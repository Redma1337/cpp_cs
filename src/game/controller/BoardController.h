//
// Created on 06/07/2022.
//

#pragma once
#include <map>
#include <memory>
#include "../components/Column.h"
#include "../components/Board.h"

class BoardController {
    typedef std::shared_ptr<Board> SharedBoard;

    SharedBoard m_sharedBoard;
public:
    void setupBoard();
    void drawBoard(sf::RenderTarget& target) const;
    void setBoard(const std::shared_ptr<Board> &board);
    bool onMove(PieceColor color, std::array<int, 2> pair);
    bool onFinish(PieceColor color, bool didBust);
};

