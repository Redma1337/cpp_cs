//
// Created on 06/07/2022.
//

#include "Column.h"
#include "../../utils/RenderWrapper.h"

Column::Column(const sf::Vector2f &dim, const sf::Vector2f &pos, const int length, const int sum)
    :   Component(dim, pos),
        m_length{ length },
        m_sum{ sum },
        m_cellContainer{}
{
    pack();

    sf::Vector2f centerPos = { m_position.x + (m_cellDim.x / 2.0f), m_position.y + (m_cellDim.y / 2.0f)};
    m_headerText = RenderWrapper::createCenteredString(std::to_string(sum), centerPos, 20, sf::Color::White);
    m_lockedBorder = RenderWrapper::createRoundedRect(m_position, m_dimension, sf::Color::Transparent, 6);
    m_lockedBorder.setOutlineThickness(2);
    m_lockedBorder.setOutlineColor(sf::Color(0xdc2626ff));
}

void
Column::pack() {
    float yOff = 0.0F;

    for (int i = 0; i < m_length; i++) {
        Cell cell(m_cellDim, { m_position.x, m_position.y + yOff }, i == 0);

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
    if (m_locked) {
        target.draw(m_lockedBorder);
    }

    target.draw(m_headerText);
}

int
Column::getPieceIndex(PieceOwner color, PieceType type) {
    for (int i = 0; i < m_cellContainer.size(); i++) {
        Cell &cell = m_cellContainer[i];
        if (cell.hasPiece(color, type) && !isLocked()) {
            return i;
        }
    }
    return -1;
}

int
Column::removePiece(PieceOwner color, PieceType type) {
    if (isLocked()) {
        return -1;
    }

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
Column::placeRunner(PieceOwner color) {
    if (isLocked()) {
        return;
    }

    int campIndex = getPieceIndex(color, PieceType::TYPE_CAMP);
    if (campIndex == -1) {
        m_cellContainer.back().setRunner(true);
    } else {
        int nextIndex = campIndex - 1;
        Cell &campCell = m_cellContainer[nextIndex];
        campCell.setRunner(true);

        if (nextIndex == 0) {
            setLocked(color, true);
        }
    }
}

void
Column::placeCamp(PieceOwner color) {
    if (isLocked()) {
        return;
    }

    removePiece(color, PieceType::TYPE_CAMP);
    int index = removePiece(color, PieceType::TYPE_RUNNER);
    if (index != -1) {
        m_cellContainer[index].addCamp(color);
    }
}

void
Column::moveRunner(PieceOwner color) {
    if (isLocked()) {
        return;
    }

    int nextIndex = removePiece(color, PieceType::TYPE_RUNNER) - 1;
    Cell &nextCell = m_cellContainer[nextIndex];
    nextCell.setRunner(true);

    if (nextIndex == 0) {
        setLocked(color, true);
    }
}

void Column::setLocked(PieceOwner winner, bool state) {
    removePiece(PieceOwner::PLAYER_ONE, PieceType::TYPE_CAMP);
    removePiece(PieceOwner::PLAYER_TWO, PieceType::TYPE_CAMP);
    m_cellContainer[0].addCamp(winner);
    Component::setLocked(state);
}

std::vector<Cell>
Column::getCellContainer(){
  return m_cellContainer;
}

bool Column::isWon(PieceOwner color) {
    return isLocked() && m_cellContainer[0].hasCamp(color);
}

