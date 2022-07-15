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

    ~Component() override = default;

    virtual void setPos(const sf::Vector2f &pos) {
        m_position = pos;
    }

    bool isCordInBounds(const sf::Vector2i &pos) {
        return (
            pos.x >= m_position.x
            && pos.y >= m_position.y
            && pos.x <= (m_position.x + m_dimension.x)
            && pos.y <= (m_position.y + m_dimension.y)
        );
    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;
};
