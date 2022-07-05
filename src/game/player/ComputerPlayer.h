//
// Created on 05/07/2022.
//

#pragma once

#include "EPieceColor.h"
#include "Player.h"

class ComputerPlayer : public Player {
public:
    ComputerPlayer(std::string name);
    std::array<int, 2> generateTurn(std::array<int, 4> dices) override;
};