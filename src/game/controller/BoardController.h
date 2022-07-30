//
// Created on 06/07/2022.
//

#pragma once
#include "../components/Column.h"
#include "../components/Board.h"
#include "../player/ETurnResult.h"
#include <memory>

class BoardController {
    typedef std::shared_ptr<Board> SharedBoard;

    SharedBoard m_sharedBoard;
public:
    void setupBoard(sf::Vector2f pos);
    void drawBoard(sf::RenderTarget& target) const;
    void setBoard(const std::shared_ptr<Board> &board);
    TurnResult onMove(PieceOwner color, std::array<int, 2> pair);
    bool onFinish(PieceOwner color, bool didBust);
};

