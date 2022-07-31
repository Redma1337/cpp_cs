//
// Created on 31/07/2022.
//

#include "IntelligentBot.h"

IntelligentBot::IntelligentBot()
        : Player("Intelligent Bot", false)
{}

std::array<int, 2>
IntelligentBot::doSelection(PairSelector& pairSelector) {
    pairSelector.clickButton(0);
    pairSelector.clickButton(2);
    pairSelector.clickButton(1);
    pairSelector.clickButton(3);
    return pairSelector.getDecision();
}

std::vector<PlayerAction>
IntelligentBot::generateActions() {
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