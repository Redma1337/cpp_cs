//
// Created on 06/07/2022.
//

#include "Cell.h"

Cell::Cell(const sf::Vector2f &dim)
    : Component{ dim }
{
    setPieceType(PieceColor::COLOR_RED, PieceType::TYPE_CAMP);
    setPieceType(PieceColor::COLOR_GREEN,PieceType::TYPE_CAMP);
    setPieceType(PieceColor::COLOR_RED,PieceType::TYPE_RUNNER);
}

void
Cell::setPieceType(PieceColor color, PieceType newType) {
    if(newType == PieceType::TYPE_RUNNER){
        m_runner[color] = newType;
    }
    else if(newType == PieceType::TYPE_CAMP) {
        m_camps[color] = newType;
    }
    else{
        m_runner.erase(color);
    }
}

PieceType
Cell::getPieceType(PieceColor color) {
    return m_camps[color];
}

void
Cell::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    sf::RectangleShape cellRect(m_dimension);
    cellRect.setPosition(m_position);
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

    if(!m_runner.empty()){
        auto it = m_runner.begin();
        sf::CircleShape runnerCircle(5,30);
        runnerCircle.setOutlineThickness(2);
        runnerCircle.setOutlineColor(sf::Color::Black);
        runnerCircle.setPosition(m_position.x + m_dimension.x/2 - runnerCircle.getRadius(), m_position.y + m_dimension.y/2 - runnerCircle.getRadius());
        runnerCircle.setFillColor(it->first==PieceColor::COLOR_GREEN ? sf::Color::Green : sf::Color::Red );
        target.draw(runnerCircle);
    }
}