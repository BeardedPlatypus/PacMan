#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <entity/render/GetDirectionContainer.h>

#include "entity/spatial/ISpatialState.h"

using ::testing::Eq;

namespace pacman {
namespace renderer {
namespace entity {
namespace render {

TEST(GetDirectionContainerTest, GetDirection_CallsCorrectChild) {
  // Setup
  state::Direction expected_direction = state::Direction::Left;
  auto p_entity_state = state::ISpatialState::Construct(0.F, 0.F, expected_direction, 0.F);

  auto container = GetDirectionContainer(*p_entity_state);

  // Call
  state::Direction result = container.GetDirection();

  // Assert
  EXPECT_THAT(result, Eq(expected_direction));
}

}
}
}
}
