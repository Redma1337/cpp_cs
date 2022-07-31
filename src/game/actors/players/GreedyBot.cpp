//
// Created on 31/07/2022.
//

#include "GreedyBot.h"

GreedyBot::GreedyBot()
        : Player("Greedy Bot", false), m_runnerMap{  }
{}

std::array<int, 2>
GreedyBot::doSelection(PairSelector& pairSelector) {
    Selection roll = pairSelector.getRoll();
    Selection selection = {};
    if (m_runnerMap.size() < 3) {
        selection = getRandomSelection();
        addRunner(selection[0], selection[1], roll);
        addRunner(selection[1], selection[2], roll);
    } else {
        for (auto &pair : m_runnerMap) {
            selection = findMatchingSelection(pairSelector.getRoll(), pair.first);
            if (selection[0] == 0 && selection[1] == 0) {
                selection = getRandomSelection();
            } else {
                pair.second += 1;
            }
        }
    }

    for (int i : selection) {
        pairSelector.clickButton(i);
    }
    return pairSelector.getDecision();
}

std::vector<PlayerAction>
GreedyBot::generateActions() {
    std::vector<PlayerAction> actions;
    doRoll(actions);
    return actions;
}

std::array<int, 4>
GreedyBot::getRandomSelection() const {
    Selection arr { 0, 1, 2, 3 };
    std::random_shuffle(arr.begin(), arr.end());
    return arr;
}

std::array<int, 4>
GreedyBot::findMatchingSelection(Selection roll, int sum) const {
    for (int i = 0; i < roll.size(); i++) {
        for (int j = 0; j < roll.size(); j++) {
            if (i == j) continue;
            int total = roll[i] + roll[j];
            if (total == sum) {
                return { i, j, 3 - i, 3 - j};
            }
        }
    }
    return {};
}

void GreedyBot::addRunner(int first, int second, Selection roll) {
    if (m_runnerMap.size() >= 3) {
        return;
    }
    m_runnerMap.insert({ roll[first] + roll[second], 0 });
}

