//
// Created on 31/07/2022.
//

#include <gtest/gtest.h>
#include "../game/actors/players/IntelligentBot.h"

class BotTest : public ::testing::Test {
protected:
    IntelligentBot ibot_;
    Bot bot_;
};

TEST_F(BotTest, BestSumOfRollTest) {
    ASSERT_EQ(bot_.getBestSumOfRoll({ 5, 3, 2, 1 })[0], 0);
    ASSERT_EQ(bot_.getBestSumOfRoll({ 5, 3, 2, 1 })[1], 2);

    ASSERT_EQ(bot_.getBestSumOfRoll({ 1, 4, 4, 3 })[0], 1);
    ASSERT_EQ(bot_.getBestSumOfRoll({ 1, 4, 4, 3 })[1], 3);
}

TEST_F(BotTest, AdvanceScoreTest) {
    ibot_.addRunner(0, 1, { 2, 3, 1, 4});
    ibot_.advance(5);
    ASSERT_EQ(ibot_.getCurrentScore(), 9);
    ibot_.resetScore();
    ibot_.addRunner(0, 1, { 5, 5, 1, 4});
    ibot_.advance(10);
    ASSERT_EQ(ibot_.getCurrentScore(), 12);
    ibot_.resetScore();
    ibot_.addRunner(0, 1, { 1, 1, 1, 4});
    ibot_.advance(2);
    ASSERT_EQ(ibot_.getCurrentScore(), 18);
}

TEST_F(BotTest, getRandomSelection) {
    ASSERT_NE(bot_.getRandomSelection(), bot_.getRandomSelection());
}

TEST_F(BotTest, getMatchingSelection) {
    std::array<int, 4> find = bot_.findMatchingSelection({ 1, 2, 6, 1}, 8);
    ASSERT_EQ(find[0], 1);
    ASSERT_EQ(find[1], 2);

    find = bot_.findMatchingSelection({ 1, 2, 6, 1}, 3);
    ASSERT_EQ(find[0], 0);
    ASSERT_EQ(find[1], 1);
}

TEST_F(BotTest, getBestSelection) {
    std::vector<int> bestSelec = ibot_.getBestSelection({ 3, 1, 6, 2}, { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 });
    std::vector<int> result = { 2, 1, 0, 3};
    for (int i : bestSelec) {
        ASSERT_EQ(bestSelec[i], result[i]);
    }

    //2255
    bestSelec = ibot_.getBestSelection({ 2, 3, 6, 4}, { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 });
    result = { 3, 1, 0, 2};
    for (int i : bestSelec) {
        ASSERT_EQ(bestSelec[i], result[i]);
    }

    bestSelec = ibot_.getBestSelection({ 5, 1, 6, 2}, { 6, 12, 11 });
    result = { 1, 0, 2, 3 };
    for (int i : bestSelec) {
        ASSERT_EQ(bestSelec[i], result[i]);
    }

    bestSelec = ibot_.getBestSelection({ 5, 1, 6, 2}, { 5, 10, 12 });
    result = { 0, 1, 2, 3 };
    for (int i : bestSelec) {
        ASSERT_EQ(bestSelec[i], result[i]);
    }

    bestSelec = ibot_.getBestSelection({ 6, 1, 6, 2}, { 6, 10, 12 });
    result = { 2, 0, 1, 3 };
    for (int i : bestSelec) {
        ASSERT_EQ(bestSelec[i], result[i]);
    }
}
