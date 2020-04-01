#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "entity/RenderEntity.h"

#include "EntityStateRendererMock.h"
#include "ValueProviderMock.h"

using ::testing::Return;

namespace pacman {
namespace renderer {
namespace entity {

enum class DummyState {
  One,
  Two, 
  Three,
};


std::unique_ptr<IEntityStateRenderer> GetRendererMockWithInitialiseExpectation() {
  std::unique_ptr<EntityStateRendererMock> p_renderer =
    std::make_unique<EntityStateRendererMock>();

  EXPECT_CALL(*p_renderer, Initialise()).Times(1);

  return p_renderer;
}


TEST(RenderEntityTest, Initialise_InitialisesAllStateRenderers) {
  // Setup
  std::unique_ptr<ValueProviderMock<DummyState>> p_state_provider =
    std::make_unique<ValueProviderMock<DummyState>>();
  ON_CALL(*p_state_provider, GetValue()).WillByDefault(Return(DummyState::Two));
  std::unique_ptr<std::unordered_map<DummyState, std::unique_ptr<IEntityStateRenderer>, EnumClassHash>> p_renderers =
    std::make_unique<std::unordered_map<DummyState, std::unique_ptr<IEntityStateRenderer>, EnumClassHash>>();

  p_renderers->insert(std::make_pair(DummyState::One, GetRendererMockWithInitialiseExpectation()));


  RenderEntity<DummyState> render_entity = 
    RenderEntity<DummyState>(std::move(p_renderers), 
                             std::move(p_state_provider));

  // Call | Assert
  render_entity.Initialise();
}


class RenderEntityUpdateTest : public ::testing::TestWithParam<size_t> {
public:
  static std::vector<size_t> GetTestData() {
    return { 1, 2, 3, 4, 5 };
  }
};


TEST_P(RenderEntityUpdateTest, Update_CallsUpdateActiveRenderer) {
  // Setup
  const float expected_dtime = 1.23F;

  std::unique_ptr<ValueProviderMock<DummyState>> p_state_provider =
    std::make_unique<ValueProviderMock<DummyState>>();
  ON_CALL(*p_state_provider, GetValue()).WillByDefault(Return(DummyState::Two));

  std::unique_ptr<EntityStateRendererMock> p_renderer_two =
    std::make_unique<EntityStateRendererMock>();
  EXPECT_CALL(*p_renderer_two, Update(expected_dtime)).Times(GetParam());

  std::unique_ptr<std::unordered_map<DummyState, std::unique_ptr<IEntityStateRenderer>, EnumClassHash>> p_renderers =
    std::make_unique<std::unordered_map<DummyState, std::unique_ptr<IEntityStateRenderer>, EnumClassHash>>();
  
  p_renderers->insert(std::make_pair(DummyState::Two, std::move(p_renderer_two)));

  RenderEntity<DummyState> render_entity = 
    RenderEntity<DummyState>(std::move(p_renderers), 
                             std::move(p_state_provider));

  // Call | Assert
  for (size_t i = 0; i < GetParam(); i++)
    render_entity.Update(expected_dtime);
}


INSTANTIATE_TEST_SUITE_P(RenderEntityTest,
                         RenderEntityUpdateTest,
                         ::testing::ValuesIn(RenderEntityUpdateTest::GetTestData()));


TEST(RenderEntityTest, Update_ActiveStateChanged_CallsResetNewActiveRenderer) {
  // Setup
  const float expected_dtime = 1.23F;

  std::unique_ptr<ValueProviderMock<DummyState>> p_state_provider =
    std::make_unique<ValueProviderMock<DummyState>>();
  EXPECT_CALL(*p_state_provider, GetValue()).WillOnce(Return(DummyState::One))
                                            .WillOnce(Return(DummyState::Two));

  std::unique_ptr<EntityStateRendererMock> p_renderer_two =
    std::make_unique<EntityStateRendererMock>();
  EXPECT_CALL(*p_renderer_two, Reset()).Times(1);
  EXPECT_CALL(*p_renderer_two, Update(expected_dtime)).Times(1);

  std::unique_ptr<std::unordered_map<DummyState, std::unique_ptr<IEntityStateRenderer>, EnumClassHash>> p_renderers =
    std::make_unique<std::unordered_map<DummyState, std::unique_ptr<IEntityStateRenderer>, EnumClassHash>>();
  
  p_renderers->insert(std::make_pair(DummyState::Two, std::move(p_renderer_two)));

  RenderEntity<DummyState> render_entity = 
    RenderEntity<DummyState>(std::move(p_renderers), 
                             std::move(p_state_provider));

  // Call | Assert
  render_entity.Update(expected_dtime);
}


TEST(RenderEntityTest, Render_CallsActiveRenderer) {
  // Setup
  const float expected_scale = 1.23F;
  const float expected_offset = 4.56F;

  std::unique_ptr<ValueProviderMock<DummyState>> p_state_provider =
    std::make_unique<ValueProviderMock<DummyState>>();
  EXPECT_CALL(*p_state_provider, GetValue()).Times(2).WillRepeatedly(Return(DummyState::Two));

  std::unique_ptr<EntityStateRendererMock> p_renderer_two =
    std::make_unique<EntityStateRendererMock>();
  EXPECT_CALL(*p_renderer_two, Render(expected_scale, expected_offset)).Times(1);

  std::unique_ptr<std::unordered_map<DummyState, std::unique_ptr<IEntityStateRenderer>, EnumClassHash>> p_renderers =
    std::make_unique<std::unordered_map<DummyState, std::unique_ptr<IEntityStateRenderer>, EnumClassHash>>();
  
  p_renderers->insert(std::make_pair(DummyState::Two, std::move(p_renderer_two)));


  RenderEntity<DummyState> render_entity = 
    RenderEntity<DummyState>(std::move(p_renderers), 
                             std::move(p_state_provider));

  // Call | Assert
  render_entity.Render(expected_scale, expected_offset);
}

}
}
}
