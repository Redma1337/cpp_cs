//
// Created on 31/07/2022.
//

#include "HesitantBot.h"

HesitantBot::HesitantBot()
        : Player("Hesitant Bot", false)
{}

std::array<int, 2>
HesitantBot::doSelection(PairSelector& pairSelector) {
    pairSelector.clickButton(0);
    pairSelector.clickButton(2);
    pairSelector.clickButton(1);
    pairSelector.clickButton(3);
    return pairSelector.getDecision();
}

std::vector<PlayerAction>
HesitantBot::generateActions() {
    std::vector<PlayerAction> actions;
    actions.push_back(PlayerAction::WAIT);
    actions.push_back(PlayerAction::ROLL_DICE);
    actions.push_back(PlayerAction::WAIT);
    actions.push_back(PlayerAction::WAIT);
    actions.push_back(PlayerAction::MAKE_SELECTION);
    actions.push_back(PlayerAction::WAIT);
    actions.push_back(PlayerAction::WAIT);
    actions.push_back(PlayerAction::SWITCH_PLAYER);
    actions.push_back(PlayerAction::WAIT);
    return actions;
}