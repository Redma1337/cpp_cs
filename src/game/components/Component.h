//
// Created on 08/07/2022.
//

#pragma once

#include <SFML/Graphics/Drawable.hpp>

class Component : sf::Drawable {
protected:
    sf::Vector2f m_dimension;
    sf::Vector2f m_position = {0, 0};
    bool m_locked;
public:
    explicit Component(const sf::Vector2f &dim)
        : m_dimension{ dim }, m_locked{ false }
    {}

    explicit Component(const sf::Vector2f &dim, const sf::Vector2f &pos)
        : m_dimension{ dim }, m_position{ pos }, m_locked{ false }
    {}

    Component()
        : m_dimension{ 0, 0 }, m_position{ 0, 0 }, m_locked{ false }
    {};

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

    void setLocked(bool state) {
        m_locked = state;
    }

    bool isLocked() const {
        return m_locked;
    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;
};
