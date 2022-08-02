//
// Created on 31/07/2022.
//

#pragma once

#include "../../../graphics/components/misc/pairing/PairSelector.h"
#include "../PlayerEnums.h"
#include "../Player.h"
#include "Bot.h"

class RandomBot : public Player, Bot {
public:
    RandomBot();
    std::array<int, 2> doSelection(PairSelector& pairSelector) override;
    ActionVec generateActions() override;
    void onBust() override;
};
