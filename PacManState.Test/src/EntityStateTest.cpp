#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "entity/IEntityState.h"

#pragma region using_statements
using ::testing::Eq;
#pragma endregion

namespace pacman {
namespace state {

TEST(EntityStateTest, ctor_setsExpectedValues) {
  // Given
  float expected_x = 5.403F;
  float expected_y = 1029.0298F;
  Direction expected_dir = Direction::Right;

  // When
  std::unique_ptr<IEntityState> p_state = IEntityState::Construct(expected_x,
                                                                  expected_y,
                                                                  expected_dir);

  // Then
  ASSERT_THAT(p_state->GetXPosition(), Eq(expected_x));
  ASSERT_THAT(p_state->GetYPosition(), Eq(expected_y));
  ASSERT_THAT(p_state->GetDirection(), Eq(expected_dir));
}


TEST(EntityStateTest, SetDirection_ValidDirection) {
  // Given
  Direction expected_dir = Direction::Right;

  std::unique_ptr<IEntityState> p_state = IEntityState::Construct(0.0,
                                                                  0.0,
                                                                  Direction::Left);

  // When
  p_state->SetDirection(expected_dir);

  // Then
  ASSERT_THAT(p_state->GetDirection(), Eq(expected_dir));
}


TEST(EntityStateTest, SetXPosition_ValidFloat) {
  // Given
  float expected_x = 1159.0298F;

  std::unique_ptr<IEntityState> p_state = IEntityState::Construct(0.0,
                                                                  0.0,
                                                                  Direction::Left);

  // When
  p_state->SetXPosition(expected_x);

  // Then
  ASSERT_THAT(p_state->GetXPosition(), Eq(expected_x));
}


TEST(EntityStateTest, SetYPosition_ValidFloat) {
  // Given
  float expected_y = 1159.0298F;

  std::unique_ptr<IEntityState> p_state = IEntityState::Construct(0.0,
                                                                  0.0,
                                                                  Direction::Left);

  // When
  p_state->SetYPosition(expected_y);

  // Then
  ASSERT_THAT(p_state->GetYPosition(), Eq(expected_y));
}


}
}
