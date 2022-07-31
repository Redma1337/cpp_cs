//
// Created on 06/07/2022.
//

#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "../Component.h"
#include "../../utils/RoundedRectangleShape.h"


class Column : public Component {
    typedef std::vector<Cell> CellContainer;
    CellContainer m_cellContainer;

    sf::Text m_headerText;
    sf::RoundedRectangleShape m_lockedBorder;

    const int m_sum;
    const int m_length;

    sf::Vector2f m_cellDim = { 50.0F, 50.0F };
    float m_bottomMargin = 10.0F;
public:
    explicit Column(const sf::Vector2f &dim, const sf::Vector2f &pos, const int length, const int sum);

    void pack();

    int getPieceIndex(PieceOwner color, PieceType type);
    void placeRunner(PieceOwner color);
    void placeCamp(PieceOwner color);
    int removePiece(PieceOwner color, PieceType type);
    void moveRunner(PieceOwner color);

    void setLocked(bool state) override;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
