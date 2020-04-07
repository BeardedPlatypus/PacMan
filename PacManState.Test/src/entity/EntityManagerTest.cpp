#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "entity/IEntityManager.h"

#include "EntityStateMock.h"


namespace pacman {
namespace state {

TEST(EntityManagerTest, GivenAnEntityManagerAndASpatialState_WhenSetPlayerStateIsSet_ThenGetPlayerStateReturnsTheCorrectPointer) {
  // Given
  std::unique_ptr<IEntityState<IPacManBehaviourState>> p_entity_state_mock = 
    std::make_unique<EntityStateMock<IPacManBehaviourState>>();
  auto entity_manager = IEntityManager::Construct();

  IEntityState<IPacManBehaviourState>* expected_pointer = p_entity_state_mock.get();

  // When
  entity_manager->SetPlayerState(std::move(p_entity_state_mock));

  // Then
  EXPECT_EQ(entity_manager->GetPlayerState(), expected_pointer);
}


} // state
} // pacman
