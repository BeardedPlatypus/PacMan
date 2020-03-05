#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <objects/behaviours/SmallDotScoreBehaviour.h>
#include "UpdatablePlayerEntityMock.h"

using ::testing::Eq;

namespace pacman {
namespace update {
namespace object {

TEST(SmallDotScoreBehaviourTest, Execute_IncrementsScoreBoard) {
  // Setup
  const unsigned int expected_value = 10;

  std::unique_ptr<state::score::IScoreBoard> p_score_board =
    state::score::IScoreBoard::Construct();

  SmallDotScoreBehaviour behaviour = SmallDotScoreBehaviour(p_score_board.get());
  UpdatablePlayerEntityMock entity;

  // Call | Assert
  behaviour.Execute(&entity);

  // Assert
  EXPECT_THAT(p_score_board->GetScore(), Eq(expected_value));
}

}
}
}
