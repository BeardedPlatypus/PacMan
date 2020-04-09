#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "entity/IEntityState.h"
#include "SpatialStateMock.h"
#include "entity/player/IPacManBehaviourState.h"

#pragma region using_statements
using ::testing::Eq;
using ::testing::Pointee;
using ::testing::Property;
using ::testing::AllOf;
#pragma endregion

namespace pacman {
namespace state {

TEST(EntityStateTest, Constructor_ExpectedResults) {
  // Setup
  std::unique_ptr<ISpatialState> p_spatial_state =
    std::make_unique<SpatialStateMock>();

  ISpatialState* p_expected_spatial_state =
    p_spatial_state.get();

  std::unique_ptr<IPacManBehaviourState> p_behavioural_state =
    IPacManBehaviourState::Construct(PacManStateType::Dying);

  IPacManBehaviourState* p_expected_behavioural_state =
    p_behavioural_state.get();

  // Call
  std::unique_ptr<IEntityState<IPacManBehaviourState>> p_entity_state =
    IEntityState<IPacManBehaviourState>::Construct(std::move(p_spatial_state),
                                                   std::move(p_behavioural_state));

  // Assert
  EXPECT_THAT(p_entity_state, 
    Pointee(AllOf(
      Property(&IEntityState<IPacManBehaviourState>::GetSpatialState,     Eq(p_expected_spatial_state)),
      Property(&IEntityState<IPacManBehaviourState>::GetBehaviouralState, Eq(p_expected_behavioural_state)))));

}

}
}
