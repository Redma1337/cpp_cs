//
// Created on 06/07/2022.
//

#include "BoardController.h"

void BoardController::setBoard(const std::shared_ptr<Board> &board) {
    m_sharedBoard = board;
}

void
BoardController::setupBoard() {
    m_sharedBoard->setup();
}

void
BoardController::executeMove(int index, BoardOperation operation) {
    switch(operation) {
        case(BoardOperation::OP_MOVE): {
            break;
        }
        case(BoardOperation::OP_PLACE): {
            break;
        }
        case(BoardOperation::OP_REMOVE): {
            break;
        }
        case(BoardOperation::OP_REPLACE): {
            break;
        }
        default:
            //lets hope this never hits
            break;
    }
}

