//
// Created on 31/07/2022.
//

#include "RandomBot.h"
#include "../../controller/DiceController.h"
#include <random>
#include <array>

RandomBot::RandomBot()
        : Player("Random Bot", false)
{}

std::array<int, 2>
RandomBot::doSelection(PairSelector& pairSelector) {
    for (int i : getRandomSelection()) {
        pairSelector.clickButton(i);
    }

    return pairSelector.getDecision();
}

std::vector<PlayerAction>
RandomBot::generateActions() {
    ActionVec actions;

    bool flip = DiceController::getRandomInt(0, 1);
    if (flip) {
        doRoll(actions);
    } else {
        switchPlayer(actions);
    }
    return actions;
}

std::array<int, 4>
RandomBot::getRandomSelection() const {
    Selection arr { 0, 1, 2, 3 };
    std::random_shuffle(arr.begin(), arr.end());

    return arr;
}

