//
// Created on 05/07/2022.
//

#include "PlayerController.h"


PlayerController::PlayerController(Player &one, Player &two)
    :   m_playerOne{ one },
        m_playerTwo{ two },
        m_currentPlayer{ &one },
        m_actionQueue{}
{
    one.setColor(PieceColor::COLOR_RED);
    two.setColor(PieceColor::COLOR_GREEN);
}

PlayerController::~PlayerController() {
    delete m_currentPlayer;
}

void
PlayerController::update(PairSelector& selector) {
    if (m_actionQueue.empty()) {
        std::vector<EPlayerAction> newActions = m_currentPlayer->generateActions();
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
            std::array<int, 2> turnPair = m_currentPlayer->doSelection(selector);
            break;
        }
        case (EPlayerAction::SWITCH_PLAYER): {
            switchPlayer();
            selector.setVisible(false);
            break;
        }
    }
    m_actionQueue.pop();
}

void
PlayerController::switchPlayer() {
    m_currentPlayer = (m_currentPlayer == &m_playerOne) ? &m_playerTwo : &m_playerOne;
}

void
PlayerController::enqueueAction(EPlayerAction action) {
    m_actionQueue.push(action);
}

bool
PlayerController::isHumanMoving() const {
    return m_currentPlayer->isHuman();
}
