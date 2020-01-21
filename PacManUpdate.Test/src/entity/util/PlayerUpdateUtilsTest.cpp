#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <entity/util/PlayerUpdateUtils.h>

#include "UpdatablePlayerEntityMock.h"
#include "UpdatableEntityAxisMock.h"
#include "PlayerMovementAxisMock.h"
#include "FieldMock.h"

using ::testing::Return;
using ::testing::Eq;


namespace pacman {
namespace update {
namespace util {

class ActiveAxisData {
public:
  ActiveAxisData(AxisDirection current, AxisDirection next, bool expected_result) :
      expected_result(expected_result),
      current_direction(current),
      next_direction(next) {
  }

  const bool expected_result;
  const AxisDirection current_direction;
  const AxisDirection next_direction;
};


class IsActiveTest : public ::testing::TestWithParam<ActiveAxisData> {
public:
  static std::vector<ActiveAxisData> GetTestValues() {
    return {
      ActiveAxisData(AxisDirection::None, AxisDirection::None, false),
      ActiveAxisData(AxisDirection::None, AxisDirection::Negative, true),
      ActiveAxisData(AxisDirection::None, AxisDirection::Positive, true),
      ActiveAxisData(AxisDirection::Negative, AxisDirection::None, true),
      ActiveAxisData(AxisDirection::Negative, AxisDirection::Negative, true),
      ActiveAxisData(AxisDirection::Negative, AxisDirection::Positive, true),
      ActiveAxisData(AxisDirection::Positive, AxisDirection::None, true),
      ActiveAxisData(AxisDirection::Positive, AxisDirection::Negative, true),
      ActiveAxisData(AxisDirection::Positive, AxisDirection::Positive, true),
    };
  }
};


void ConfigureAxisDirectionOnEntityMock(UpdatablePlayerEntityMock& entity_mock,
                                        UpdatableEntityAxisMock& entity_axis_mock,
                                        PlayerMovementAxisMock& movement_axis_mock,
                                        const ActiveAxisData& data) {
  ON_CALL(entity_axis_mock, GetCurrentAxisDirection())
    .WillByDefault(Return(data.current_direction));
  ON_CALL(entity_mock, GetActiveAxis())
    .WillByDefault(Return(&entity_axis_mock));

  ON_CALL(movement_axis_mock, GetNextDirection())
    .WillByDefault(Return(data.next_direction));
  ON_CALL(entity_mock, GetActivePlayerMovementAxis())
    .WillByDefault(Return(&movement_axis_mock));
}


TEST_P(IsActiveTest, ExpectedResults) {
  // Setup
  UpdatablePlayerEntityMock player_entity;
  UpdatableEntityAxisMock entity_axis_mock;
  PlayerMovementAxisMock player_axis_mock;

  ConfigureAxisDirectionOnEntityMock(player_entity, 
                                     entity_axis_mock, 
                                     player_axis_mock, 
                                     GetParam());

  // Call
  bool result = IsActive(&player_entity);

  // Assert
  EXPECT_THAT(result, Eq(GetParam().expected_result));
}


INSTANTIATE_TEST_SUITE_P(PlayerUpdateUtilsTest_IsActive,
                         IsActiveTest,
                         ::testing::ValuesIn(IsActiveTest::GetTestValues()));


class ShouldUpdateDirectionActiveAxisTest : public ::testing::TestWithParam<ActiveAxisData> {
public:
  static std::vector<ActiveAxisData> GetTestValues() {
    return {
      ActiveAxisData(AxisDirection::None,     AxisDirection::None, false),
      ActiveAxisData(AxisDirection::Negative, AxisDirection::None, false),
      ActiveAxisData(AxisDirection::Positive, AxisDirection::None, false),
      ActiveAxisData(AxisDirection::None,     AxisDirection::Positive, true),
      ActiveAxisData(AxisDirection::Negative, AxisDirection::Positive, true),
      ActiveAxisData(AxisDirection::Positive, AxisDirection::Positive, false),
      ActiveAxisData(AxisDirection::None,     AxisDirection::Negative, true),
      ActiveAxisData(AxisDirection::Negative, AxisDirection::Negative, false),
      ActiveAxisData(AxisDirection::Positive, AxisDirection::Negative, true),
    };
  }
};


TEST_P(ShouldUpdateDirectionActiveAxisTest, ExpectedResults) {
  // Setup
  auto data = GetParam();

  UpdatablePlayerEntityMock player_entity;
  UpdatableEntityAxisMock entity_axis_mock;
  PlayerMovementAxisMock player_axis_mock;

  ConfigureAxisDirectionOnEntityMock(player_entity, 
                                     entity_axis_mock, 
                                     player_axis_mock, 
                                     GetParam());

  // Call
  bool result = ShouldUpdateDirectionActiveAxis(&player_entity);

  // Assert
  EXPECT_THAT(result, Eq(data.expected_result));
}


INSTANTIATE_TEST_SUITE_P(PlayerUpdateUtilsTest_ShouldUpdateDirectionActiveAxis,
                         ShouldUpdateDirectionActiveAxisTest,
                         ::testing::ValuesIn(ShouldUpdateDirectionActiveAxisTest::GetTestValues()));


TEST(PlayerUpdateUtilsTest, UpdateDirectionActiveAxis_SetsCorrectValue) {
  // Setup
  UpdatablePlayerEntityMock entity_mock;
  UpdatableEntityAxisMock entity_axis_mock;
  PlayerMovementAxisMock movement_axis_mock;

  ON_CALL(movement_axis_mock, GetNextDirection())
    .WillByDefault(Return(AxisDirection::Positive));
  ON_CALL(entity_mock, GetActivePlayerMovementAxis())
    .WillByDefault(Return(&movement_axis_mock));

  EXPECT_CALL(entity_axis_mock, SetCurrentAxisDirection(AxisDirection::Positive))
    .Times(1);
  ON_CALL(entity_mock, GetActiveAxis())
    .WillByDefault(Return(&entity_axis_mock));

  // Call
  UpdateDirectionActiveAxis(&entity_mock);
}


class GetDirectionValueData {
public:
  GetDirectionValueData(AxisDirection input_direction,
                        int expected_value) : 
      input_direction(input_direction), 
      expected_value(expected_value) {  }

  const AxisDirection input_direction;
  const int expected_value;
};


class GetDirectionValueTest : public ::testing::TestWithParam<GetDirectionValueData> {
public:
  static std::vector<GetDirectionValueData> GetTestValues() {
    return {
      GetDirectionValueData(AxisDirection::Negative, -1),
      GetDirectionValueData(AxisDirection::Positive, +1),
      GetDirectionValueData(AxisDirection::None,      0),
    };
  }
};


TEST_P(GetDirectionValueTest, ExpectedResults) {
  int result = GetDirectionValue(GetParam().input_direction);
  EXPECT_THAT(result, Eq(GetParam().expected_value));
}


INSTANTIATE_TEST_SUITE_P(PlayerUpdateUtilsTest_GetDirectionValue,
                         GetDirectionValueTest,
                         ::testing::ValuesIn(GetDirectionValueTest::GetTestValues()));


class HasOtherDirectionData {
public:
  HasOtherDirectionData(AxisDirection input_direction, 
                        bool expected_value) :
      input_direction(input_direction),
      expected_value(expected_value) {
  }

  const AxisDirection input_direction;
  const bool expected_value;
};


class HasOtherDirectionTest : public ::testing::TestWithParam<HasOtherDirectionData> {
public:
  static std::vector<HasOtherDirectionData> GetTestValues() {
    return {
      HasOtherDirectionData(AxisDirection::Positive, true),
      HasOtherDirectionData(AxisDirection::Negative, true),
      HasOtherDirectionData(AxisDirection::None, false),
    };
  }
};


TEST_P(HasOtherDirectionTest, ExpectedResults) {
  // Setup
  UpdatablePlayerEntityMock entity_mock;
  PlayerMovementAxisMock movement_axis_mock;

  ON_CALL(movement_axis_mock, GetNextDirection())
    .WillByDefault(Return(GetParam().input_direction));
  ON_CALL(entity_mock, GetInactivePlayerMovementAxis())
    .WillByDefault(Return(&movement_axis_mock));

  // Call
  bool result = HasOtherDirection(&entity_mock);

  // Assert
  EXPECT_THAT(result, Eq(GetParam().expected_value));
}


INSTANTIATE_TEST_SUITE_P(PlayerUpdateUtilsTest_HasOtherDirectiontest,
                         HasOtherDirectionTest,
                         ::testing::ValuesIn(HasOtherDirectionTest::GetTestValues()));


class GetDistanceData {
public:
  GetDistanceData(float current_position,
                  int tile_position,
                  float expected_result) :
      current_position(current_position),
      tile_position(tile_position),
      expected_result(expected_result) { }

  const float current_position;
  const int tile_position;
  const float expected_result;
};


class GetDistanceToTileCenterTest : public ::testing::TestWithParam<GetDistanceData> {
public:
  static std::vector<GetDistanceData> GetTestValues() {
    return {
      GetDistanceData(0.F, 0, 0.F),
      GetDistanceData(0.5F, 0, 0.5F),
      GetDistanceData(1.5F, 1, 0.5F),
      GetDistanceData(-0.5F, 0, 0.5F),
      GetDistanceData(-1.5F, -1, 0.5F),
    };
  }
};


TEST_P(GetDistanceToTileCenterTest, NextTileCenter_ExpectedResults) {
  // Setup
  UpdatablePlayerEntityMock entity_mock;
  UpdatableEntityAxisMock entity_axis_mock;

  ON_CALL(entity_axis_mock, GetPosition())
    .WillByDefault(Return(GetParam().current_position));
  ON_CALL(entity_axis_mock, GetNextTileCenter())
    .WillByDefault(Return(GetParam().tile_position));

  ON_CALL(entity_mock, GetActiveAxis())
    .WillByDefault(Return(&entity_axis_mock));

  // Call
  float result = GetDistanceToNextCenter(&entity_mock);

  // Assert
  EXPECT_THAT(result, Eq(GetParam().expected_result));
}


TEST_P(GetDistanceToTileCenterTest, PreviousTileCenter_ExpectedResults) {
  // Setup
  UpdatablePlayerEntityMock entity_mock;
  UpdatableEntityAxisMock entity_axis_mock;

  ON_CALL(entity_axis_mock, GetPosition())
    .WillByDefault(Return(GetParam().current_position));
  ON_CALL(entity_axis_mock, GetPreviousTileCenter())
    .WillByDefault(Return(GetParam().tile_position));

  ON_CALL(entity_mock, GetActiveAxis())
    .WillByDefault(Return(&entity_axis_mock));

  // Call
  float result = GetDistanceToPreviousCenter(&entity_mock);

  // Assert
  EXPECT_THAT(result, Eq(GetParam().expected_result));
}


INSTANTIATE_TEST_SUITE_P(PlayerUpdateUtilsTest_DistanceCenter,
                         GetDistanceToTileCenterTest,
                         ::testing::ValuesIn(GetDistanceToTileCenterTest::GetTestValues()));


class CanMoveToPositionData {
public:
  CanMoveToPositionData(state::field::TileType tile_type,
                        bool expected_result) : 
      tile_type(tile_type),
      expected_result(expected_result) { }

  const state::field::TileType tile_type;
  const bool expected_result;
};


class CanMoveToPositionTest : public ::testing::TestWithParam<CanMoveToPositionData> {
public:
  static std::vector<CanMoveToPositionData> GetTestValues() {
    return {
      CanMoveToPositionData(state::field::TileType::Gate,        false),
      CanMoveToPositionData(state::field::TileType::OutOfBounds, false),
      CanMoveToPositionData(state::field::TileType::Solid,       false),
      CanMoveToPositionData(state::field::TileType::Space,       true),
    };
  }
};


TEST_P(CanMoveToPositionTest, ExpectedResults) {
  // Setup
  const int x = 3;
  const int y = 5;

  FieldMock field;
  EXPECT_CALL(field, GetTileType(x, y)).Times(1).WillOnce(Return(GetParam().tile_type));

  // Call
  bool result = CanMoveToPosition(&field, x, y);

  EXPECT_THAT(result, Eq(GetParam().expected_result));
}


INSTANTIATE_TEST_SUITE_P(PlayerUpdateUtilsTest_CanMoveToPosition,
                         CanMoveToPositionTest,
                         ::testing::ValuesIn(CanMoveToPositionTest::GetTestValues()));

}
}
}
