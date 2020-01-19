#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <entity/util/PlayerUpdateUtils.h>

#include "UpdatablePlayerEntityMock.h"
#include "UpdatableEntityAxisMock.h"
#include "PlayerMovementAxisMock.h"

using ::testing::Return;
using ::testing::Eq;


namespace pacman {
namespace update {
namespace util {

class IsActiveData {
public:
  IsActiveData(AxisDirection current, AxisDirection next, bool expected_result) :
      expected_result(expected_result),
      current_direction(current),
      next_direction(next) {
  }

  const bool expected_result;
  const AxisDirection current_direction;
  const AxisDirection next_direction;
};


class IsActiveTest : public ::testing::TestWithParam<IsActiveData> {
public:
  static std::vector<IsActiveData> GetTestValues() {
    return {
      IsActiveData(AxisDirection::None, AxisDirection::None, false),
      IsActiveData(AxisDirection::None, AxisDirection::Negative, true),
      IsActiveData(AxisDirection::None, AxisDirection::Positive, true),
      IsActiveData(AxisDirection::Negative, AxisDirection::None, true),
      IsActiveData(AxisDirection::Negative, AxisDirection::Negative, true),
      IsActiveData(AxisDirection::Negative, AxisDirection::Positive, true),
      IsActiveData(AxisDirection::Positive, AxisDirection::None, true),
      IsActiveData(AxisDirection::Positive, AxisDirection::Negative, true),
      IsActiveData(AxisDirection::Positive, AxisDirection::Positive, true),
    };
  }
};


TEST_P(IsActiveTest, ExpectedResults) {
  // Setup
  auto data = GetParam();

  UpdatablePlayerEntityMock player_entity;
  UpdatableEntityAxisMock entity_axis_mock;
  PlayerMovementAxisMock player_axis_mock;

  ON_CALL(entity_axis_mock, GetCurrentAxisDirection())
    .WillByDefault(Return(data.current_direction));
  ON_CALL(player_entity, GetActiveAxis())
    .WillByDefault(Return(&entity_axis_mock));

  ON_CALL(player_axis_mock, GetNextDirection())
    .WillByDefault(Return(data.next_direction));
  ON_CALL(player_entity, GetActivePlayerMovementAxis())
    .WillByDefault(Return(&player_axis_mock));

  // Call
  bool result = IsActive(&player_entity);

  // Assert
  EXPECT_THAT(result, Eq(data.expected_result));
}


INSTANTIATE_TEST_SUITE_P(PlayerUpdateUtilsTest_IsActive,
                         IsActiveTest,
                         ::testing::ValuesIn(IsActiveTest::GetTestValues()));


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


TEST_P(GetDirectionValueTest, Expected_Results) {
  int result = GetDirectionValue(GetParam().input_direction);
  EXPECT_THAT(result, Eq(GetParam().expected_value));
}


INSTANTIATE_TEST_SUITE_P(PlayerUpdateUtilsTest_GetDirectionValue,
                         GetDirectionValueTest,
                         ::testing::ValuesIn(GetDirectionValueTest::GetTestValues()));



}
}
}
