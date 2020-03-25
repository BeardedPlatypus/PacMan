#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "entity/RenderEntity.h"

#include "ViewAPIMock.h"
#include "ValueProviderMock.h"
#include "AnimationPositionProviderMock.h"

using ::testing::Return;

namespace pacman {
namespace renderer {
namespace entity {

TEST(RenderEntityTest, Render_ExpectedResults) {
  // Setup
  const std::string expected_label = "label";
  std::shared_ptr<ValueProviderMock<std::string>> p_label_provider =
    std::make_shared<ValueProviderMock<std::string>>();
  EXPECT_CALL(*p_label_provider, GetValue())
    .Times(1)
    .WillOnce(Return(expected_label));

  const float expected_scale = 7.89F;
  const float expected_render_offset = 10.1112F;

  const float expected_x = 1.23F;
  const float expected_y = 4.56F;
  std::shared_ptr<AnimationPositionProviderMock> p_position_provider =
    std::make_shared<AnimationPositionProviderMock>();
  EXPECT_CALL(*p_position_provider, GetXPosition(expected_scale))
    .Times(1)
    .WillOnce(Return(expected_x));
  EXPECT_CALL(*p_position_provider, GetYPosition(expected_scale, expected_render_offset))
    .Times(1)
    .WillOnce(Return(expected_y));

  const float expected_scale_factor = 1.35F;
  std::shared_ptr<ValueProviderMock<float>> p_scale_factor_provider =
    std::make_shared<ValueProviderMock<float>>();
  EXPECT_CALL(*p_scale_factor_provider, GetValue())
    .Times(1)
    .WillOnce(Return(expected_scale_factor));

  const float expected_rotation = 2.46F;
  std::shared_ptr<ValueProviderMock<float>> p_rotation_provider =
    std::make_shared<ValueProviderMock<float>>();
  EXPECT_CALL(*p_rotation_provider, GetValue())
    .Times(1)
    .WillOnce(Return(expected_rotation));

  const bool expected_flip_horizontal = true;
  std::shared_ptr<ValueProviderMock<bool>> p_flip_horizontally_provider =
    std::make_shared<ValueProviderMock<bool>>();
  EXPECT_CALL(*p_flip_horizontally_provider, GetValue())
    .Times(1)
    .WillOnce(Return(expected_flip_horizontal));

  const bool expected_flip_vertical = false;
  std::shared_ptr<ValueProviderMock<bool>> p_flip_vertical_provider =
    std::make_shared<ValueProviderMock<bool>>();
  EXPECT_CALL(*p_flip_vertical_provider, GetValue())
    .Times(1)
    .WillOnce(Return(expected_flip_vertical));

  std::unique_ptr<entity::render::EntityRenderConfig> p_render_config =
    std::make_unique<entity::render::EntityRenderConfig>(p_label_provider,
                                                         p_position_provider,
                                                         p_scale_factor_provider,
                                                         p_rotation_provider,
                                                         p_flip_horizontally_provider,
                                                         p_flip_vertical_provider);

  ViewAPIMock view_api;
  EXPECT_CALL(view_api, RenderSpriteAnimation(expected_label,
    expected_x,
    expected_y,
    expected_scale_factor * expected_scale,
    expected_rotation,
    expected_flip_horizontal,
    expected_flip_vertical)).Times(1);

  RenderEntity render_entity = RenderEntity(std::move(p_render_config), &view_api);

  // Call | Assert
  render_entity.Render(expected_scale, expected_render_offset);
}


}
}
}
