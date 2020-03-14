#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <objects/behaviours/IncrementDotsConsumedBehaviour.h>
#include "LevelManagerMock.h"
#include "UpdatablePlayerEntityMock.h"

using ::testing::Eq;

namespace pacman {
namespace update {
namespace object {

TEST(IncrementDotsConsumedBehaviourTest, Execute_IncrementsScoreBoard) {
  // Setup
  const unsigned int expected_value = 50;

  LevelManagerMock level_manager;
  EXPECT_CALL(level_manager, IncrementDotsConsumedInCurrentLevel()).Times(1);

  IncrementDotsConsumedBehaviour behaviour = IncrementDotsConsumedBehaviour(&level_manager);
  UpdatablePlayerEntityMock entity;

  // Call | Assert
  behaviour.Execute(&entity);
}

}
}
}
