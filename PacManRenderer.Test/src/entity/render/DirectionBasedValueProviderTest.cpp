#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <entity/render/DirectionBasedValueProvider.h>

#include "entity/ISpatialState.h"

using ::testing::Eq;

namespace pacman {
namespace renderer {
namespace entity {
namespace render {

std::unique_ptr<std::unordered_map<state::Direction, std::string, EnumClassHash>> GetTestFilledMapping() {
  auto p_mapping = std::make_unique<std::unordered_map<state::Direction, std::string, EnumClassHash>>();
  (*p_mapping)[state::Direction::Up]    = "Up";
  (*p_mapping)[state::Direction::Left]  = "Left";
  (*p_mapping)[state::Direction::Right] = "Right";
  (*p_mapping)[state::Direction::Down]  = "Down";

  return p_mapping;
}

class GetDirectionTest : public ::testing::TestWithParam<state::Direction> {
public:
  static std::vector<state::Direction> GetTestData() {
    return {
      state::Direction::Up,
      state::Direction::Left,
      state::Direction::Right,
      state::Direction::Down,
    };
  }
};

TEST_P(GetDirectionTest, Filled_ReturnsExpectedLabel) {
  // Setup
  auto p_entity_state = state::ISpatialState::Construct(0.F, 0.F, GetParam(), 0.F);
  auto p_container = std::make_unique<GetDirectionContainer>(*p_entity_state);
  auto p_mapping = GetTestFilledMapping();

  const std::string expected_label = (*p_mapping)[GetParam()];

  auto label_provider = DirectionBasedValueProvider<std::string>(std::move(p_container),
                                                                 "",
                                                                 std::move(p_mapping));

  // Call
  std::string result = label_provider.GetValue();

  // Assert
  EXPECT_THAT(result, Eq(expected_label));
}

INSTANTIATE_TEST_SUITE_P(DirectionBasedValueProviderTest,
                         GetDirectionTest,
                         ::testing::ValuesIn(GetDirectionTest::GetTestData()));


TEST(DirectionBasedValueProviderTest, GetDirection_NotFound_ReturnsDefault) {
  // Setup
  const std::string expected_label = "default_label";
  auto p_entity_state = state::ISpatialState::Construct(0.F, 0.F, state::Direction::Up, 0.F);
  auto p_container = std::make_unique<GetDirectionContainer>(*p_entity_state);
  auto p_mapping = std::make_unique<std::unordered_map<state::Direction, std::string, EnumClassHash>>();

  auto label_provider = DirectionBasedValueProvider<std::string>(std::move(p_container),
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
