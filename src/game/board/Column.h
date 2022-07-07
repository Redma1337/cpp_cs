//
// Created on 06/07/2022.
//

#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Cell.h"

class Column : sf::Drawable {
    sf::Vector2f m_position;
    const size_t m_length;

    std::vector<Cell> m_cells;
public:
    Column(const size_t length);

    void setPos(const sf::Vector2f pos);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
