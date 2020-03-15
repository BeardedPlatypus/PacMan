#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "entity/IEntityState.h"

#pragma region using_statements
using ::testing::Eq;
using ::testing::IsFalse;
using ::testing::IsTrue;
#pragma endregion

namespace pacman {
namespace state {

TEST(EntityStateTest, ctor_setsExpectedValues) {
  // Given
  float expected_x = 5.403F;
  float expected_y = 1029.0298F;
  Direction expected_dir = Direction::Right;
  float expected_speed = 20.326F;

  // When
  std::unique_ptr<IEntityState> p_state = IEntityState::Construct(expected_x,
                                                                  expected_y,
                                                                  expected_dir, 
                                                                  expected_speed);

  // Then
  ASSERT_THAT(p_state->GetXAxis()->GetPosition(), Eq(expected_x));
  ASSERT_THAT(p_state->GetYAxis()->GetPosition(), Eq(expected_y));
  ASSERT_THAT(p_state->GetDirection(), Eq(expected_dir));
  ASSERT_THAT(p_state->GetSpeed(), Eq(expected_speed));
  ASSERT_THAT(p_state->IsMoving(), IsFalse());
}


TEST(EntityStateTest, SetDirection_ValidDirection) {
  // Given
  Direction expected_dir = Direction::Right;

  std::unique_ptr<IEntityState> p_state = IEntityState::Construct(0.F,
                                                                  0.F,
                                                                  Direction::Left, 
                                                                  0.F);

  // When
  p_state->SetDirection(expected_dir);

  // Then
  ASSERT_THAT(p_state->GetDirection(), Eq(expected_dir));
}


TEST(EntityStateTest, SetXPosition_ValidFloat) {
  // Given
  float expected_x = 1159.0298F;

  std::unique_ptr<IEntityState> p_state = IEntityState::Construct(0.F,
                                                                  0.F,
                                                                  Direction::Left,
                                                                  0.F);

  // When
  p_state->GetXAxis()->SetPosition(expected_x);

  // Then
  ASSERT_THAT(p_state->GetXAxis()->GetPosition(), Eq(expected_x));
}


TEST(EntityStateTest, SetYPosition_ValidFloat) {
  // Given
  float expected_y = 1159.0298F;

  std::unique_ptr<IEntityState> p_state = IEntityState::Construct(0.F,
                                                                  0.F,
                                                                  Direction::Left,
                                                                  0.F);

  // When
  p_state->GetYAxis()->SetPosition(expected_y);

  // Then
  ASSERT_THAT(p_state->GetYAxis()->GetPosition(), Eq(expected_y));
}


TEST(EntityStateTest, SetSpeed_UpdatesCorrectly) {
  // Setup
  std::unique_ptr<IEntityState> p_state = IEntityState::Construct(0.F,
                                                                  0.F,
                                                                  Direction::Left,
                                                                  0.F);

  float expected_new_speed = 50.F;

  // Call
  p_state->SetSpeed(expected_new_speed);

  // Assert
  EXPECT_THAT(p_state->GetSpeed(), Eq(expected_new_speed));
}


TEST(EntityStateTest, SetIsMoving_UpdatesCorrectly) {
  // Setup
  std::unique_ptr<IEntityState> p_state = IEntityState::Construct(0.F,
                                                                  0.F,
                                                                  Direction::Left,
                                                                  0.F);

  // Call
  p_state->SetIsMoving(true);

  // Assert
  EXPECT_THAT(p_state->IsMoving(), IsTrue());
}


TEST(EntityStateTest, Reset_SetsExpectedValues) {
  // Given
  float expected_x = 5.403F;
  float expected_y = 1029.0298F;
  Direction expected_dir = Direction::Right;
  float expected_speed = 20.326F;

  std::unique_ptr<IEntityState> p_state = IEntityState::Construct(expected_x,
                                                                  expected_y,
                                                                  expected_dir, 
                                                                  expected_speed);
  p_state->SetSpeed(5.F);
  p_state->SetDirection(Direction::Down);
  p_state->GetXAxis()->SetPosition(0.F);
  p_state->GetYAxis()->SetPosition(0.F);
  p_state->SetIsMoving(true);

  // When
  p_state->Reset();

  // Then
  ASSERT_THAT(p_state->GetXAxis()->GetPosition(), Eq(expected_x));
  ASSERT_THAT(p_state->GetYAxis()->GetPosition(), Eq(expected_y));
  ASSERT_THAT(p_state->GetDirection(), Eq(expected_dir));
  ASSERT_THAT(p_state->GetSpeed(), Eq(expected_speed));
  ASSERT_THAT(p_state->IsMoving(), IsFalse());
}



}
}
