#include "EntityStateMock.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "entity/IEntityManager.h"


namespace pacman {
namespace state {

TEST(EntityManagerTest, GivenAnEntityManagerAndAEntityState_WhenSetPlayerStateIsSet_ThenGetPlayerStateReturnsTheCorrectPointer) {
  // Given
  std::unique_ptr<IEntityState> p_entity_state_mock = 
    std::make_unique<EntityStateMock>();
  auto entity_manager = IEntityManager::Construct();

  IEntityState* expected_pointer = p_entity_state_mock.get();

  // When
  entity_manager->SetPlayerState(std::move(p_entity_state_mock));

  // Then
  EXPECT_EQ(entity_manager->GetPlayerState(), expected_pointer);
}


} // state
} // pacman
