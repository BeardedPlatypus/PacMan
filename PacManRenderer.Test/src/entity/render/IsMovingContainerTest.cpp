#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <entity/render/IsMovingContainer.h>

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

TEST(IsMovingContainerTest, IsMoving_CallsCorrectChild) {
  // Setup
  const bool expected_is_moving = true;
  auto dummy = IsMovingDummy(expected_is_moving);

  auto container = IsMovingContainer(dummy);

  // Call
  bool result = container.IsMoving();

  // Assert
  EXPECT_THAT(result, Eq(expected_is_moving));
}

}
}
}
}
