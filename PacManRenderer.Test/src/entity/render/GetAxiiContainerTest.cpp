
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <entity/render/GetAxiiContainer.h>

#include "entity/IEntityState.h"

using ::testing::Eq;

namespace pacman {
namespace renderer {
namespace entity {
namespace render {

TEST(GetAxiiContainerTest, GetXAxis_CallsCorrectContainedObject) {
  // Setup
  auto p_entity_state = state::IEntityState::Construct(0.F, 0.F, state::Direction::Left, 0.F);
  state::IEntityAxis* expected_pointer = p_entity_state->GetXAxis();

  auto container = GetAxiiContainer(*p_entity_state);

  // Call
  const state::IEntityAxis* p_result = container.GetXAxis();

  // Assert
  EXPECT_THAT(p_result, Eq(expected_pointer));
}

TEST(GetAxiiContainerTest, GetYAxis_CallsCorrectContainedObject) {
  // Setup
  auto p_entity_state = state::IEntityState::Construct(0.F, 0.F, state::Direction::Left, 0.F);
  state::IEntityAxis* expected_pointer = p_entity_state->GetYAxis();

  auto container = GetAxiiContainer(*p_entity_state);

  // Call
  const state::IEntityAxis* p_result = container.GetYAxis();

  // Assert
  EXPECT_THAT(p_result, Eq(expected_pointer));
}


}
}
}
}
