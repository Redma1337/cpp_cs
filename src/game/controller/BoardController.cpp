//
// Created on 06/07/2022.
//

#include <iostream>
#include "BoardController.h"

void BoardController::setBoard(const std::shared_ptr<Board> &board) {
    m_sharedBoard = board;
}

void
BoardController::setupBoard() {
    m_sharedBoard->setup();
}

void
BoardController::drawBoard(sf::RenderTarget &target) const {
    m_sharedBoard->draw(target, sf::RenderStates::Default);
}

void
BoardController::onMove(const std::array<int, 2> &pair) {
    std::cout << "Player move received" << std::endl;
}

