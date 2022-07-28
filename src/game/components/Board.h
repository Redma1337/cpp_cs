//
// Created on 08/07/2022.
//

#pragma once

#include "Component.h"
#include "Column.h"

typedef std::map<int, Column> ColumnContainer;

class Board : public Component {
    ColumnContainer m_columnContainer;
public:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void setup();

    std::vector<int> getPieces(PieceColor color, PieceType type);
    void moveRunner(PieceColor color, int colIndex);
    void placeRunner(PieceColor color, int colIndex);
    void placeCamp(PieceColor color, int colIndex);
};
