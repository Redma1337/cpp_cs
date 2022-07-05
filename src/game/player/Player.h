//
// Created on 05/07/2022.
//

#pragma once
#include "EPieceColor.h"
#include <string>
#include <array>

class Player {
protected:
    PieceColor m_color;
    const std::string m_name;
    const bool m_isHuman;
public:
    virtual ~Player() = default;

    Player(std::string name, bool human); //pass string by value because we will std::move it

    virtual std::array<int, 2> generateTurn(std::array<int, 4> dices) = 0;

    const PieceColor getColor() const;
    void setColor(PieceColor color);
    const std::string getName() const;
    const bool isHuman() const;
};
