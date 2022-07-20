//
// Created on 05/07/2022.
//

#pragma once
#include "EPieceColor.h"
#include "../components/PairSelector.h"
#include <string>
#include <array>
#include <memory>

class Player {
protected:
    PieceColor m_color;
    const std::string m_name;
    const bool m_isHuman;
public:
    virtual ~Player() = default;

    Player(std::string name, bool human); //pass string by value because we will std::move it

    virtual std::array<int, 2> generateTurn(PairSelector& pairSelector) = 0;

    PieceColor getColor() const;
    void setColor(PieceColor color);

    std::string getName() const;

    bool isHuman() const;
};
