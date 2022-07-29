//
// Created on 05/07/2022.
//

#include "PlayerController.h"


PlayerController::PlayerController()
    :   m_currentPlayer{ 0 },
        m_actionQueue{},
        m_players{ std::make_shared<HumanPlayer>("Human Player") }
{}

void
PlayerController::update(PairSelector& selector) {
    if (m_actionQueue.empty()) {
        std::vector<EPlayerAction> newActions = getCurrentPlayer()->generateActions();
        std::for_each(newActions.begin(), newActions.end(), [this](EPlayerAction e) { m_actionQueue.push(e); });
        return;
    }

    EPlayerAction currentAction = m_actionQueue.front();
    switch (currentAction) {
        case (EPlayerAction::WAIT): {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            break;
        }
        case (EPlayerAction::ROLL_DICE): {
            selector.reRoll();
            selector.setVisible(true);
            break;
        }
        case (EPlayerAction::MAKE_SELECTION): {
            std::array<int, 2> turnPair = getCurrentPlayer()->doSelection(selector);
            m_actionCallback(getCurrentPlayer()->getColor(), turnPair);
            selector.setVisible(false);
            break;
        }
        case (EPlayerAction::SWITCH_PLAYER): {
            switchPlayer();
            selector.setVisible(false);
            selector.reset();
            break;
        }
    }
    m_actionQueue.pop();
}

const std::shared_ptr<Player>&
PlayerController::getCurrentPlayer() const {
    return m_players[m_currentPlayer];
}

void
PlayerController::setOpponent(const std::shared_ptr<Player> &player) {
    m_players[1] = player;
}

void PlayerController::setActionListener(const ActionCallback& callback) {
    m_actionCallback = callback;
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
