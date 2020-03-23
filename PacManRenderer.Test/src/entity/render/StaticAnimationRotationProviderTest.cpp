#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <entity/render/StaticAnimationRotationProvider.h>

using ::testing::Eq;

namespace pacman {
namespace renderer {
namespace entity {
namespace render {

TEST(StaticAnimationRotationProviderTest, GetRotation_ReturnsStaticValue) {
  // Setup
  float expected_value = 1.2345F;
  StaticAnimationRotationProvider rotation_provider = StaticAnimationRotationProvider(expected_value);

  // Call
  float result = rotation_provider.GetRotation();

  // Assert
  EXPECT_THAT(result, Eq(expected_value));
}

}
}
}
}
