//
// Created on 08/07/2022.
//

#include "Board.h"

Board::Board()
{
    this->setup();
}

int
CalculateYPos(int length, int margin, int cellHeight, int maxHeight){
    return (int)((maxHeight-(length*cellHeight+(length-1)*margin))/2);
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
    float cellMargin = 10;
    sf::Vector2f cellDims = {50,50};
    int maxHeight = 13*cellDims.y + 12*cellMargin;
    for (int i = 2; i <= 12; i++) {
        Column col(lengths[i-2]);
        col.setCellMargin(cellMargin);
        col.setCellSize(cellDims);
        col.setPos({ m_position.x + xOff, m_position.y + CalculateYPos((int)lengths[i-2], (int)cellMargin, (int)cellDims.y, maxHeight)});
        col.pack();

        mapCopy.insert(BoardModelType::value_type(i, col));
        xOff += 50.0f + marginRight;
    }

    setData(mapCopy);
}