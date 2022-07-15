//
// Created on 15/07/2022.
//

#include "Button.h"

Button::Button(const sf::Vector2f &dim, const sf::Vector2f &pos)
    : Component(dim, pos), m_callback()
{}

void
Button::addActionListener(std::function<void(const sf::Vector2i)> callback) {
    m_callback = callback;
}

void
Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    sf::RectangleShape cellRect(m_dimension);
    cellRect.setPosition(m_position);
    target.draw(cellRect);
}

void
Button::onClick(const sf::Vector2i &cords) {
    if (isCordInBounds(cords)) {
        if (m_callback) {
            m_callback(cords);
        }
    }
}
