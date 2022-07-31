//
// Created on 05/07/2022.
//

#include "PlayerController.h"
#include "../../graphics/ColorTheme.h"

PlayerController::PlayerController()
    :   m_currentPlayer{ 0 },
        m_actionQueue{},
        m_players{ },
        m_statusText{ "Waiting..." }
{}

void
PlayerController::update(PairSelector& selector) {
    if (m_actionQueue.empty()) {
        std::vector<PlayerAction> newActions = getCurrentPlayer()->generateActions();
        std::for_each(newActions.begin(), newActions.end(), [this](PlayerAction e) { m_actionQueue.push(e); });
        return;
    }

    bool shouldQueueWipe = false;
    PlayerAction currentAction = m_actionQueue.front();
    switch (currentAction) {
        case (PlayerAction::WAIT): {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            m_statusText = "Thinking...";
            break;
        }
        case (PlayerAction::ROLL_DICE): {
            m_statusText = "Rolling dice";
            selector.reRoll();
            selector.setVisible(true);
            break;
        }
        case (PlayerAction::MAKE_SELECTION): {
            //human players will just return the component, bots will imitate actors use of the component
            std::array<int, 2> turnPair = getCurrentPlayer()->doSelection(selector);
            m_statusText = "Choosing " + std::to_string(turnPair[0]) + " and " + std::to_string(turnPair[1]);

            //pass this data to the board controller, since its nothing that has to do with actors controlling
            TurnResult turnResult = m_onMoveCallback(m_currentPlayer, turnPair);

            switch (turnResult) {
                case (TurnResult::WON): {
                    m_onGameFinishCallback(getCurrentPlayer()->getName());
                    selector.setVisible(false);
                    break;
                }
                case (TurnResult::BUSTED): {
                    m_statusText = "Busted";
                    m_onFinishCallback(m_currentPlayer, true);
                    switchPlayer();
                    shouldQueueWipe = true;
                    selector.setVisible(false);
                    break;
                }
            }

            break;
        }
        case (PlayerAction::SWITCH_PLAYER): {
            m_statusText = "Scoring";
            m_onFinishCallback(m_currentPlayer, false);

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

    if (shouldQueueWipe) {
        clearActions();
    }
}

void PlayerController::reset() {
    m_players[0] = nullptr;
    m_players[1] = nullptr;
}

void
PlayerController::switchPlayer() {
    m_currentPlayer = (m_currentPlayer == PieceOwner::PLAYER_ONE ? PieceOwner::PLAYER_TWO : PieceOwner::PLAYER_ONE);
}



const std::shared_ptr<Player>
PlayerController::getCurrentPlayer() const {
    return m_players[(int) m_currentPlayer];
}

void
PlayerController::setPlayer(PieceOwner playerPos, const SharedPlayer &player) {
    m_players[(int) playerPos] = player;
    m_players[(int) playerPos]->setColor(playerPos == PieceOwner::PLAYER_ONE ? ColorTheme::PLAYER_ONE_COLOR : ColorTheme::PLAYER_TWO_COLOR);
}

void
PlayerController::enqueueAction(PlayerAction action) {
    m_actionQueue.push(action);
}

bool
PlayerController::isHumanMoving() const {
    return getCurrentPlayer()->isHuman();
}

std::string
PlayerController::getCurrentStatus() const {
    return getCurrentPlayer()->getName() + ": " + m_statusText;
}

void PlayerController::clearActions() {
    m_actionQueue = ActionQueue();
}




