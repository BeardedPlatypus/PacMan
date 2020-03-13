#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <entity/UpdatablePlayerEntity.h>

#include "EntityStateMock.h"
#include "UpdatableEntityAxisMock.h"
#include "PlayerMovementAxisMock.h"

using ::testing::Eq;
using ::testing::Return;

namespace pacman {
namespace update {

inline std::vector<AxisType> GetActiveAxisTypeData() {
  return {
    AxisType::X,
    AxisType::Y,
  };
}

class ActiveAxisTypeTest : public ::testing::TestWithParam<AxisType> { };

TEST_P(ActiveAxisTypeTest, SetActiveAxisType_ExpectedResults) {
  // Setup
  EntityStateMock entity_state;

  UpdatablePlayerEntity player_entity = UpdatablePlayerEntity(&entity_state, 
                                                              std::make_unique<UpdatableEntityAxisMock>(), 
                                                              std::make_unique<UpdatableEntityAxisMock>(), 
                                                              std::make_unique<PlayerMovementAxisMock>(),
                                                              std::make_unique<PlayerMovementAxisMock>());

  // Call
  player_entity.SetActiveAxisType(GetParam());

  // Assert
  EXPECT_THAT(player_entity.GetActiveAxisType(), Eq(GetParam()));
}

INSTANTIATE_TEST_SUITE_P(UpdatablePlayerEntityTest,
                         ActiveAxisTypeTest,
                         ::testing::ValuesIn(GetActiveAxisTypeData()));


TEST(UpdatablePlayerEntityTest, GetSpeed_ExpectedResults) {
  // Setup
  const float expected_speed = 30.124F;

  EntityStateMock entity_state;
  EXPECT_CALL(entity_state, GetSpeed()).Times(1).WillOnce(Return(expected_speed));

  UpdatablePlayerEntity player_entity = UpdatablePlayerEntity(&entity_state, 
                                                              std::make_unique<UpdatableEntityAxisMock>(), 
                                                              std::make_unique<UpdatableEntityAxisMock>(), 
                                                              std::make_unique<PlayerMovementAxisMock>(),
                                                              std::make_unique<PlayerMovementAxisMock>());

  // Call
  float result = player_entity.GetSpeed();

  // Assert
  EXPECT_THAT(result, Eq(expected_speed));
}


TEST(UpdatablePlayerEntityTest, ActiveAxis_Consistent) {
  // Setup
  EntityStateMock entity_state;

  UpdatablePlayerEntity player_entity = UpdatablePlayerEntity(&entity_state, 
                                                              std::make_unique<UpdatableEntityAxisMock>(), 
                                                              std::make_unique<UpdatableEntityAxisMock>(), 
                                                              std::make_unique<PlayerMovementAxisMock>(),
                                                              std::make_unique<PlayerMovementAxisMock>());


  // Call
  AxisType active_axis_type = player_entity.GetActiveAxisType();

  // Assert
  IUpdatableEntityAxis* active_axis;

  IPlayerMovementAxis* active_movement_axis;
  IPlayerMovementAxis* inactive_movement_axis;
  if (active_axis_type == AxisType::X) {
    active_axis = player_entity.GetXAxis();
    active_movement_axis = player_entity.GetPlayerMovementXAxis();
    inactive_movement_axis = player_entity.GetPlayerMovementYAxis();
  }
  else {
    active_axis = player_entity.GetYAxis();
    active_movement_axis = player_entity.GetPlayerMovementYAxis();
    inactive_movement_axis = player_entity.GetPlayerMovementXAxis();
  }

  EXPECT_THAT(player_entity.GetActiveAxis(), Eq(active_axis));
  EXPECT_THAT(player_entity.GetActivePlayerMovementAxis(), Eq(active_movement_axis));
  EXPECT_THAT(player_entity.GetInactivePlayerMovementAxis(), Eq(inactive_movement_axis));
}


TEST(UpdatablePlayerEntityTest, SwapActiveAxis_ExpectedResults) {
  // Setup
  EntityStateMock entity_state;

  UpdatablePlayerEntity player_entity = UpdatablePlayerEntity(&entity_state, 
                                                              std::make_unique<UpdatableEntityAxisMock>(), 
                                                              std::make_unique<UpdatableEntityAxisMock>(), 
                                                              std::make_unique<PlayerMovementAxisMock>(),
                                                              std::make_unique<PlayerMovementAxisMock>());

  AxisType prev_inactive_axis_type = player_entity.GetActiveAxisType() == AxisType::X ? AxisType::Y : AxisType::X;

  // Call
  player_entity.SwapActiveAxis();

  // Assert
  EXPECT_THAT(player_entity.GetActiveAxisType(), Eq(prev_inactive_axis_type));
}


TEST(UpdatablePlayerEntityTest, GetMovingDirection_WrapsEntityState) {
  // Setup
  state::Direction expected_direction = state::Direction::Down;
  EntityStateMock entity_state;
  EXPECT_CALL(entity_state, GetDirection()).Times(1).WillOnce(Return(expected_direction));

  UpdatablePlayerEntity player_entity = UpdatablePlayerEntity(&entity_state, 
                                                              std::make_unique<UpdatableEntityAxisMock>(), 
                                                              std::make_unique<UpdatableEntityAxisMock>(), 
                                                              std::make_unique<PlayerMovementAxisMock>(),
                                                              std::make_unique<PlayerMovementAxisMock>());

  // Call
  state::Direction result = player_entity.GetMovingDirection();

  // Assert
  EXPECT_THAT(result, Eq(expected_direction));
}


TEST(UpdatablePlayerEntityTest, SetMovingDirection_WrapsEntityState) {
  // Setup
  state::Direction expected_direction = state::Direction::Down;
  EntityStateMock entity_state;
  EXPECT_CALL(entity_state, SetDirection(expected_direction)).Times(1);

  UpdatablePlayerEntity player_entity = UpdatablePlayerEntity(&entity_state, 
                                                              std::make_unique<UpdatableEntityAxisMock>(), 
                                                              std::make_unique<UpdatableEntityAxisMock>(), 
                                                              std::make_unique<PlayerMovementAxisMock>(),
                                                              std::make_unique<PlayerMovementAxisMock>());

  // Call
  player_entity.SetMovingDirection(expected_direction);
}


}
}