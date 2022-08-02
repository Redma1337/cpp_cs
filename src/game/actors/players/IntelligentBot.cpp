//
// Created on 31/07/2022.
//

#include <iostream>
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

    std::vector<int> best;
    if (m_runnerMap.size() < 3) {
        best = getBestSelection(roll, m_colValues);

        std::cout << "Playing runner... | Roll was: ";
        for (int i : roll) {
            std::cout << std::to_string(i);
        }
        std::cout << std::endl << "Choosing...: ";
        for (int i : best) {
            std::cout << std::to_string(i);
        }
        std::cout << std::endl;

        addRunner(best[0], best[1], roll);
        addRunner(best[2], best[3], roll);
    } else {
        std::vector<int> runnerPool;
        for (const auto &pair : m_runnerMap) {
            runnerPool.push_back(pair.first);
        }

        best = getBestSelection(roll, runnerPool);

        std::cout << "Playing runner... | Roll was: ";
        for (int i : roll) {
            std::cout << std::to_string(i);
        }
        std::cout << std::endl << "Runner pool is: ";
        for (int i : runnerPool) {
            std::cout << std::to_string(i);
        }
        std::cout << std::endl << "Choosing...: ";
        for (int i : best) {
            std::cout << std::to_string(i);
        }
        std::cout << std::endl;

        moveRunner(best[0], best[1], roll);
        moveRunner(best[2], best[3], roll);
    }

    std::cout << "Current score: " << m_currentScore << std::endl;

    for (int i : best) {
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
        m_runnerMap = {};
        switchPlayer(actions);
    }
    return actions;
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
IntelligentBot::moveRunner(int first, int second, Selection roll) {
    int runnerSum = roll[first] + roll[second];
    m_runnerMap[runnerSum] += 1;
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

std::vector<int>
IntelligentBot::getBestSelection(std::array<int, 4> roll, std::vector<int> sumPool) {
    int bestSum = 0;
    std::vector<int> result = { -1, -1 };
    for (int sum : sumPool) {
        std::vector<int> s = getFirstPair(roll, sum);
        if (s[0] != -1 && s[1] != -1) {
            int currBestDiff = std::abs(7 - bestSum);
            int sumDiff = std::abs(7 - sum);
            if (currBestDiff > sumDiff) {
                bestSum = sum;
                result[0] = s[0];
                result[1] = s[1];
            }
        }
    }
    if (result[0] == -1 && result[1] == -1) {
        return { 0, 1, 2, 3 };
    }

    for (int i = 0; i < roll.size(); i++) {
        if (i != result[0] && i != result[1]) {
            result.push_back(i);
        }
    }

    return result;
}

std::map<int, int>
IntelligentBot::getRunnerMap() const {
    return m_runnerMap;
}
