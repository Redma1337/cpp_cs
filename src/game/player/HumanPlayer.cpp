//
// Created on 05/07/2022.
//

#include "HumanPlayer.h"

HumanPlayer::HumanPlayer()
    : Player("You", true)
{}

std::array<int, 2>
HumanPlayer::doSelection(PairSelector& pairSelector) {
    std::cout << "Human Player turning...." << std::endl;
    return pairSelector.getDecision();
}

std::vector<EPlayerAction>
HumanPlayer::generateActions() {
    std::vector<EPlayerAction> actions;
    actions.push_back(EPlayerAction::IDLE);
    return actions;
}