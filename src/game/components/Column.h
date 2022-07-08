//
// Created on 06/07/2022.
//

#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "Component.h"

class Column : public Component {
    const size_t m_length;

    std::vector<Cell> m_cells;
public:
    Column(const size_t length);

    void pack();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
