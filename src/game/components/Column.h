//
// Created on 06/07/2022.
//

#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "Component.h"

typedef std::vector<Cell> CellContainer;

class Column : public Component {
    CellContainer m_cellContainer;
    sf::Text m_headerText;

    const int m_sum;
    const int m_length;

    sf::Vector2f m_cellDim = { 50.0F, 50.0F };
    float m_bottomMargin = 10.0F;
public:
    explicit Column(const sf::Vector2f &dim, const sf::Vector2f &pos, const int length, const int sum);

    void pack();

    int getPieceIndex(PieceColor color, PieceType type);
    void placeRunner(PieceColor color);
    void placeCamp(PieceColor color);
    int removePiece(PieceColor color, PieceType type);
    void moveRunner(PieceColor color);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void reset();
};
