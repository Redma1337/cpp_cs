//
// Created on 15/07/2022.
//

#include "Button.h"

Button::Button(const std::string &text, const sf::Vector2f &dim, const sf::Vector2f &pos)
    : Component(dim, pos),
        m_color{ sf::Color::Red },
        m_text{ text },
        m_callback()
{}

Button::Button(const std::string &text, const sf::Vector2f &dim)
        : Button(text, dim, {0, 0})
{}

Button::Button(const std::string &text)
        : Button(text, {0, 0}, {0, 0})
{}

void
Button::addActionListener(std::function<void(const sf::Vector2i)> callback) {
    m_callback = callback;
}

void
Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (!isVisible()) {
        return;
    }

    sf::RectangleShape cellRect(m_dimension);
    cellRect.setPosition(m_position);
    cellRect.setFillColor(m_color);
    target.draw(cellRect);

    sf::Vector2f centerPos = { m_position.x + m_dimension.x / 2, m_position.y + m_dimension.y / 2 };
    sf::Text text = RenderWrapper::createCenteredString(m_text, centerPos, 20, sf::Color::White);
    target.draw(text);
}

void
Button::click() {
    sf::Vector2i sF(m_position);
    this->onClick(sF);
}

void
Button::onClick(const sf::Vector2i &cords) {
    if (isLocked() || !isCordInBounds(cords) || !isVisible()) {
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

void
Button::setText(const std::string &text) {
    m_text = text;
}
