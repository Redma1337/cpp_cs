//
// Created on 05/07/2022.
//

#include "PlayerController.h"

PlayerController::PlayerController(Player &one, Player &two)
    : m_playerOne{ one }, m_playerTwo{ two }, m_currentPlayer{ &one }
{
    one.setColor(PieceColor::COLOR_RED);
    two.setColor(PieceColor::COLOR_GREEN);
}

bool
PlayerController::doTurn() {

}

void
PlayerController::switchPlayer() {
    m_currentPlayer = (m_currentPlayer == &m_playerOne) ? &m_playerTwo : &m_playerOne;
}
