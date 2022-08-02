//
// Created on 06/07/2022.
//

#pragma once
#include <SFML/Graphics.hpp>
#include "../Component.h"
#include "../../controller/EPieceType.h"
#include "../../../game/actors/PlayerEnums.h"

class Cell : public Component {
    std::map<PieceOwner, bool> m_camps;
    bool m_hasRunner; //we will at most have 1 runner of the current actors
    bool m_isEndCell; //we will at most have 1 runner of the current actors
    sf::Color m_color;
public:
    explicit Cell(const sf::Vector2f &dim, const sf::Vector2f &pos, bool isEndCell);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void setRunner(bool state);
    bool hasRunner() const;

    bool hasCamp(PieceOwner color) const;
    void addCamp(PieceOwner color);
    void removeCamp(PieceOwner color);

    bool hasPiece(PieceOwner color, PieceType type) const;
};
