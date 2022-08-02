//
// Created by moman on 31.07.2022.
//

#include <gtest/gtest.h>
#include "../graphics/components/board/Board.h"

class ComponentTest : public ::testing::Test {
protected:
  Board board_ = Board();
  Column column_ = Column({1,3},{1,1},3,2);
  Cell cell_ = Cell({1,1},{1,1},false);
};

TEST_F(ComponentTest, RemoveAllRunnersTest) {
    /*
  board_.getColumnContainer().at(1).placeRunner(PieceOwner::PLAYER_ONE);
  board_.getColumnContainer().at(2).placeRunner(PieceOwner::PLAYER_ONE);
  board_.getColumnContainer().at(3).placeRunner(PieceOwner::PLAYER_ONE);

  board_.removeAllRunners(PieceOwner::PLAYER_ONE);

  ASSERT_EQ(board_.getColumnContainer().at(1).getPieceIndex(PieceOwner::PLAYER_ONE, PieceType::TYPE_RUNNER),-1);
  ASSERT_EQ(board_.getColumnContainer().at(2).getPieceIndex(PieceOwner::PLAYER_ONE, PieceType::TYPE_RUNNER),-1);
  ASSERT_EQ(board_.getColumnContainer().at(3).getPieceIndex(PieceOwner::PLAYER_ONE, PieceType::TYPE_RUNNER),-1);
    */
}

TEST_F(ComponentTest, RemovePieceTest){
  column_.getCellContainer()[1].addCamp(PieceOwner::PLAYER_ONE);
  column_.removePiece(PieceOwner::PLAYER_ONE, PieceType::TYPE_CAMP);
  ASSERT_FALSE(column_.getCellContainer()[1].hasCamp(PieceOwner::PLAYER_ONE));

  column_.placeRunner(PieceOwner::PLAYER_ONE);
  column_.removePiece(PieceOwner::PLAYER_ONE, PieceType::TYPE_RUNNER);
  ASSERT_FALSE(column_.getCellContainer()[2].hasRunner());
}

TEST_F(ComponentTest, PlaceRunnerTest){
  column_.getCellContainer()[2].addCamp(PieceOwner::PLAYER_ONE);
  column_.placeRunner(PieceOwner::PLAYER_ONE);
  ASSERT_TRUE(column_.getCellContainer()[2].hasRunner());

  column_.getCellContainer()[2].addCamp(PieceOwner::PLAYER_TWO);
  column_.placeRunner(PieceOwner::PLAYER_TWO);
  ASSERT_TRUE(column_.getCellContainer().at(2).hasRunner());
}

TEST_F(ComponentTest, PlaceCampTest){
  column_.placeRunner(PieceOwner::PLAYER_ONE);
  column_.placeCamp(PieceOwner::PLAYER_ONE);
  ASSERT_TRUE(column_.getCellContainer()[2].hasCamp(PieceOwner::PLAYER_ONE));

  column_.placeRunner(PieceOwner::PLAYER_TWO);
  column_.placeCamp(PieceOwner::PLAYER_TWO);
  ASSERT_TRUE(column_.getCellContainer()[2].hasCamp(PieceOwner::PLAYER_TWO));
}

TEST_F(ComponentTest, MoveRunnerTest){
  column_.placeRunner(PieceOwner::PLAYER_ONE);
  column_.moveRunner(PieceOwner::PLAYER_ONE);
  ASSERT_TRUE(column_.getCellContainer()[1].hasRunner());
}

TEST_F(ComponentTest, CampTest) {
  cell_.addCamp(PieceOwner::PLAYER_ONE);
  ASSERT_TRUE(cell_.hasCamp(PieceOwner::PLAYER_ONE));
  cell_.removeCamp(PieceOwner::PLAYER_ONE);
  ASSERT_FALSE(cell_.hasCamp(PieceOwner::PLAYER_ONE));
}

TEST_F(ComponentTest, RunnerTest){
  cell_.setRunner(true);
  ASSERT_TRUE(cell_.hasRunner());
  cell_.setRunner(false);
  ASSERT_FALSE(cell_.hasRunner());
}

TEST_F(ComponentTest, VisibilityTest){
  cell_.setVisible(true);
  ASSERT_TRUE(cell_.isVisible());
  cell_.setVisible(false);
  ASSERT_FALSE(cell_.isVisible());
}

TEST_F(ComponentTest, LockTest){
  cell_.setLocked(true);
  ASSERT_TRUE(cell_.isLocked());
  cell_.setLocked(false);
  ASSERT_FALSE(cell_.isLocked());
}