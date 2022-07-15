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
    float m_bottomMargin = 10.0F;
    sf::Vector2f m_cellDim = { 50.0F, 50.0F };
    std::vector<Cell> m_cells;
    std::map<PieceColor,int> m_campPosition = {};
    int m_runnerIndex{-1};

public:
    explicit Column(size_t length);

    void pack();

    void setCellMargin(float margin);
    void setCellSize(sf::Vector2f cellDim);

    void placeCamp(PieceColor color);
    void placeRunner(PieceColor color);

    void moveRunner(PieceColor);

    bool isFinished() const;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    bool inBounds(int i);
};
