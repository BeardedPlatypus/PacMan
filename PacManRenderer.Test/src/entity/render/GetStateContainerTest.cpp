#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <entity/render/GetStateContainer.h>

using ::testing::Eq;

namespace pacman {
namespace renderer {
namespace entity {
namespace render {


enum class DummyStateEnum {
  State1,
  State2,
};


class DummyStateClass {
public:
  explicit DummyStateClass(DummyStateEnum dummy_state) : 
    _dummy_state(dummy_state) { }

  DummyStateEnum GetState() const {
    return this->_dummy_state;
  }

private:
  DummyStateEnum _dummy_state;

};


TEST(GetStateContainerTest, GetState_ExpectedResult) {
  // Setup
  const DummyStateEnum expected_dummy_state = DummyStateEnum::State2;
  auto dummy = DummyStateClass(expected_dummy_state);

  auto container = GetStateContainer<DummyStateEnum>(dummy);

  // Call
  DummyStateEnum result = container.GetState();

  // Assert
  EXPECT_THAT(result, Eq(expected_dummy_state));
}

}
}
}
}
