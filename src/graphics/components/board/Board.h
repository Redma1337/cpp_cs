//
// Created on 08/07/2022.
//

#pragma once

#include "../Component.h"
#include "Column.h"

typedef std::map<int, Column> ColumnContainer;

class Board : public Component {
    ColumnContainer m_columnContainer;
public:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void setup();

    std::vector<int> getPieces(PieceOwner color, PieceType type);
    std::vector<int> getFinishedCols(PieceOwner color);
    void moveRunner(PieceOwner color, int colIndex);
    void placeRunner(PieceOwner color, int colIndex);
    void placeCamp(PieceOwner color, int colIndex);
    void removeAllRunners(PieceOwner color);
    std::map<int, Column> getColumnContainer();
};
