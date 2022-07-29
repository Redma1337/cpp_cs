//
// Created on 06/07/2022.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "../player/EPieceColor.h"
#include "../player/EPieceType.h"
#include "Component.h"

class Cell : public Component {
    std::map<PieceColor, bool> m_camps;
    bool m_hasRunner; //we will at most have 1 runner of the current player
    sf::Color m_color;
public:
    explicit Cell(const sf::Vector2f &dim, const sf::Vector2f &pos);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void setRunner(bool state);
    bool hasRunner() const;

    bool hasCamp(PieceColor color);
    void addCamp(PieceColor color);
    void removeCamp(PieceColor color);

    bool hasPiece(PieceColor color, PieceType type);

    void reset();
};
