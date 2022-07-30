//
// Created on 06/07/2022.
//

#include <iostream>
#include "BoardController.h"

void BoardController::setBoard(const std::shared_ptr<Board> &board) {
    m_sharedBoard = board;
}

void
BoardController::setupBoard(sf::Vector2f pos) {
    m_sharedBoard->setPos(pos);
    m_sharedBoard->setup();
}

void
BoardController::drawBoard(sf::RenderTarget &target) const {
    m_sharedBoard->draw(target, sf::RenderStates::Default);
}

bool
BoardController::onMove(PieceOwner color, std::array<int, 2> pair) {
    std::vector<int> runnerCells = m_sharedBoard->getPieces(color, PieceType::TYPE_RUNNER);
    //TODO: detect a win, maybe result object returned
    //TODO: add status label

    int busts = 0;

    for (int sum : pair) {
        auto sumFound = std::find(runnerCells.begin(), runnerCells.end(), sum);
        //the sum was found in existing runners
        if (sumFound != runnerCells.end()) {
            m_sharedBoard->moveRunner(color, sum);
        } else {
            //sum was none of the 3 runners
            if (runnerCells.size() >= 3) {
                busts++;
                continue;
            }

            m_sharedBoard->placeRunner(color, sum);
            runnerCells.push_back(sum);
        }
    }

    return busts >= 2;
}

bool
BoardController::onFinish(PieceOwner color, bool didBust) {
    if (didBust) {
        m_sharedBoard->removeAllRunners(color);
    } else {
        std::vector<int> runnerCells = m_sharedBoard->getPieces(color, PieceType::TYPE_RUNNER);
        for (int index : runnerCells) {
            m_sharedBoard->placeCamp(color, index);
        }
    }
}

