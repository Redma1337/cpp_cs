//
// Created on 05/07/2022.
//

#pragma once

#include "../Player.h"

class HumanPlayer : public Player {
public:
    HumanPlayer();

    std::array<int, 2> doSelection(PairSelector& pairSelector) override;
    std::vector<PlayerAction> generateActions() override;
    void onBust() override;
};
