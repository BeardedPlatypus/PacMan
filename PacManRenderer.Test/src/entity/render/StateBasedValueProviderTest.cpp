#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <entity/render/StateBasedValueProvider.h>

using ::testing::Eq;

namespace pacman {
namespace renderer {
namespace entity {
namespace render {


enum class DummyEnum {
  StateA,
  StateB,
  StateC,
  StateD,
};


class DummyState {
public:
  explicit DummyState(DummyEnum dummy_state) : 
    _dummy_state(dummy_state) { }

  DummyEnum GetState() const {
    return this->_dummy_state;
  }

private:
  DummyEnum _dummy_state;
};


std::unique_ptr<std::unordered_map<DummyEnum, std::string, EnumClassHash>> GetTestFilledMapping() {
  auto p_mapping = std::make_unique<std::unordered_map<DummyEnum, std::string, EnumClassHash>>();
  (*p_mapping)[DummyEnum::StateA] = "StateA";
  (*p_mapping)[DummyEnum::StateB] = "StateB";
  (*p_mapping)[DummyEnum::StateC] = "StateC";
  (*p_mapping)[DummyEnum::StateD] = "StateD";

  return p_mapping;
}

class GetStateTest : public ::testing::TestWithParam<DummyEnum> {
public:
  static std::vector<DummyEnum> GetTestData() {
    return {
      DummyEnum::StateA,
      DummyEnum::StateB,
      DummyEnum::StateC,
      DummyEnum::StateD,
    };
  }
};

TEST_P(GetStateTest, Filled_ReturnsExpectedLabel) {
  // Setup
  auto dummy_obj = DummyState(GetParam());

  auto p_container = std::make_unique<GetStateContainer<DummyEnum>>(dummy_obj);
  auto p_mapping = GetTestFilledMapping();

  const std::string expected_label = (*p_mapping)[GetParam()];

  auto label_provider = StateBasedValueProvider<DummyEnum, std::string>(std::move(p_container),
                                                                        "",
                                                                        std::move(p_mapping));

  // Call
  std::string result = label_provider.GetValue();

  // Assert
  EXPECT_THAT(result, Eq(expected_label));
}

INSTANTIATE_TEST_SUITE_P(StateBasedValueProviderTest,
                         GetStateTest,
                         ::testing::ValuesIn(GetStateTest::GetTestData()));


TEST(StateBasedValueProviderTest, GetState_NotFound_ReturnsDefault) {
  // Setup
  auto dummy_obj = DummyState(DummyEnum::StateA);
  const std::string expected_label = "default_label";
  auto p_container = std::make_unique<GetStateContainer<DummyEnum>>(dummy_obj);
  auto p_mapping = std::make_unique<std::unordered_map<DummyEnum, std::string, EnumClassHash>>();

  auto label_provider = StateBasedValueProvider<DummyEnum, std::string>(std::move(p_container),
                                                                        expected_label,
                                                                        std::move(p_mapping));

  // Call
  std::string result = label_provider.GetValue();

  // Assert
  EXPECT_THAT(result, Eq(expected_label));
}

}
}
}
}
