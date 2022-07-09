//
// Created on 06/07/2022.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "../player/EPieceColor.h"
#include "../player/EPieceType.h"
#include "Component.h"

class Cell : public Component {
    std::map<PieceColor, PieceType> m_occupiers;
public:
    Cell(const sf::Vector2f &dim);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void setPieceType(PieceColor color, PieceType type);
    PieceType getPieceType(PieceColor color);
};
