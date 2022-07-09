//
// Created on 06/07/2022.
//

#include "Column.h"

Column::Column(const size_t length)
    : m_length{ length },
        Component{{50, (float) length * 50}}
{}

void
Column::pack() {
    float yOff = 0;
    float bottomMargin = 10;
    const sf::Vector2f cellDim = { 50, 50 };

    for (int i = 0; i < m_length; i++) {
        Cell cell(cellDim);
        cell.setPos({ m_position.x, m_position.y + yOff });

        m_cells.push_back(cell);
        yOff += cellDim.y + bottomMargin;
    }
}

void
Column::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(Cell const &c : m_cells) {
        c.draw(target, states);
    }
}