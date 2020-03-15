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


TEST(UpdatablePlayerEntityTest, Update_CallsMovementAxii) {
  // Setup
  const float expected_dt = 0.12345F;

  EntityStateMock entity_state;
  
  std::unique_ptr<PlayerMovementAxisMock> p_x_axis = std::make_unique<PlayerMovementAxisMock>();
  EXPECT_CALL(*p_x_axis, Update(expected_dt)).Times(1);

  std::unique_ptr<PlayerMovementAxisMock> p_y_axis = std::make_unique<PlayerMovementAxisMock>();
  EXPECT_CALL(*p_y_axis, Update(expected_dt)).Times(1);

  UpdatablePlayerEntity player_entity = UpdatablePlayerEntity(&entity_state,
                                                              std::make_unique<UpdatableEntityAxisMock>(),
                                                              std::make_unique<UpdatableEntityAxisMock>(),
                                                              std::move(p_x_axis),
                                                              std::move(p_y_axis));

  // Call
  player_entity.Update(expected_dt);
}


TEST(UpdatablePlayerEntityTest, SetIsMoving_WrapsEntityState) {
  // Setup
  bool expected_is_moving = true;
  EntityStateMock entity_state;
  EXPECT_CALL(entity_state, SetIsMoving(expected_is_moving)).Times(1);

  UpdatablePlayerEntity player_entity = UpdatablePlayerEntity(&entity_state, 
                                                              std::make_unique<UpdatableEntityAxisMock>(), 
                                                              std::make_unique<UpdatableEntityAxisMock>(), 
                                                              std::make_unique<PlayerMovementAxisMock>(),
                                                              std::make_unique<PlayerMovementAxisMock>());

  // Call
  player_entity.SetIsMoving(expected_is_moving);
}


TEST(UpdatablePlayerEntityTest, Reset_WrapsEntityState) {
  // Setup
  EntityStateMock entity_state;
  EXPECT_CALL(entity_state, Reset()).Times(1);

  std::unique_ptr<UpdatableEntityAxisMock> p_x_axis_mock = std::make_unique<UpdatableEntityAxisMock>();
  EXPECT_CALL(*(p_x_axis_mock.get()), SetCurrentAxisDirection(AxisDirection::None)).Times(1);

  std::unique_ptr<UpdatableEntityAxisMock> p_y_axis_mock = std::make_unique<UpdatableEntityAxisMock>();
  EXPECT_CALL(*(p_y_axis_mock.get()), SetCurrentAxisDirection(AxisDirection::None)).Times(1);

  std::unique_ptr<PlayerMovementAxisMock> p_x_movement_axis_mock = std::make_unique<PlayerMovementAxisMock>();
  EXPECT_CALL(*(p_x_movement_axis_mock.get()), ChangeState(state_machine::PlayerControlEvent::Reset)).Times(1);

  std::unique_ptr<PlayerMovementAxisMock> p_y_movement_axis_mock = std::make_unique<PlayerMovementAxisMock>();
  EXPECT_CALL(*(p_y_movement_axis_mock.get()), ChangeState(state_machine::PlayerControlEvent::Reset)).Times(1);

  UpdatablePlayerEntity player_entity = UpdatablePlayerEntity(&entity_state,
                                                              std::move(p_x_axis_mock),
                                                              std::move(p_y_axis_mock),
                                                              std::move(p_x_movement_axis_mock),
                                                              std::move(p_y_movement_axis_mock));

  // Call
  player_entity.Reset();

  // Assert
  EXPECT_THAT(player_entity.GetActiveAxisType(), Eq(AxisType::X));
}

}
}
