//
// Created on 31/07/2022.
//

#include "IntelligentBot.h"

IntelligentBot::IntelligentBot()
        : Player("Intelligent Bot", false), Bot(),
            m_currentScore{ 0 },
            m_markedVals{ 12, 10, 6, 6, 4, 2, 4, 6, 8, 10, 12 },
            m_advancingVals{ 6, 5, 4, 3, 2, 1, 2, 3, 4, 5, 6 }
{}

std::array<int, 2>
IntelligentBot::doSelection(PairSelector& pairSelector) {
    Selection roll = pairSelector.getRoll();
    Selection selection = {};


    if (m_runnerMap.size() < 3) {
        selection = getBestSumOfRoll(roll);
        if (selection[0] == -1) {
            selection = getRandomSelection();
        }

        addRunner(selection[0], selection[1], roll);
        addRunner(selection[1], selection[2], roll);
    } else {
        int i = 0;
        for (const auto &pair : m_runnerMap) {
            if (i >= 2) continue;
            selection = findMatchingSelection(pairSelector.getRoll(), pair.first);
            if (selection[0] == -1) {
                selection = getRandomSelection();
            }
            moveRunner(selection[0], selection[1], roll);
            i++;
        }
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
        m_currentScore = 0;
        switchPlayer(actions);
    }
    return actions;
}

void
IntelligentBot::addRunner(int first, int second, Selection roll) {
    int runnerSum = roll[first] + roll[second];
    m_runnerMap.insert({ runnerSum, 0 });
    mark(runnerSum);
}

void
IntelligentBot::moveRunner(int first, int second, Selection roll) {
    int runnerSum = roll[first] + roll[second];
    m_runnerMap[runnerSum]++;
    advance(runnerSum);
}

void
IntelligentBot::mark(int sum) {
    m_currentScore += m_markedVals[sum-2];
}

void
IntelligentBot::advance(int sum) {
    m_currentScore += m_advancingVals[sum-2];
}
int
IntelligentBot::getCurrentScore() const {
    return m_currentScore;
}

bool IntelligentBot::isSelectionBetter(const Selection &s1, const Selection &s2, const Selection &roll) {
}
