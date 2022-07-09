//
// Created on 08/07/2022.
//

#include "Board.h"

Board::Board()
{
    this->setup();
}

void
Board::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (auto const& pair : getData()) {
        Column col = pair.second;
        col.draw(target, states);
    }
}

void
Board::setup() {
    BoardModelType mapCopy = getData();

    size_t lengths[] = { 3, 5, 7, 9, 11, 13, 11, 9, 7, 5, 3 };

    float xOff = 0;
    float marginRight = 10;
    for (int i = 2; i <= 12; i++) {
        Column col(lengths[i-2]);
        col.setPos({ m_position.x + xOff, m_position.y + (int)((770-(lengths[i-2]*50+(lengths[i-2]-1)*10))/2)});
        col.pack();

        mapCopy.insert(BoardModelType::value_type(i, col));
        xOff += 50.0f + marginRight;
    }

    setData(mapCopy);
}
