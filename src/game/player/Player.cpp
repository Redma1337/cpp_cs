//
// Created on 05/07/2022.
//

#include "Player.h"

Player::Player(std::string name, bool human)
    :   m_name{ std::move(name) },
        m_isHuman{ human }
{}

std::string
Player::getName() const {
    return m_name;
}

sf::Color
Player::getColor() const {
    return m_color;
}

void
Player::setColor(sf::Color color) {
    m_color = color;
}

bool
Player::isHuman() const {
    return m_isHuman;
}