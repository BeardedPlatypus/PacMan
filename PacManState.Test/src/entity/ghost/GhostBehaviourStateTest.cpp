#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "entity/ghost/IGhostBehaviourState.h"

#pragma region using_statements
using ::testing::Eq;
using ::testing::Property;
using ::testing::Pointee;
#pragma endregion


namespace pacman {
namespace state {

TEST(GhostBehaviourStateTest, Constructor_ExpectedResults) {
  // Setup
  GhostStateType expected_state = GhostStateType::Caged;

  // Call
  std::unique_ptr<IGhostBehaviourState> p_result = 
    IGhostBehaviourState::Construct(expected_state);

  // Assert
  EXPECT_THAT(p_result, Pointee(Property(&IGhostBehaviourState::GetState, Eq(expected_state))));
}


TEST(GhostBehaviourStateTest, SetData_ExpectedResults) {
  // Setup
  GhostStateType expected_state = GhostStateType::Edible;

  std::unique_ptr<IGhostBehaviourState> p_result = 
    IGhostBehaviourState::Construct(GhostStateType::Chasing);

  // Call
  p_result->SetState(expected_state);

  // Assert
  EXPECT_THAT(p_result, Pointee(Property(&IGhostBehaviourState::GetState, Eq(expected_state))));

}

}
}
