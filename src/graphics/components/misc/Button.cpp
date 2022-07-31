//
// Created on 15/07/2022.
//

#include "Button.h"
#include "../../utils/RenderWrapper.h"

Button::Button(const std::string &text, const sf::Vector2f &dim, const sf::Vector2f &pos, bool isRounded)
    : Component(dim, pos),
        m_color{ sf::Color(0x6366f1ff) },
        m_callback()
{
    m_backgroundRect = RenderWrapper::createRoundedRect(m_position, m_dimension, m_color, isRounded ? 5 : 0);
    setText(text);
}

Button::Button(const std::string &text, const sf::Vector2f &dim)
        : Button(text, dim, {0, 0}, false)
{}

Button::Button(const std::string &text)
        : Button(text, {0, 0}, {0, 0}, false)
{}

void
Button::addActionListener(ButtonCallback callback) {
    m_callback = callback;
}

void
Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (!isVisible()) {
        return;
    }

    target.draw(m_backgroundRect);
    target.draw(m_buttonText);
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
    m_backgroundRect.setFillColor(color);
}

void
Button::setText(const std::string &text) {
    sf::Vector2f center = { m_position.x + (m_dimension.x / 2.0f), m_position.y + (m_dimension.y / 2.0f)};
    m_buttonText = RenderWrapper::createCenteredString(text, center, 20, sf::Color::White);
}