#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "score/IScoreBoard.h"

#pragma region using_statements
using ::testing::Eq;
#pragma endregion

namespace pacman {
namespace state {
namespace score {

TEST(ScoreBoardTest, Constructor_ExpectedResult) {
  // Call
  std::unique_ptr<IScoreBoard> score_board = IScoreBoard::Construct();

  // Assert
  EXPECT_THAT(score_board->GetScore(), Eq(0));
}


TEST(ScoreBoardTest, IncrementScore_ExpectedResult) {
  // Setup
  unsigned int expected_value = 253;
  std::unique_ptr<IScoreBoard> score_board = IScoreBoard::Construct();

  // Call
  score_board->IncrementScore(expected_value);

  // Assert
  EXPECT_THAT(score_board->GetScore(), Eq(expected_value));
}


TEST(ScoreBoardTest, Reset_ExpectedResult) {
  // Setup
  std::unique_ptr<IScoreBoard> score_board = IScoreBoard::Construct();
  score_board->IncrementScore(253);

  // Call
  score_board->Reset();

  // Assert
  EXPECT_THAT(score_board->GetScore(), Eq(0));
}

}
}
}