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



class PortalBehaviourExecuteData {
public:
  PortalBehaviourExecuteData(std::unique_ptr<state::IEntityState> p_state,
                             float expected_x,
                             float expected_y) :
      p_state(std::move(p_state)),
      expected_x_location(expected_x),
      expected_y_location(expected_y) { 
    p_entity = IUpdatablePlayerEntity::Construct(this->p_state.get());
  }

  inline IUpdatablePlayerEntity* GetEntity() const { return this->p_entity.get(); }

  inline float GetExpectedXLocation() const { return this->expected_x_location; }
  inline float GetExpectedYLocation() const { return this->expected_y_location; }
private:
  std::unique_ptr<state::IEntityState> p_state;
  std::unique_ptr<IUpdatablePlayerEntity> p_entity;

  float expected_x_location;
  float expected_y_location;
};


std::shared_ptr<PortalBehaviourExecuteData> GetData(float previous_x, 
                                                    float previous_y,
                                                    float current_x,
                                                    float current_y,
                                                    AxisDirection previous_dir,
                                                    AxisDirection current_dir,
                                                    float expected_x,
                                                    float expected_y) {
  auto p_entity_state = state::IEntityState::Construct(previous_x, previous_y, state::Direction::Left, 30.F);
  auto data = std::make_shared<PortalBehaviourExecuteData>(std::move(p_entity_state), expected_x, expected_y);

  data->GetEntity()->GetXAxis()->SetPosition(current_x);
  data->GetEntity()->GetYAxis()->SetPosition(current_y);

  data->GetEntity()->GetActiveAxis()->SetCurrentAxisDirection(current_dir);
  data->GetEntity()->GetActiveAxis()->SetPreviousAxisDirection(previous_dir);

  return data;
}


class PortalBehaviourExecuteTest : public ::testing::TestWithParam<std::shared_ptr<PortalBehaviourExecuteData>> {
public:
  static std::vector<std::shared_ptr<PortalBehaviourExecuteData>> GetTestValues() {
    return {
      GetData(1.F, 1.F, 0.F, 1.F, AxisDirection::Negative, AxisDirection::Negative, 2.F, 2.F),
      GetData(0.F, 1.F, 0.F, 1.F, AxisDirection::Negative, AxisDirection::Positive, 2.F, 2.F),
      GetData(0.F, 1.F, 0.F, 1.F, AxisDirection::Negative, AxisDirection::Negative, 0.F, 1.F),
      GetData(0.F, 0.F, 0.F, 0.F, AxisDirection::Negative, AxisDirection::Negative, 0.F, 0.F),
    };
  }
};


TEST_P(PortalBehaviourExecuteTest, MovesEntityToCorrectLocation) {
  // Given
  std::unique_ptr<state::field::IField> p_field = ConstructTestField();

  auto source_index = p_field->GetFieldIndex(0, 1);
  auto target_index = p_field->GetFieldIndex(2, 2);

  std::unordered_map<int, int> mapping = { 
    { source_index, target_index} 
  };

  auto portal_behaviour = PortalBehaviour(p_field.get(), mapping);

  // When
  portal_behaviour.Execute(GetParam()->GetEntity());

  // Then
  ASSERT_THAT(GetParam()->GetEntity()->GetXAxis()->GetPosition(), 
              Eq(GetParam()->GetExpectedXLocation()));
  ASSERT_THAT(GetParam()->GetEntity()->GetYAxis()->GetPosition(), 
              Eq(GetParam()->GetExpectedYLocation()));
}


INSTANTIATE_TEST_SUITE_P(PortalBehaviourTest,
                         PortalBehaviourExecuteTest,
                         ::testing::ValuesIn(PortalBehaviourExecuteTest::GetTestValues()));


}
}
}
