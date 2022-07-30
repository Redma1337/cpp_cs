//
// Created on 05/07/2022.
//

#include "PlayerController.h"


PlayerController::PlayerController()
    :   m_currentPlayer{ 0 },
        m_actionQueue{},
        m_players{ std::make_shared<HumanPlayer>("Human Player") },
        m_statusText{ "Waiting..." }
{
    m_players[0]->setColor(PieceOwner::PLAYER_TWO);
}

void
PlayerController::update(PairSelector& selector) {
    if (m_actionQueue.empty()) {
        std::vector<EPlayerAction> newActions = getCurrentPlayer()->generateActions();
        std::for_each(newActions.begin(), newActions.end(), [this](EPlayerAction e) { m_actionQueue.push(e); });
        return;
    }

    //TODO: make Actions a seperate thing, having an owner / runnable
    bool shouldQueueWipe = false;
    EPlayerAction currentAction = m_actionQueue.front();
    switch (currentAction) {
        case (EPlayerAction::WAIT): {
            m_statusText = "Thinking...";
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            break;
        }
        case (EPlayerAction::ROLL_DICE): {
            m_statusText = "Rolling dice";
            selector.reRoll();
            selector.setVisible(true);
            break;
        }
        case (EPlayerAction::MAKE_SELECTION): {
            //human players will just return the component, bots will imitate player use of the component
            std::array<int, 2> turnPair = getCurrentPlayer()->doSelection(selector);
            m_statusText = "Choosing " + std::to_string(turnPair[0]) + " and " + std::to_string(turnPair[1]);

            //pass this data to the board controller, since its nothing that has to do with player controlling
            TurnResult turnResult = m_onMoveCallback(getCurrentPlayer()->getColor(), turnPair);

            if (turnResult.hasWon) {
                m_onGameFinishCallback(getCurrentPlayer()->getColor());
                break;
            }

            if (turnResult.hasBusted) {
                m_statusText = "Busted";
                m_onFinishCallback(getCurrentPlayer()->getColor(), true);
                switchPlayer();
                shouldQueueWipe = true;
            }
            break;
        }
        case (EPlayerAction::SWITCH_PLAYER): {
            m_onFinishCallback(getCurrentPlayer()->getColor(), false);

            switchPlayer();
            shouldQueueWipe = true;

            selector.setVisible(false);
            selector.reset();
            break;
        }
        default:
            m_statusText = "Thinking...";
    }
    m_actionQueue.pop();

    /**
     *     we cant delete in the switch statement, but we need to make sure the queue is emptied if the player switches
     *     since computers will bust although there is different behaviour queued
     */

    if (shouldQueueWipe) {
        m_actionQueue = std::queue<EPlayerAction>();
    }
}

const std::shared_ptr<Player>&
PlayerController::getCurrentPlayer() const {
    return m_players[m_currentPlayer];
}

void
PlayerController::setOpponent(const std::shared_ptr<Player> &player) {
    m_players[1] = player;
    m_players[1]->setColor(PieceOwner::PLAYER_ONE);
}

void PlayerController::setOnMoveListener(const OnMoveCallback& callback) {
    m_onMoveCallback = callback;
}

void PlayerController::setOnTurnFinishListener(const OnFinishCallback& callback) {
    m_onFinishCallback = callback;
}

void PlayerController::setOnTurnFinishListener(const OnFinishCallback& callback) {
    m_onFinishCallback = callback;
}

void
PlayerController::switchPlayer() {
    m_currentPlayer = (m_currentPlayer == 0 ? 1 : 0);
}

void
PlayerController::enqueueAction(EPlayerAction action) {
    m_actionQueue.push(action);
}

bool
PlayerController::isHumanMoving() const {
    return getCurrentPlayer()->isHuman();
}

std::string
PlayerController::getCurrentStatus() {
    return m_statusText;
}
