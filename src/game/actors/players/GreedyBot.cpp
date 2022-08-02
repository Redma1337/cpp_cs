//
// Created on 31/07/2022.
//

#include "GreedyBot.h"

GreedyBot::GreedyBot()
        : Player("Greedy Bot", false),
            Bot(),
            m_runnerMap{  }
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
        int i = 0;
        for (auto &pair : m_runnerMap) {
            if (i >= 2) continue;
            selection = findMatchingSelection(pairSelector.getRoll(), pair.first);
            if (selection[0] == -1) {
                selection = getRandomSelection();
            } else {
                pair.second += 1;
            }
            i++;
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

void GreedyBot::addRunner(int first, int second, Selection roll) {
    if (m_runnerMap.size() >= 3) {
        return;
    }
    m_runnerMap.insert({ roll[first] + roll[second], 0 });
}

void GreedyBot::onBust() {
    m_runnerMap.clear();
}
