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
    ibot_.advance(5);
    ASSERT_EQ(ibot_.getCurrentScore(), 3);
    ibot_.advance(10);
    ASSERT_EQ(ibot_.getCurrentScore(), 7);
    ibot_.mark(2);
    ASSERT_EQ(ibot_.getCurrentScore(), 19);
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
