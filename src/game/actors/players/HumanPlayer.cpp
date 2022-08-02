//
// Created on 05/07/2022.
//

#include "HumanPlayer.h"

HumanPlayer::HumanPlayer()
    : Player("You", true)
{}

std::array<int, 2>
HumanPlayer::doSelection(PairSelector& pairSelector) {
    return pairSelector.getDecision();
}

std::vector<PlayerAction>
HumanPlayer::generateActions() {
    std::vector<PlayerAction> actions;
    actions.push_back(PlayerAction::IDLE);
    return actions;
}

void HumanPlayer::onBust() {}