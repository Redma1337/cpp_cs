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
    std::map<int, int> m_campMap;

    std::vector<int> m_markedVals;
    std::vector<int> m_advancingVals;
    std::vector<int> m_wonCols;
    std::vector<int> m_colLengths;
public:
    IntelligentBot();
    std::array<int, 2> doSelection(PairSelector& pairSelector) override;
    std::vector<PlayerAction> generateActions() override;
    void onBust() override;

    void addRunner(int first, int second, Selection roll);
    void moveRunner(int first, int second, Selection roll);
    std::vector<int> getBestSelection(std::array<int, 4> roll, std::vector<int> sumPool);

    void mark(int sum);
    void advance(int sum);

    void placeCamps();
    int getCurrentScore() const;
    void resetScore();
    std::map<int, int> getRunnerMap() const;
};
