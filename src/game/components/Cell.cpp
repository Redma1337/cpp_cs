//
// Created on 06/07/2022.
//

#include "Cell.h"

Cell::Cell(const sf::Vector2f &dim)
    : Component{ dim }
{}

void
Cell::setPieceType(PieceColor color, PieceType newType) {
    m_occupiers[color] = newType;
}

PieceType
Cell::getPieceType(PieceColor color) {
    return m_occupiers[color];
}

void
Cell::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    sf::RectangleShape cellRect(m_dimension);
    cellRect.setPosition(m_position);
    target.draw(cellRect);

    //TODO: draw the occupiers
}