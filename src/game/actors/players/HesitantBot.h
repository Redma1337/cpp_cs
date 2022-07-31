//
// Created on 31/07/2022.
//

#pragma once

#include "../../../graphics/components/misc/pairing/PairSelector.h"
#include "../PlayerEnums.h"
#include "../Player.h"
#include "Bot.h"

class HesitantBot : public Player, Bot {
    std::vector<int> m_runnerVec;
public:
    HesitantBot();
    std::array<int, 2> doSelection(PairSelector& pairSelector) override;
    std::vector<PlayerAction> generateActions() override;
};
