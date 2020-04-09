#include <gtest/gtest.h>

#include <entity/spatial/IEntityAxis.h>


namespace pacman {
namespace state {

TEST(EntityAxisTest, Constructor_ExpectedValues) {
  // Setup
  float expectedValue = 123.4F;

  // Call
  auto p_axis = IEntityAxis::Construct(expectedValue);

  // Assert
  EXPECT_EQ(p_axis->GetPosition(), expectedValue);
}


TEST(EntityAxisTest, SetPosition_ExpectedValue) {
  // Setup
  auto p_axis = IEntityAxis::Construct(0.0F);
  float expectedValue = 123.4F;

  // Call
  p_axis->SetPosition(expectedValue);

  // Assert
  EXPECT_EQ(p_axis->GetPosition(), expectedValue);
}


} // state
} // pacman
