//
// Created on 31/07/2022.
//

#include "Bot.h"

Bot::Bot()
    : m_colValues{ 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 }
{}

std::array<int, 4>
Bot::findMatchingSelection(Selection roll, int sum) const {
    for (int i = 0; i < roll.size(); i++) {
        for (int j = 0; j < roll.size(); j++) {
            if (i == j) continue;
            int total = roll[i] + roll[j];
            if (total == sum) {
                return { i, j, 3 - i, 3 - j};
            }
        }
    }
    return { -1 };
}

std::array<int, 4>
Bot::getBestSumOfRoll(Selection roll) const {
    int bestSum = 0;
    Selection result = {  };
    for (int sum : m_colValues) {
        Selection s = findMatchingSelection(roll, sum);
        if (s[0] != -1) {
            int currBestDiff = std::abs(7 - bestSum);
            int sumDiff = std::abs(7 - sum);
            if (currBestDiff > sumDiff) {
                bestSum = sum;
                result = s;
            }
        }
    }
    return result;
}

std::array<int, 4>
Bot::getRandomSelection() const {
    Selection arr { 0, 1, 2, 3 };
    std::random_shuffle(arr.begin(), arr.end());

    return arr;
}
