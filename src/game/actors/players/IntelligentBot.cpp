//
// Created on 31/07/2022.
//

#include "IntelligentBot.h"

IntelligentBot::IntelligentBot()
        : Player("Intelligent Bot", false), m_currentScore{ 0 },
            m_colValues{ 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 },
            m_markedVals{ 12, 10, 6, 6, 4, 2, 4, 6, 8, 10, 12 },
            m_advancingVals{ 6, 5, 4, 3, 2, 1, 2, 3, 4, 5, 6 }
{}

std::array<int, 2>
IntelligentBot::doSelection(PairSelector& pairSelector) {
    Selection roll = pairSelector.getRoll();
    Selection selection = {};

    if (m_runnerMap.size() < 3) {
        int bestSum = getBestSumOfRoll(roll);
        if (bestSum == -1) {

        }
    } else {

    }

    for (int i : selection) {
        pairSelector.clickButton(i);
    }
    return pairSelector.getDecision();
}

std::vector<PlayerAction>
IntelligentBot::generateActions() {
    std::vector<PlayerAction> actions;
    if (m_currentScore < 28) {
        doRoll(actions);
    } else {
        switchPlayer(actions);
    }
    return actions;
}

std::array<int, 4>
IntelligentBot::findMatchingSelection(Selection roll, int sum) const {
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

void
IntelligentBot::addRunner(int first, int second, Selection roll) {
    if (m_runnerMap.size() >= 3) {
        return;
    }
    int runnerSum = roll[first] + roll[second];
    m_runnerMap.insert({ runnerSum, 0 });
    mark(runnerSum);
}

void
IntelligentBot::mark(int sum) {
    m_currentScore += m_markedVals[sum-2];
}

void
IntelligentBot::advance(int sum) {
    m_currentScore += m_advancingVals[sum-2];
}

int IntelligentBot::getBestSumOfRoll(Selection roll) {
    int bestSum = 0;
    for (int sum : m_colValues) {
        Selection selection = findMatchingSelection(roll, sum);
        if (selection[0] != 0 && selection[1] != 0) {
            int currBestDiff = std::abs(7 - bestSum);
            int sumDiff = std::abs(7 - sum);
            if (currBestDiff > sumDiff) {
                bestSum = sum;
            }
        }
    }
    return bestSum;
}

