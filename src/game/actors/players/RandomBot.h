//
// Created on 31/07/2022.
//

#pragma once

#include "../../../graphics/components/misc/pairing/PairSelector.h"
#include "../PlayerEnums.h"
#include "../Player.h"

class RandomBot : public Player {
public:
    RandomBot();
    std::array<int, 2> doSelection(PairSelector& pairSelector) override;
    ActionVec generateActions() override;

    Selection getRandomSelection() const;
};
