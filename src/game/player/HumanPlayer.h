//
// Created on 05/07/2022.
//

#pragma once

#include "Player.h"

class HumanPlayer : public Player {
public:
    HumanPlayer(std::string name);
    std::array<int, 2> generateTurn(std::array<int, 4> dices) override;
};