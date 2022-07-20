//
// Created on 06/07/2022.
//

#pragma once
#include <map>
#include <memory>
#include "../components/Column.h"
#include "../model/EBoardOperation.h"
#include "../model/Model.h"
#include "../components/Board.h"

class BoardController {
    typedef std::shared_ptr<Board> SharedBoard;

    SharedBoard m_sharedBoard;
public:
    void setupBoard();
    void setBoard(const std::shared_ptr<Board> &board);
    void executeMove(int index, BoardOperation operation);
};

