#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <objects/behaviours/PortalBehaviour.h>

#include <field/IField.h>

using ::testing::Eq;


namespace pacman {
namespace update {
namespace object {

std::unique_ptr<state::field::IField> ConstructTestField() {
  std::vector<std::vector<state::field::TileType>> field_tiles = {
    { state::field::TileType::Space, state::field::TileType::Space, state::field::TileType::Space, },
    { state::field::TileType::Space, state::field::TileType::Space, state::field::TileType::Space, },
    { state::field::TileType::Space, state::field::TileType::Space, state::field::TileType::Space, },
  };

  return state::field::IField::Construct(field_tiles);
}

TEST(PortalBehaviourTest, GivenAPlayerEntity_WhenPortalBehaviourIsExecutedAtAMappedTile_ThenThePlayerIsMoved) {
  // Given
  std::unique_ptr<state::field::IField> p_field = ConstructTestField();

  auto initial_x = 0;
  auto initial_y = 1;

  auto goal_x = 2;
  auto goal_y = 2;
  auto goal_index = p_field->GetFieldIndex(goal_x, goal_y);

  std::unordered_map<int, int> mapping = { 
    { p_field->GetFieldIndex(initial_x, initial_y), goal_index} 
  };

  auto portal_behaviour = PortalBehaviour(p_field.get(), mapping);

  auto p_entity_state = state::IEntityState::Construct(0.F, 1.F, state::Direction::Left, 30.F);
  auto p_entity = IUpdatablePlayerEntity::Construct(p_entity_state.get());

  // When
  portal_behaviour.Execute(p_entity.get(), initial_x, initial_y);

  // Then
  ASSERT_THAT(p_entity_state->GetXAxis()->GetPosition(), Eq(goal_x));
  ASSERT_THAT(p_entity_state->GetYAxis()->GetPosition(), Eq(goal_y));
}


TEST(PortalBehaviourTest, GivenAPlayerEntity_WhenPortalBehaviourIsExecutedAtANonMappedTile_ThenThePlayerIsMoved) {
  // Given
  std::unique_ptr<state::field::IField> p_field = ConstructTestField();

  auto initial_x = 0;
  auto initial_y = 1;

  std::unordered_map<int, int> mapping = { 
    { p_field->GetFieldIndex(2,2), p_field->GetFieldIndex(0,1) } 
  };

  auto portal_behaviour = PortalBehaviour(p_field.get(), mapping);

  auto p_entity_state = state::IEntityState::Construct(0.F, 1.F, state::Direction::Left, 30.F);
  auto p_entity = IUpdatablePlayerEntity::Construct(p_entity_state.get());

  // When
  portal_behaviour.Execute(p_entity.get(), initial_x, initial_y);

  // Then
  ASSERT_THAT(p_entity_state->GetXAxis()->GetPosition(), Eq(initial_x));
  ASSERT_THAT(p_entity_state->GetYAxis()->GetPosition(), Eq(initial_y));
}

}
}
}
