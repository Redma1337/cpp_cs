//
// Created on 31/07/2022.
//

#include <gtest/gtest.h>
#include "../game/actors/players/IntelligentBot.h"

class IntelligentBotTest : public ::testing::Test {
protected:
    IntelligentBot bot_;
};

TEST_F(IntelligentBotTest, BestSumOfRollTest) {
    ASSERT_EQ(bot_.getBestSumOfRoll({ 5, 3, 2, 1 }), 7);
    ASSERT_EQ(bot_.getBestSumOfRoll({ 1, 4, 4, 3 }), 7);
    ASSERT_EQ(bot_.getBestSumOfRoll({ 1, 2, 2, 1 }), 4);
    ASSERT_EQ(bot_.getBestSumOfRoll({ 6, 2, 2, 1 }), 8);
}
