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
BoardController::onMove(PieceColor color, std::array<int, 2> pair) {
    int firstSum = pair[0], secondSum = pair[1];

    std::vector<int> runnerCells = m_sharedBoard->getPieces(color, PieceType::TYPE_RUNNER);
    std::vector<int> campCells = m_sharedBoard->getPieces(color, PieceType::TYPE_RUNNER);

    for (int sum : pair) {
        auto sumFound = std::find(runnerCells.begin(), runnerCells.end(), sum);
        if (sumFound != runnerCells.end()) {
            m_sharedBoard->moveRunner(color, sum);
        } else {
            m_sharedBoard->placeRunner(color, sum);
        }
    }
}

