
#include "game/CantStop.h"
#include <unordered_set>
#include <iterator>

std::vector<int> cols = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

std::vector<int> getFirstPair(std::vector<int> roll, int sum) {
    std::vector<int> result = { -1, -1 };
    std::unordered_set<int> set;
    for (int i = 0; i < roll.size(); i++) {
        int temp = sum - roll[i];

        auto tempFound = std::find(roll.begin(), roll.end(), temp);
        if (set.find(temp) != set.end()) {
            result[0] = i;
            result[1] = std::distance(roll.begin(), tempFound);
            return result;
        }

        set.insert(roll[i]);
    }
    return result;
}

std::vector<int> getBestSelection(std::vector<int> roll) {
    int bestSum = 0;
    std::vector<int> result = { -1, -1 };
    for (int sum : cols) {
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
    result.push_back(3 - result[0]);
    result.push_back(3 - result[1]);

    return result;
}

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    CantStop cantStop(settings);
    cantStop.start();
    return 0;
}


