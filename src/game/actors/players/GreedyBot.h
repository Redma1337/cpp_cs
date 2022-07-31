//
// Created on 31/07/2022.
//

#pragma once

#include "../../../graphics/components/misc/pairing/PairSelector.h"
#include "../Player.h"
#include "Bot.h"

class GreedyBot : public Player, Bot  {
    std::map<int, int> m_runnerMap;
public:
    GreedyBot();
    std::array<int, 2> doSelection(PairSelector& pairSelector) override;
    std::vector<PlayerAction> generateActions() override;

    void addRunner(int first, int second, Selection roll);
};
