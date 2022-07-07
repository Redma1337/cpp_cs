//
// Created on 06/07/2022.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "../player/EPieceColor.h"
#include "../player/EPieceType.h"

class Cell : sf::Drawable {
    const sf::Vector2f m_dimension;
    sf::Vector2f m_position;

    std::map<PieceColor, PieceType> m_occupiers;
public:
    Cell(const sf::Vector2f &dim);

    void setPos(const sf::Vector2f pos);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void setPieceType(PieceColor color, PieceType type);
    const PieceType getPieceType(PieceColor color);
};
