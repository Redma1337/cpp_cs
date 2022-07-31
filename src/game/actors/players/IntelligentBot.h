//
// Created on 31/07/2022.
//

#pragma once

#include "../../../graphics/components/misc/pairing/PairSelector.h"
#include "../PlayerEnums.h"
#include "../Player.h"

class IntelligentBot : public Player {
    int m_currentScore;
    std::map<int, int> m_runnerMap;
    std::vector<int> m_colValues;
    std::vector<int> m_markedVals;
    std::vector<int> m_advancingVals;
public:
    IntelligentBot();
    std::array<int, 2> doSelection(PairSelector& pairSelector) override;
    std::vector<PlayerAction> generateActions() override;

    Selection findMatchingSelection(Selection roll, int sum) const;
    Selection getRandomSelection() const;
    void addRunner(int first, int second, Selection roll);
    int getBestSumOfRoll(Selection roll);

    void mark(int sum);
    void advance(int sum);
};
