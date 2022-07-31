//
// Created on 06/07/2022.
//

#pragma once
#include "EPieceType.h"
#include "../components/board/Board.h"
#include <memory>

class BoardController {
    typedef std::shared_ptr<Board> SharedBoard;

    SharedBoard m_sharedBoard;
public:
    void setupBoard(const sf::Vector2f &pos);
    void setBoard(const SharedBoard &board);

    void drawBoard(sf::RenderTarget& target) const;
    TurnResult onMove(PieceOwner color, std::array<int, 2> pair);
    bool onFinish(PieceOwner color, bool didBust);
};

