#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <entity/render/IsMovingBasedValueProvider.h>

using ::testing::Eq;

namespace pacman {
namespace renderer {
namespace entity {
namespace render {

class IsMovingDummy {
public:
  explicit IsMovingDummy(bool is_moving) : 
      _is_moving(is_moving) { }

  inline bool IsMoving() const { return this->_is_moving; }
private:
  const bool _is_moving;
};

class IsMovingTest : public ::testing::TestWithParam<bool> {
public:
  static std::vector<bool> GetTestData() {
    return {
      true, false,
    };
  }
};

TEST_P(IsMovingTest, ReturnsExpectedValue) {
  // Setup
  auto dummy = IsMovingDummy(GetParam());
  auto p_container = std::make_unique<IsMovingContainer>(dummy);

  auto provider = IsMovingBasedValueProvider<bool>(std::move(p_container),
                                                   true, 
                                                   false);

  // Call
  bool result = provider.GetValue();

  // Assert
  EXPECT_THAT(result, Eq(GetParam()));
}

INSTANTIATE_TEST_SUITE_P(IsMovingBasedValueProviderTest,
                         IsMovingTest,
                         ::testing::ValuesIn(IsMovingTest::GetTestData()));

}
}
}
}
