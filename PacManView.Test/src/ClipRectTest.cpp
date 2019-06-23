#include <gmock/gmock.h>
#include <gtest/gtest.h>


#include "sprite/ClipRect.h"


#pragma region using_statements
using ::testing::AllOf;
using ::testing::Field;
#pragma endregion


namespace pacman {
namespace view {

// When ClipRect is constructed
// Then the fields are set correctly
TEST(ClipRectTest, WhenAClipRectIsConstructed_ThenTheFieldsAreSetCorrectly) {
  // Given
  const int expected_x = 5;
  const int expected_y = 6;
  const int expected_w = 7;
  const int expected_h = 8;

  // When
  auto result = ClipRect(expected_x,
						 expected_y,
						 expected_w,
						 expected_h);

  // Then
  auto clip_matcher = AllOf(Field(&ClipRect::x, expected_x),
							Field(&ClipRect::y, expected_y),
							Field(&ClipRect::w, expected_w),
							Field(&ClipRect::h, expected_h));

  EXPECT_THAT(result, clip_matcher);
}

}
}