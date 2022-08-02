//
// Created on 31/07/2022.
//

#pragma once
#include <array>
#include <vector>
#include <algorithm>
#include <unordered_set>

class Bot {
protected:
    typedef std::array<int, 4> Selection;
    std::vector<int> m_colValues;
public:
    Bot();

    Selection findMatchingSelection(Selection roll, int sum) const;
    Selection getBestSumOfRoll(Selection roll) const;
    Selection getRandomSelection() const;

    std::vector<int> getBestSelection(std::vector<int> roll);
    std::vector<int> getFirstPair(std::vector<int> roll, int sum);
};
