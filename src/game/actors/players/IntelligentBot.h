//
// Created on 31/07/2022.
//

#pragma once

#include "../../../graphics/components/misc/pairing/PairSelector.h"
#include "../PlayerEnums.h"
#include "../Player.h"
#include "Bot.h"

class IntelligentBot : public Player, Bot {
    int m_currentScore;
    std::map<int, int> m_runnerMap;
    std::vector<int> m_colValues;
    std::vector<int> m_markedVals;
    std::vector<int> m_advancingVals;
public:
    IntelligentBot();
    std::array<int, 2> doSelection(PairSelector& pairSelector) override;
    std::vector<PlayerAction> generateActions() override;

    void addRunner(int first, int second, Selection roll);
    void moveRunner(int first, int second, Selection roll);
    bool isSelectionBetter(const Selection &s1, const Selection &s2, const Selection &roll);

    void mark(int sum);
    void advance(int sum);

    int getCurrentScore() const;

};
