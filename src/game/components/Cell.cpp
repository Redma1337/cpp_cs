//
// Created on 06/07/2022.
//

#include "Cell.h"
#include "../wrapper/RenderWrapper.h"

Cell::Cell(const sf::Vector2f &dim, const sf::Vector2f &pos)
    : Component{ dim, pos },
        m_color{},
        m_hasRunner{ false },
        m_camps{
            { PieceColor::COLOR_GREEN, false },
            { PieceColor::COLOR_RED, false }
        }
{}

void
Cell::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (!isVisible()) {
        return;
    }

    sf::RectangleShape cellRect(m_dimension);
    cellRect.setPosition(m_position);
    cellRect.setFillColor(sf::Color(0x182134ff));
    target.draw(cellRect);

    if (hasCamp(PieceColor::COLOR_GREEN) && hasCamp(PieceColor::COLOR_RED)) {
        sf::ConvexShape lowerTriangle = RenderWrapper::createTriangle(m_position, { 0, 0 }, { 0, m_dimension.y }, m_dimension, sf::Color(0x6366f1ff));
        target.draw(lowerTriangle);

        sf::ConvexShape upperTriangle = RenderWrapper::createTriangle(m_position, { 0, 0 }, { 0, m_dimension.y }, m_dimension, sf::Color(0x0ea5e9ff));
        upperTriangle.setOrigin(m_dimension);
        upperTriangle.setRotation(180);
        target.draw(upperTriangle);
    } else if (hasCamp(PieceColor::COLOR_GREEN) || hasCamp(PieceColor::COLOR_RED)) {
        sf::RectangleShape camp(m_dimension);
        camp.setPosition(m_position);
        camp.setFillColor(hasCamp(PieceColor::COLOR_GREEN) ? sf::Color(0x6366f1ff) : sf::Color(0x0ea5e9ff));
        target.draw(camp);
    }

    if(hasRunner()){
        sf::CircleShape runnerCircle(5,30);
        runnerCircle.setPointCount(50);
        runnerCircle.setPosition(m_position.x + m_dimension.x/2 - runnerCircle.getRadius(), m_position.y + m_dimension.y/2 - runnerCircle.getRadius());
        runnerCircle.setFillColor(sf::Color::White);
        target.draw(runnerCircle);
    }
}

void
Cell::setRunner(bool state) {
    m_hasRunner = state;
}

bool
Cell::hasRunner() const {
    return m_hasRunner;
}

bool
Cell::hasCamp(PieceColor color) const {
    auto pairFound = m_camps.find(color);
    return pairFound->second;
}

void
Cell::removeCamp(PieceColor color) {
    m_camps[color] = false;
}

void
Cell::addCamp(PieceColor color) {
    m_camps[color] = true;
}

bool
Cell::hasPiece(PieceColor color, PieceType type) {
    return (type == PieceType::TYPE_RUNNER && hasRunner()) || (type == PieceType::TYPE_CAMP && hasCamp(color));
}
