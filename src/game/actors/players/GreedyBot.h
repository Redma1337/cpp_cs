//
// Created on 31/07/2022.
//

#pragma once

#include "../../../graphics/components/misc/pairing/PairSelector.h"
#include "../Player.h"

class GreedyBot : public Player  {
    std::array<int, 3> m_runner;
public:
    GreedyBot();
    std::array<int, 2> doSelection(PairSelector& pairSelector) override;
    std::vector<PlayerAction> generateActions() override;

    Selection getRandomSelection() const;
    Selection findMatchingSelection(Selection roll) const;
};
