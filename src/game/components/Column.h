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
    float m_bottomMargin = 10;
    sf::Vector2f m_cellDim = { 50, 50 };
    std::vector<Cell> m_cells;
public:
    explicit Column(size_t length);

    void pack();

    void setCellMargin(float margin);
    void setCellSize(sf::Vector2f cellDim);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
