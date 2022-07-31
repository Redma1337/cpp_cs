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

void
Player::doRoll(ActionVec &actions) {
    actions.push_back(PlayerAction::WAIT);
    actions.push_back(PlayerAction::ROLL_DICE);
    actions.push_back(PlayerAction::WAIT);
    actions.push_back(PlayerAction::WAIT);
    actions.push_back(PlayerAction::MAKE_SELECTION);
    actions.push_back(PlayerAction::WAIT);
}

void
Player::switchPlayer(ActionVec &actions) {
    actions.push_back(PlayerAction::WAIT);
    actions.push_back(PlayerAction::SWITCH_PLAYER);
    actions.push_back(PlayerAction::WAIT);
}