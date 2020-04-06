#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "entity/IPacManBehaviourState.h"

#pragma region using_statements
using ::testing::Eq;
using ::testing::Property;
using ::testing::Pointee;
#pragma endregion


namespace pacman {
namespace state {

TEST(PacManBehaviourStateTest, Constructor_ExpectedResults) {
  // Setup
  PacManStateType expected_state = PacManStateType::Moving;

  // Call
  std::unique_ptr<IPacManBehaviourState> p_result = 
    IPacManBehaviourState::Construct(expected_state);

  // Assert
  EXPECT_THAT(p_result, Pointee(Property(&IPacManBehaviourState::GetState, Eq(expected_state))));
}


TEST(PacManBehaviourStateTest, SetData_ExpectedResults) {
  // Setup
  PacManStateType expected_state = PacManStateType::Dying;

  std::unique_ptr<IPacManBehaviourState> p_result = 
    IPacManBehaviourState::Construct(PacManStateType::Moving);

  // Call
  p_result->SetState(expected_state);

  // Assert
  EXPECT_THAT(p_result, Pointee(Property(&IPacManBehaviourState::GetState, Eq(expected_state))));

}

}
}
