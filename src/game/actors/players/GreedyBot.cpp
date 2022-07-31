//
// Created on 31/07/2022.
//

#include "GreedyBot.h"

GreedyBot::GreedyBot()
        : Player("Greedy Bot", false)
{}

std::array<int, 2>
GreedyBot::doSelection(PairSelector& pairSelector) {
    Selection roll = pairSelector.getRoll();
    Selection selection = {};
    if (m_runner.empty()) {
        selection = getRandomSelection();
        m_runner[0] = selection[0] + selection[1];
        m_runner[1] = selection[1] + selection[2];
    } else {
        selection = findMatchingSelection(pairSelector.getRoll());
    }

    for (int i : selection) {
        pairSelector.clickButton(i);
    }
    return pairSelector.getDecision();
}

std::vector<PlayerAction>
GreedyBot::generateActions() {
    std::vector<PlayerAction> actions;
    size_t lengths[] = { 3, 5, 7, 9, 11, 13, 11, 9, 7, 5, 3 };
    return actions;
}

std::array<int, 4>
GreedyBot::getRandomSelection() const {
    Selection arr { 0, 1, 2, 3 };
    std::random_shuffle(arr.begin(), arr.end());

    return arr;
}

std::array<int, 4>
GreedyBot::findMatchingSelection(Selection roll) const {
    for (int runnerSum : m_runner) {

    }
}
