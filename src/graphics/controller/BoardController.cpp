//
// Created on 06/07/2022.
//

#include "BoardController.h"

void BoardController::setBoard(const SharedBoard &board) {
    m_sharedBoard = board;
}

void
BoardController::setupBoard(const sf::Vector2f &pos) {
    m_sharedBoard->setPos(pos);
    m_sharedBoard->setup();
}

void
BoardController::drawBoard(sf::RenderTarget &target) const {
    m_sharedBoard->draw(target, sf::RenderStates::Default);
}

TurnResult
BoardController::onMove(PieceOwner color, std::array<int, 2> pair) {
    std::vector<int> runnerCells = m_sharedBoard->getPieces(color, PieceType::TYPE_RUNNER);
    //TODO: detect a win, maybe result object returned

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

        //check win
        std::vector<int> wonCols = m_sharedBoard->getFinishedCols(color);
        if (wonCols.size() >= 3) {
            return TurnResult::WON;
        }
    }

    return busts >= 2 ? TurnResult::BUSTED : TurnResult::DEFAULT;
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

