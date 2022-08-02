//
// Created on 08/07/2022.
//

#include "Board.h"

float
CalculateYPos(float length, float margin, float cellHeight, float maxHeight){
    return ((maxHeight-(length*cellHeight+(length-1.0f)*margin))/2.0f);
}

void
Board::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (!isVisible()) {
        return;
    }

    for (auto const &pair : m_columnContainer) {
        Column col = pair.second;
        col.draw(target, states);
    }
}

void
Board::setup() {
    m_columnContainer.clear();
    size_t lengths[] = { 3, 5, 7, 9, 11, 13, 11, 9, 7, 5, 3 };

    float xOff = 0;
    float marginRight = 10;
    float cellMargin = 10;
    sf::Vector2f cellDims = {50,50};
    float maxHeight = 13*cellDims.y + 12*cellMargin;
    for (int sum = 2; sum <= 12; sum++) {
        const int colLength = lengths[sum-2];
        sf::Vector2f pos = {
                m_position.x + xOff,
                m_position.y + CalculateYPos((float)lengths[sum-2], cellMargin, cellDims.y, maxHeight)
        };

        sf::Vector2f dim = {
                cellDims.x,
                cellDims.y * colLength + cellMargin * colLength - cellMargin
        };
        Column col(dim, pos, colLength, sum);

        m_columnContainer.insert({ sum, col });
        xOff += 50.0f + marginRight;
    }
}

std::vector<int>
Board::getPieces(PieceOwner color, PieceType type) {
    std::vector<int> result;
    for (auto const &pair : m_columnContainer) {
        Column col = pair.second;
        if (col.getPieceIndex(color, type) != -1) {
            result.push_back(pair.first);
        }
    }
    return result;
}

std::vector<int>
Board::getFinishedCols(PieceOwner color) {
    std::vector<int> result;
    for (auto const &pair : m_columnContainer) {
        Column col = pair.second;
        if (col.isWon(color)) {
            result.push_back(pair.first);
        }
    }
    return result;
}

void
Board::moveRunner(PieceOwner color, int colIndex) {
    auto pairFound = m_columnContainer.find(colIndex);
    if (pairFound != m_columnContainer.end()) {
        Column &col = pairFound->second;
        col.moveRunner(color);
    }
}

void
Board::placeRunner(PieceOwner color, int colIndex) {
    auto pairFound = m_columnContainer.find(colIndex);
    if (pairFound != m_columnContainer.end()) {
        Column &col = pairFound->second;
        col.placeRunner(color);
    }
}

void
Board::placeCamp(PieceOwner color, int colIndex) {
    auto pairFound = m_columnContainer.find(colIndex);
    if (pairFound != m_columnContainer.end()) {
        Column &col = pairFound->second;
        col.placeCamp(color);
    }
}

void
Board::removeAllRunners(PieceOwner color) {
    for (auto &pair : m_columnContainer) {
        Column &col = pair.second;
        col.removePiece(color, PieceType::TYPE_RUNNER);
    }
}

