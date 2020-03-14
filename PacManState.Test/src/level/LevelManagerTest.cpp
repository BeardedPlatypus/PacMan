#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "level/ILevelManager.h"

#pragma region using_statements
using ::testing::Eq;
#pragma endregion

namespace pacman {
namespace state {
namespace level {

TEST(LevelManagerTest, Constructor_ExpectedResults) {
  // Setup
  const unsigned int expected_n_dots = 30;

  // Call
  auto p_manager = ILevelManager::Construct(expected_n_dots);

  // Assert
  EXPECT_THAT(p_manager->GetCurrentLevel(), Eq(0));
  EXPECT_THAT(p_manager->GetTotalNDots(), Eq(expected_n_dots));
  EXPECT_THAT(p_manager->GetDotsLeftInCurrentLevel(), Eq(expected_n_dots));
  EXPECT_THAT(p_manager->GetDotsConsumedInCurrentLevel(), Eq(0));
}


TEST(LevelManagerTest, IncrementLevel_ExpectedResults) {
  // Setup
  const unsigned int expected_n_dots = 30;
  auto p_manager = ILevelManager::Construct(expected_n_dots);

  p_manager->IncrementDotsConsumedInCurrentLevel();
  unsigned int prev_level = p_manager->GetCurrentLevel();

  // Call
  p_manager->IncrementCurrentLevel();

  // Assert
  EXPECT_THAT(p_manager->GetCurrentLevel(), Eq(prev_level + 1));
  EXPECT_THAT(p_manager->GetDotsConsumedInCurrentLevel(), Eq(0));
  EXPECT_THAT(p_manager->GetDotsLeftInCurrentLevel(), Eq(p_manager->GetTotalNDots()));
}


TEST(LevelManagerTest, IncrementDotsConsumedInCurrentLevel_ExpectedResults) {
  // Setup
  const unsigned int expected_n_dots = 30;
  auto p_manager = ILevelManager::Construct(expected_n_dots);

  // Call
  p_manager->IncrementDotsConsumedInCurrentLevel();

  // Assert
  EXPECT_THAT(p_manager->GetDotsConsumedInCurrentLevel(), Eq(1));
  EXPECT_THAT(p_manager->GetDotsLeftInCurrentLevel(), Eq(expected_n_dots - 1));
}

}
}
}
