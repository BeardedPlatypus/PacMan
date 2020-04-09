#include <gtest/gtest.h>

#include <entity/IUpdatableEntityAxis.h>
#include <entity/spatial/IEntityAxis.h>

#include "EntityAxisMock.h"

using ::testing::Return;

namespace pacman {
namespace update {

TEST(UpdatableEntityAxisTest, Constructor_ExpectedValues) {
  // Setup
  float position = 12.34F;
  auto p_entity_axis = state::IEntityAxis::Construct(position);

  // Call
  auto p_updatable_entity_axis = IUpdatableEntityAxis::Construct(p_entity_axis.get());

  // Assert
  EXPECT_EQ(p_updatable_entity_axis->GetPosition(), p_entity_axis->GetPosition());
}


struct CurrentIndexValues {
  CurrentIndexValues(float position,
                     int expected_value) : position(position),
                                           expected_value(expected_value) { }

  float position;
  int expected_value;
};


class UpdatableEntityAxisCurrentIndexTest : public ::testing::TestWithParam<CurrentIndexValues> {
public:
  static std::vector<CurrentIndexValues> GetTestValues() {
    std::vector<CurrentIndexValues> result = {
      CurrentIndexValues(10.0F, 10),
      CurrentIndexValues(10.6F, 11),
      CurrentIndexValues(8.3F, 8),
      CurrentIndexValues(8.9F, 9),
    };

    return result;
  }
};


TEST_P(UpdatableEntityAxisCurrentIndexTest, GetCurrentIndex_ReturnsCorrectValue) {
  // Setup
  float position = GetParam().position;
  int expected_value = GetParam().expected_value;

  auto p_entity_axis = state::IEntityAxis::Construct(position);

  // Call
  auto p_updatable_entity_axis = IUpdatableEntityAxis::Construct(p_entity_axis.get());

  // Assert
  EXPECT_EQ(p_updatable_entity_axis->GetCurrentIndex(), expected_value);
}


INSTANTIATE_TEST_SUITE_P(UpdatableEntityAxisTest,
                         UpdatableEntityAxisCurrentIndexTest,
                         ::testing::ValuesIn(UpdatableEntityAxisCurrentIndexTest::GetTestValues()));


class UpdatableEntityAxisAxisDirectionTest : public ::testing::TestWithParam<AxisDirection> {
public:
  static std::vector<AxisDirection> GetTestValues() {
    std::vector<AxisDirection> result = {
      AxisDirection::Negative,
      AxisDirection::Positive,
      AxisDirection::None,
    };

    return result;
  }
};


TEST_P(UpdatableEntityAxisAxisDirectionTest, SetCurrentAxisDirection_SetsCorrectValue) {
  // Setup
  AxisDirection axis_direction = GetParam();
  auto p_entity_axis = state::IEntityAxis::Construct(0.F);
  auto p_updatable_entity_axis = IUpdatableEntityAxis::Construct(p_entity_axis.get());

  // Call
  p_updatable_entity_axis->SetCurrentAxisDirection(axis_direction);

  // Assert
  EXPECT_EQ(p_updatable_entity_axis->GetCurrentAxisDirection(), axis_direction);
}


INSTANTIATE_TEST_SUITE_P(UpdatableEntityAxisTest,
                         UpdatableEntityAxisAxisDirectionTest,
                         ::testing::ValuesIn(UpdatableEntityAxisAxisDirectionTest::GetTestValues()));


struct TileCenterValues {
  TileCenterValues(float position,
                   AxisDirection direction,
                   int expected_value) : position(position),
                                         axis_direction(direction),
                                         expected_value(expected_value) { }

  float position;
  AxisDirection axis_direction;

  int expected_value;
};


class UpdatableEntityAxisNextTileCenterTest : public ::testing::TestWithParam<TileCenterValues> {
public:
  static std::vector<TileCenterValues> GetTestValues() {
    std::vector<TileCenterValues> result = {
      TileCenterValues(10.2F, AxisDirection::Positive, 11),
      TileCenterValues(10.2F, AxisDirection::Negative, 10),
      TileCenterValues( 8.6F, AxisDirection::Positive,  9),
      TileCenterValues( 8.6F, AxisDirection::Negative,  8),
    };

    return result;
  }
};


TEST_P(UpdatableEntityAxisNextTileCenterTest, NextTileCenter_ReturnsCorrectValue) {
  // Setup
  auto test_value = GetParam();

  auto p_entity_axis = state::IEntityAxis::Construct(test_value.position);
  auto p_updatable_entity_axis = IUpdatableEntityAxis::Construct(p_entity_axis.get());

  p_updatable_entity_axis->SetCurrentAxisDirection(test_value.axis_direction);

  // Call
  int result = p_updatable_entity_axis->GetNextTileCenter();

  // Assert
  EXPECT_EQ(result, test_value.expected_value);
}


INSTANTIATE_TEST_SUITE_P(UpdatableEntityAxisTest,
                         UpdatableEntityAxisNextTileCenterTest,
                         ::testing::ValuesIn(UpdatableEntityAxisNextTileCenterTest::GetTestValues()));


class UpdatableEntityAxisPreviousTileCenterTest : public ::testing::TestWithParam<TileCenterValues> {
public:
  static std::vector<TileCenterValues> GetTestValues() {
    std::vector<TileCenterValues> result = {
      TileCenterValues(10.2F, AxisDirection::Positive, 10),
      TileCenterValues(10.2F, AxisDirection::Negative, 11),
      TileCenterValues( 8.6F, AxisDirection::Positive,  8),
      TileCenterValues( 8.6F, AxisDirection::Negative,  9),
    };

    return result;
  }
};


TEST_P(UpdatableEntityAxisPreviousTileCenterTest, PreviousTileCenter_ReturnsCorrectValue) {
  // Setup
  auto test_value = GetParam();

  auto p_entity_axis = state::IEntityAxis::Construct(test_value.position);
  auto p_updatable_entity_axis = IUpdatableEntityAxis::Construct(p_entity_axis.get());

  p_updatable_entity_axis->SetCurrentAxisDirection(test_value.axis_direction);

  // Call
  int result = p_updatable_entity_axis->GetPreviousTileCenter();

  // Assert
  EXPECT_EQ(result, test_value.expected_value);
}


INSTANTIATE_TEST_SUITE_P(UpdatableEntityAxisTest,
                         UpdatableEntityAxisPreviousTileCenterTest,
                         ::testing::ValuesIn(UpdatableEntityAxisPreviousTileCenterTest::GetTestValues()));


struct MoveValues {
  MoveValues(float position,
             float move_distance,
             float expected_value) : position(position),
                                     move_distance(move_distance),
                                     expected_value(expected_value) { }

  float position;
  float move_distance;

  float expected_value;
};


class UpdatableEntityAxisMoveTest : public ::testing::TestWithParam<MoveValues> {
public:
  static std::vector<MoveValues> GetTestValues() {
    std::vector<MoveValues> result = {
      MoveValues(12.4F,  2.F, 14.4F),
      MoveValues(12.4F, -2.F, 10.4F),
      MoveValues(8.6F,  0.5F, 9.1F),
      MoveValues(8.6F, -0.5F, 8.1F),
    };

    return result;
  }
};


TEST_P(UpdatableEntityAxisMoveTest, PreviousTileCenter_ReturnsCorrectValue) {
  // Setup
  auto test_value = GetParam();

  auto p_entity_axis = state::IEntityAxis::Construct(test_value.position);
  auto p_updatable_entity_axis = IUpdatableEntityAxis::Construct(p_entity_axis.get());

  int expected_previous_index = p_updatable_entity_axis->GetCurrentIndex();

  // Call
  p_updatable_entity_axis->Move(test_value.move_distance);

  // Assert
  EXPECT_EQ(p_updatable_entity_axis->GetPosition(), test_value.expected_value);
  EXPECT_EQ(p_updatable_entity_axis->GetPreviousIndex(), expected_previous_index);
}


INSTANTIATE_TEST_SUITE_P(UpdatableEntityAxisTest,
                         UpdatableEntityAxisMoveTest,
                         ::testing::ValuesIn(UpdatableEntityAxisMoveTest::GetTestValues()));


}
}
