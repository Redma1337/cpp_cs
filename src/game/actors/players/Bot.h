//
// Created on 31/07/2022.
//

#pragma once
#include <array>
#include <vector>
#include <algorithm>

class Bot {
protected:
    typedef std::array<int, 4> Selection;
    std::vector<int> m_colValues;
public:
    Bot();

    Selection findMatchingSelection(Selection roll, int sum) const;
    Selection getBestSumOfRoll(Selection roll) const;
    Selection getRandomSelection() const;
};
