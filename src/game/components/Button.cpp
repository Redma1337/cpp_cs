//
// Created on 15/07/2022.
//

#include "Button.h"

Button::Button(const sf::Vector2f &dim, const sf::Vector2f &pos)
    : Component(dim, pos),
        m_color{ sf::Color::Red },
        m_callback()
{}

Button::Button(const sf::Vector2f &dim)
        : Button(dim, {0, 0})
{}

Button::Button()
        : Button({0, 0}, {0, 0})
{}

void
Button::addActionListener(std::function<void(const sf::Vector2i)> callback) {
    m_callback = callback;
}

void
Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    sf::RectangleShape cellRect(m_dimension);
    cellRect.setPosition(m_position);
    cellRect.setFillColor(m_color);
    target.draw(cellRect);
}

void
Button::click() {
    sf::Vector2i sF(m_position);
    this->onClick(sF);
}

void
Button::onClick(const sf::Vector2i &cords) {
    if (isLocked() || !isCordInBounds(cords)) {
        return;
    }

    if (m_callback) {
        m_callback(cords);
    }
}

void
Button::setColor(const sf::Color &color) {
    m_color = color;
}
