//
// Created on 06/07/2022.
//

#include "Column.h"
#include "../wrapper/RenderWrapper.h"

Column::Column(const sf::Vector2f &dim, const sf::Vector2f &pos, const int length, const int sum)
    :   Component(dim, pos),
        m_length{ length },
        m_sum{ sum },
        m_cellContainer{}
{
    pack();

    int xAdjust = sum > 9 ? 11 : 6;
    m_headerText = RenderWrapper::createCenteredString(
            std::to_string(sum),
            { m_position.x + (m_cellDim.x / 2.0f) - xAdjust, m_position.y + (m_cellDim.y / 2.0f) + 7},
            20,
            sf::Color::White
    );
}

void
Column::pack() {
    float yOff = 0.0F;

    for (int i = 0; i < m_length; i++) {
        Cell cell(m_cellDim, { m_position.x, m_position.y + yOff });

        m_cellContainer.push_back(cell);
        yOff += m_cellDim.y + m_bottomMargin;
    }
}

void
Column::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (!isVisible()) {
        return;
    }

    for(Cell const &c : m_cellContainer) {
        c.draw(target, states);
    }
    target.draw(m_headerText);
}

int
Column::getPieceIndex(PieceColor color, PieceType type) {
    for (int i = 0; i < m_cellContainer.size(); i++) {
        Cell &cell = m_cellContainer[i];
        if (cell.hasPiece(color, type)) {
            return i;
        }
    }
    return -1;
}

int
Column::removePiece(PieceColor color, PieceType type) {
    for (int i = 0; i < m_cellContainer.size(); i++) {
        Cell &cell = m_cellContainer[i];
        if (cell.hasPiece(color, type)) {
            if (type == PieceType::TYPE_RUNNER) {
                cell.setRunner(false);
            } else {
                cell.removeCamp(color);
            }
            return i;
        }
    }
    return -1;
}

void
Column::placeRunner(PieceColor color) {
    int campIndex = removePiece(color, PieceType::TYPE_CAMP);
    if (campIndex == -1) {
        m_cellContainer.back().setRunner(true);
    } else {
        Cell &campCell = m_cellContainer[campIndex];
        campCell.setRunner(true);
        campCell.removeCamp(color);
    }
}

void
Column::placeCamp(PieceColor color) {
    int index = removePiece(color, PieceType::TYPE_RUNNER);
    if (index != -1) {
        m_cellContainer[index].addCamp(color);
    }
}

void
Column::moveRunner(PieceColor color) {
    int nextIndex = removePiece(color, PieceType::TYPE_RUNNER) - 1;
    Cell &nextCell = m_cellContainer[nextIndex];
    nextCell.setRunner(true);

    if (nextIndex == 0) {
        setLocked(true);
    }
}
