#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "ui/font/StaticStringRenderData.h"


using ::testing::Eq;


namespace pacman {
namespace renderer {
namespace ui {

TEST(StaticStringRenderDataTest, Constructor_ExpectedValues) {
  // Setup
  std::string expected_string = "expected string";
  float expected_x = 5.4321F;
  float expected_y = 1.2345F;
  float expected_font_scale = 10.333F;
  Justification expected_justification = Justification::Centre;

  // Call
  auto string_data = StaticStringRenderData(expected_string,
                                            expected_x,
                                            expected_y,
                                            expected_font_scale,
                                            expected_justification);

  // Assert
  ASSERT_THAT(string_data.GetString(), Eq(expected_string));
  ASSERT_THAT(string_data.GetX(), Eq(expected_x));
  ASSERT_THAT(string_data.GetY(), Eq(expected_y));
  ASSERT_THAT(string_data.GetFontScale(), Eq(expected_font_scale));
  ASSERT_THAT(string_data.GetJustification(), Eq(expected_justification));
}

}
}
}