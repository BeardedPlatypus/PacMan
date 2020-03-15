#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <objects/behaviours/BonusFruitScoreBehaviour.h>
#include "UpdatablePlayerEntityMock.h"

using ::testing::Eq;

namespace pacman {
namespace update {
namespace object {

TEST(BonusFruitScoreBehaviourTest, Execute_IncrementsScoreBoard) {
  // Setup
  const unsigned int expected_value = 100;

  std::unique_ptr<state::score::IScoreBoard> p_score_board =
    state::score::IScoreBoard::Construct();

  BonusFruitScoreBehaviour behaviour = BonusFruitScoreBehaviour(p_score_board.get());
  UpdatablePlayerEntityMock entity;

  // Call | Assert
  behaviour.Execute(&entity);

  // Assert
  EXPECT_THAT(p_score_board->GetScore(), Eq(expected_value));
}

}
}
}
