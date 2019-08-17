#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Position.h"

#pragma region using_statements
using ::testing::Eq;
#pragma endregion

namespace pacman {
namespace state {

TEST(PositionTest, ctor_setsExpectedValues) {
  // Given
  float expected_x = 5.403F;
  float expected_y = 1029.0298F;

  // When
  Position pos = Position(expected_x, expected_y);

  // Then
  ASSERT_THAT(pos.x, Eq(expected_x));
  ASSERT_THAT(pos.y, Eq(expected_y));
}

}
}
