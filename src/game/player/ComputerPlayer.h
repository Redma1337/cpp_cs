//
// Created on 05/07/2022.
//

#pragma once

#include "EPieceOwner.h"
#include "Player.h"
#include "../controller/EPlayerAction.h"

class ComputerPlayer : public Player {
public:
    ComputerPlayer(std::string name);

    std::array<int, 2> doSelection(PairSelector& pairSelector) override;
    std::vector<EPlayerAction> generateActions() override;
};