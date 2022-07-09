//
// Created on 08/07/2022.
//

#pragma once

#include <SFML/Graphics/Drawable.hpp>

class Component : sf::Drawable {
protected:
    sf::Vector2f m_dimension;
    sf::Vector2f m_position = {0, 0};
public:
    explicit Component(const sf::Vector2f &dim)
        : m_dimension{ dim }
    {}

    explicit Component(const sf::Vector2f &dim, const sf::Vector2f &pos)
        : m_dimension{ dim }, m_position{ pos }
    {}

    Component() = default;

    virtual ~Component() = default;

    virtual void setPos(const sf::Vector2f &pos) {
        m_position = pos;
    }

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};
