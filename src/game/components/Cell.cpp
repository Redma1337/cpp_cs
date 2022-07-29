//
// Created on 06/07/2022.
//

#include "Cell.h"
#include "../wrapper/RenderWrapper.h"

Cell::Cell(const sf::Vector2f &dim, const sf::Vector2f &pos)
    : Component{ dim, pos }, m_color{}, m_hasRunner{ false }
{}

void
Cell::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (!isVisible()) {
        return;
    }

    sf::RectangleShape cellRect(m_dimension);
    cellRect.setPosition(m_position);
    cellRect.setFillColor(sf::Color(20, 20, 20, 100));
    target.draw(cellRect);

    if(m_camps.size() == 1){
        auto it = m_camps.begin();
        cellRect.setFillColor(it->first==PieceColor::COLOR_GREEN ? sf::Color::Green : sf::Color::Red );
        target.draw(cellRect);
    }
    else if(m_camps.size() == 2) {
        sf::ConvexShape lowerTriangle = RenderWrapper::createTriangle(m_position, { 0, 0 }, { 0, m_dimension.y }, m_dimension, sf::Color::Red);
        target.draw(lowerTriangle);

        sf::ConvexShape upperTriangle = RenderWrapper::createTriangle(m_position, { 0, 0 }, { 0, m_dimension.y }, m_dimension, sf::Color::Green);
        upperTriangle.setOrigin(m_dimension);
        upperTriangle.setRotation(180);
        target.draw(upperTriangle);
    }

    if(hasRunner()){
        sf::CircleShape runnerCircle(5,30);
        runnerCircle.setOutlineThickness(2);
        runnerCircle.setOutlineColor(sf::Color::Black);
        runnerCircle.setPointCount(50);
        runnerCircle.setPosition(m_position.x + m_dimension.x/2 - runnerCircle.getRadius(), m_position.y + m_dimension.y/2 - runnerCircle.getRadius());
        runnerCircle.setFillColor(sf::Color::Black);
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
Cell::hasCamp(PieceColor color) {
    auto pairFound = m_camps.find(color);
    return pairFound != m_camps.end();
}

void
Cell::removeCamp(PieceColor color) {
    m_camps[color] = false;
}

void
Cell::addCamp(PieceColor color) {
    m_camps[color] = true;
}

void
Cell::reset() {
    m_camps = {};
    m_hasRunner = false;
}

bool
Cell::hasPiece(PieceColor color, PieceType type) {
    return (type == PieceType::TYPE_RUNNER && hasRunner()) || (type == PieceType::TYPE_CAMP && hasCamp(color));
}
