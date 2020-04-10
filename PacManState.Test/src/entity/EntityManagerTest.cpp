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


TEST(EntityManagerTest, SetBlinkyState_ExpectedResults) {
  // Given
  std::unique_ptr<IEntityState<IGhostBehaviourState>> p_entity_state_mock = 
    std::make_unique<EntityStateMock<IGhostBehaviourState>>();
  auto entity_manager = IEntityManager::Construct();

  IEntityState<IGhostBehaviourState>* expected_pointer = p_entity_state_mock.get();

  // When
  entity_manager->SetBlinkyState(std::move(p_entity_state_mock));

  // Then
  EXPECT_EQ(entity_manager->GetBlinkyState(), expected_pointer);
}


TEST(EntityManagerTest, SetPinkyState_ExpectedResults) {
  // Given
  std::unique_ptr<IEntityState<IGhostBehaviourState>> p_entity_state_mock = 
    std::make_unique<EntityStateMock<IGhostBehaviourState>>();
  auto entity_manager = IEntityManager::Construct();

  IEntityState<IGhostBehaviourState>* expected_pointer = p_entity_state_mock.get();

  // When
  entity_manager->SetPinkyState(std::move(p_entity_state_mock));

  // Then
  EXPECT_EQ(entity_manager->GetPinkyState(), expected_pointer);
}


TEST(EntityManagerTest, SetInkyState_ExpectedResults) {
  // Given
  std::unique_ptr<IEntityState<IGhostBehaviourState>> p_entity_state_mock = 
    std::make_unique<EntityStateMock<IGhostBehaviourState>>();
  auto entity_manager = IEntityManager::Construct();

  IEntityState<IGhostBehaviourState>* expected_pointer = p_entity_state_mock.get();

  // When
  entity_manager->SetInkyState(std::move(p_entity_state_mock));

  // Then
  EXPECT_EQ(entity_manager->GetInkyState(), expected_pointer);
}


TEST(EntityManagerTest, SetClydeState_ExpectedResults) {
  // Given
  std::unique_ptr<IEntityState<IGhostBehaviourState>> p_entity_state_mock = 
    std::make_unique<EntityStateMock<IGhostBehaviourState>>();
  auto entity_manager = IEntityManager::Construct();

  IEntityState<IGhostBehaviourState>* expected_pointer = p_entity_state_mock.get();

  // When
  entity_manager->SetClydeState(std::move(p_entity_state_mock));

  // Then
  EXPECT_EQ(entity_manager->GetClydeState(), expected_pointer);
}


} // state
} // pacman
