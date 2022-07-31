//
// Created on 31/07/2022.
//

#include "HesitantBot.h"

HesitantBot::HesitantBot()
        : Player("Hesitant Bot", false)
{}

std::array<int, 2>
HesitantBot::doSelection(PairSelector& pairSelector) {
    Selection rngSelection = getRandomSelection();
    for (int i : rngSelection) {
        pairSelector.clickButton(i);
    }

    for (int i = 0; i < rngSelection.size(); i+= 2) {
        int sum = rngSelection[i] + rngSelection[i+1];
        auto sumFound = std::find(m_runnerVec.begin(), m_runnerVec.end(), sum);
        if (sumFound == m_runnerVec.end()) {
            m_runnerVec.push_back(sum);
        }
    }

    return pairSelector.getDecision();
}

std::vector<PlayerAction>
HesitantBot::generateActions() {
    ActionVec actions;
    if (m_runnerVec.size() < 3) {
        doRoll(actions);
    } else {
        switchPlayer(actions);
        m_runnerVec.clear();
    }
    return actions;
}

std::array<int, 4>
HesitantBot::getRandomSelection() const {
    Selection arr { 0, 1, 2, 3 };
    std::random_shuffle(arr.begin(), arr.end());

    return arr;
}
