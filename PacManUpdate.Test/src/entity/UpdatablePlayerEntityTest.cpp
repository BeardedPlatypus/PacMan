#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <entity/UpdatablePlayerEntity.h>

using ::testing::Eq;

namespace pacman {
namespace update {

inline std::vector<AxisType> GetActiveAxisTypeData() {
  return {
    AxisType::X,
    AxisType::Y,
  };
}

class ActiveAxisTypeTest : public ::testing::TestWithParam<AxisType> { };

TEST_P(ActiveAxisTypeTest, SetActiveAxisType_ExpectedResults) {
  // Setup
  std::unique_ptr<state::IEntityState> p_entity_state = 
    state::IEntityState::Construct(0.F, 0.F, state::Direction::Left, 30.F);

  UpdatablePlayerEntity player_entity = UpdatablePlayerEntity(p_entity_state.get());

  // Call
  player_entity.SetActiveAxisType(GetParam());

  // Assert
  EXPECT_THAT(player_entity.GetActiveAxisType(), Eq(GetParam()));
}

INSTANTIATE_TEST_SUITE_P(UpdatablePlayerEntityTest,
                         ActiveAxisTypeTest,
                         ::testing::ValuesIn(GetActiveAxisTypeData()));

}
}
