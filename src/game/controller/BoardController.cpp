//
// Created on 06/07/2022.
//

#include "BoardController.h"

BoardController::BoardController(Model<BoardModelType> &model)
    : m_model{ model }
{
    setupBoard();
}

void
BoardController::setupBoard() {
    BoardModelType mapCopy = m_model.getData();
    size_t lengths[] = { 3, 5, 7, 9, 11, 13, 11, 9, 7, 5, 3 };
    for (int i = 2; i <= 12; i++) {
        Column col(lengths[i-2]);
        mapCopy.insert(BoardModelType::value_type(i, col));
    }
    m_model.setData(mapCopy);
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