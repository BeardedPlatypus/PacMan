#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <entity/render/StaticValueProvider.h>

using ::testing::Eq;

namespace pacman {
namespace renderer {
namespace entity {
namespace render {

TEST(StaticValueProviderTest, GetFloat_ReturnsExpectedValue) {
  // Setup
  float expected_value = 1.2345F;
  std::unique_ptr<StaticValueProvider<float>> value_provider = std::make_unique<StaticValueProvider<float>>(expected_value);

  // Call
  float result = value_provider->GetValue();

  // Assert
  EXPECT_THAT(result, Eq(expected_value));
}


TEST(StaticValueProviderTest, GetBool_ReturnsExpectedValue) {
  // Setup
  bool expected_value = true;
  std::unique_ptr<StaticValueProvider<bool>> value_provider = std::make_unique<StaticValueProvider<bool>>(expected_value);

  // Call
  bool result = value_provider->GetValue();

  // Assert
  EXPECT_THAT(result, Eq(expected_value));
}


TEST(StaticValueProviderTest, GetString_ReturnsExpectedValue) {
  // Setup
  std::string expected_value = "expected_value";
  std::unique_ptr<StaticValueProvider<std::string>> value_provider = std::make_unique<StaticValueProvider<std::string>>(expected_value);

  // Call
  std::string result = value_provider->GetValue();

  // Assert
  EXPECT_THAT(result, Eq(expected_value));
}

}
}
}
}
