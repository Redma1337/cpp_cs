//
// Created on 06/07/2022.
//

#include "Column.h"

Column::Column(const size_t length)
    : m_length{ length },
        Component({ 50, length * 50.0f })
{}

void
Column::pack() {
    float yOff = 0.0F;

    for (int i = 0; i < m_length; i++) {
        Cell cell(m_cellDim);
        cell.setPos({ m_position.x, m_position.y + yOff });

        m_cells.push_back(cell);
        yOff += m_cellDim.y + m_bottomMargin;
    }
}

void
Column::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(Cell const &c : m_cells) {
        c.draw(target, states);
    }
}

void
Column::setCellMargin(float margin) {
    m_bottomMargin = margin;
}
void
Column::setCellSize(sf::Vector2f dim) {
    m_cellDim = dim;
}


void
removeRunner(std::vector<Cell> &cells, PieceColor color, int runnerIndex){
  cells.at(static_cast<unsigned int>(runnerIndex)).setPieceType(color,PieceType::TYPE_EMPTY);
}
void
removeOldCamp(std::vector<Cell> &cells, PieceColor color, std::map<PieceColor, int> &campPosition){
  cells.at(static_cast<unsigned int>(campPosition.at(color))).setPieceType(color, PieceType::TYPE_EMPTY);
}
void
setNewCamp(std::vector<Cell> &cells, PieceColor color, std::map<PieceColor,int> &campPosition, int runnerIndex){
  campPosition.at(color) = runnerIndex;
  cells.at(static_cast<unsigned int>(campPosition.at(color))).setPieceType(color,PieceType::TYPE_CAMP);
}
void
Column::placeCamp(PieceColor color) {
  if(m_runnerIndex!=-1){
    removeRunner(m_cells, color,m_runnerIndex);
    if(m_campPosition.find(color)!=m_campPosition.end()){
      removeOldCamp(m_cells, color, m_campPosition);
    }
    setNewCamp(m_cells, color, m_campPosition, m_runnerIndex);
    m_runnerIndex = -1;
  }
}


void
placeRunnerOnBoard(std::vector<Cell> &cells, PieceColor color, std::map<PieceColor,int> &campPosition, int &runnerIndex){
  cells.at(static_cast<unsigned int>(campPosition.at(color))).setPieceType(color,PieceType::TYPE_RUNNER);
  runnerIndex = campPosition.at(color);
}
void
Column::placeRunner(PieceColor color) {
  if(m_campPosition.find(color)!=m_campPosition.end()){
    placeRunnerOnBoard(m_cells, color, m_campPosition, m_runnerIndex);
  }
  else{
    std::map<PieceColor,int> tempMap = {{color, m_length-static_cast<unsigned int>(1)}};
    placeRunnerOnBoard(m_cells, color, tempMap, m_runnerIndex);
  }
}


void
setNewRunner(std::vector<Cell> &cells, PieceColor color, int &runnerIndex){
  cells.at(static_cast<unsigned int>(runnerIndex+1)).setPieceType(color, PieceType::TYPE_RUNNER);
  runnerIndex--;
}
void
Column::moveRunner(PieceColor color) {
  if(m_runnerIndex!=-1){
    removeRunner(m_cells,color,m_runnerIndex);
    setNewRunner(m_cells,color,m_runnerIndex);
  }
}

bool
Column::isFinished() const {
  if(m_runnerIndex==0){
    return true;
  }
  return false;
}

bool
Column::inBounds(int i) {
  return false;
}