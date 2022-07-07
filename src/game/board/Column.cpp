//
// Created on 06/07/2022.
//

#include "Column.h"

Column::Column(const size_t length)
    : m_length{ length }, m_position{ 0, 0 }
{
    int yOff = 0;
    const sf::Vector2f cellDim = { 50, 50 };
    for (int i = 0; i < length; i++) {
        Cell cell(cellDim);
        cell.setPos({ m_position.x, m_position.y + yOff });

        m_cells.push_back(cell);
        yOff += cellDim.y;
    }
}

void
Column::setPos(const sf::Vector2f pos) {
    m_position = pos;
}

void
Column::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(Cell c : m_cells) {
        c.draw(target, states);
    }
}