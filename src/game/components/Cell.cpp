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
        sf::VertexArray campOne(sf::Triangles, 4);
        campOne[0].position = sf::Vector2f(m_position);
        campOne[1].position = sf::Vector2f(m_position.x + m_dimension.x, m_position.y);
        campOne[2].position = sf::Vector2f(m_position.x + m_dimension.x, m_position.y + m_dimension.y);
        campOne[0].color = sf::Color::Red;
        campOne[1].color = sf::Color::Red;
        campOne[2].color = sf::Color::Red;
        target.draw(campOne);

        sf::VertexArray campTwo(sf::Triangles, 3);
        campTwo[0].position = sf::Vector2f(m_position);
        campTwo[1].position = sf::Vector2f(m_position.x, m_position.y + m_dimension.y);
        campTwo[2].position = sf::Vector2f(m_position.x + m_dimension.x, m_position.y + m_dimension.y);
        campTwo[0].color = sf::Color::Green;
        campTwo[1].color = sf::Color::Green;
        campTwo[2].color = sf::Color::Green;
        target.draw(campTwo);
    }

    if(hasRunner()){
        sf::CircleShape runnerCircle(5,30);
        runnerCircle.setOutlineThickness(2);
        runnerCircle.setOutlineColor(sf::Color::Black);
        runnerCircle.setPosition(m_position.x + m_dimension.x/2 - runnerCircle.getRadius(), m_position.y + m_dimension.y/2 - runnerCircle.getRadius());
        runnerCircle.setFillColor(sf::Color::Green);
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
