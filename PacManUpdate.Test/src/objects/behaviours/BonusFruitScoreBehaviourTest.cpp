#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <objects/behaviours/BonusFruitScoreBehaviour.h>
#include "UpdatablePlayerEntityMock.h"
#include "LevelManagerMock.h"

using ::testing::Return;
using ::testing::Eq;

namespace pacman {
namespace update {
namespace object {

class BonusFruitScoreBehaviourExecuteTestData {
public:
  BonusFruitScoreBehaviourExecuteTestData(unsigned int level, unsigned int score) :
      level(level), expected_score(score){ }

  const unsigned int level;
  const unsigned int expected_score;
};

class ExecuteTest : public ::testing::TestWithParam<BonusFruitScoreBehaviourExecuteTestData> {
public:
  static std::vector<BonusFruitScoreBehaviourExecuteTestData> GetTestData() {
    return {
      BonusFruitScoreBehaviourExecuteTestData(0, 100),
      BonusFruitScoreBehaviourExecuteTestData(1, 300),
      BonusFruitScoreBehaviourExecuteTestData(2, 500),
      BonusFruitScoreBehaviourExecuteTestData(3, 700),
      BonusFruitScoreBehaviourExecuteTestData(4, 700),
      BonusFruitScoreBehaviourExecuteTestData(5, 1000),
      BonusFruitScoreBehaviourExecuteTestData(6, 1000),
      BonusFruitScoreBehaviourExecuteTestData(7, 2000),
      BonusFruitScoreBehaviourExecuteTestData(8, 2000),
      BonusFruitScoreBehaviourExecuteTestData(9, 3000),
      BonusFruitScoreBehaviourExecuteTestData(10, 3000),
      BonusFruitScoreBehaviourExecuteTestData(11, 5000),
      BonusFruitScoreBehaviourExecuteTestData(12, 5000),
      BonusFruitScoreBehaviourExecuteTestData(13, 5000),
    };
  }
};

TEST_P(ExecuteTest, Execute_IncrementsScoreBoard) {
  // Setup
  std::unique_ptr<state::score::IScoreBoard> p_score_board =
    state::score::IScoreBoard::Construct();

  LevelManagerMock level_manager;
  ON_CALL(level_manager, GetCurrentLevel()).WillByDefault(Return(GetParam().level));

  BonusFruitScoreBehaviour behaviour = BonusFruitScoreBehaviour(p_score_board.get(), &level_manager);
  
  UpdatablePlayerEntityMock entity;

  // Call | Assert
  behaviour.Execute(&entity);

  // Assert
  EXPECT_THAT(p_score_board->GetScore(), Eq(GetParam().expected_score));
}


INSTANTIATE_TEST_SUITE_P(BonusFruitScoreBehaviourTest,
                         ExecuteTest,
                         ::testing::ValuesIn(ExecuteTest::GetTestData()));

}
}
}
