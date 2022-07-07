//
// Created on 06/07/2022.
//

#include "Cell.h"

Cell::Cell(const sf::Vector2f &dim)
    : m_dimension{ dim }, m_position{ 0, 0 }
{}

void
Cell::setPos(const sf::Vector2f pos) {
    m_position = pos;
}

void
Cell::setPieceType(PieceColor color, PieceType newType) {
    m_occupiers[color] = newType;
}

const PieceType
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