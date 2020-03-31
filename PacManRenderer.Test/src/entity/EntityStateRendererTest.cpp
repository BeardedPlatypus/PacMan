#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "entity/EntityStateRenderer.h"

#include "AnimationRenderConfigMock.h"
#include "ViewAPIMock.h"
#include "ValueProviderMock.h"
#include "AnimationPositionProviderMock.h"

using ::testing::Return;

namespace pacman {
namespace renderer {
namespace entity {

TEST(EntityStateRendererTest, Initialise_CallsAnimationConfigurationsInitialise) {
  // Setup
  std::shared_ptr<ValueProviderMock<std::string>> p_label_provider =
    std::make_shared<ValueProviderMock<std::string>>();
  std::shared_ptr<AnimationPositionProviderMock> p_position_provider =
    std::make_shared<AnimationPositionProviderMock>();
  std::shared_ptr<ValueProviderMock<float>> p_scale_factor_provider =
    std::make_shared<ValueProviderMock<float>>();
  std::shared_ptr<ValueProviderMock<float>> p_rotation_provider =
    std::make_shared<ValueProviderMock<float>>();
  std::shared_ptr<ValueProviderMock<bool>> p_flip_horizontally_provider =
    std::make_shared<ValueProviderMock<bool>>();
  std::shared_ptr<ValueProviderMock<bool>> p_flip_vertical_provider =
    std::make_shared<ValueProviderMock<bool>>();

  std::unique_ptr<entity::render::EntityRenderConfig> p_render_config =
    std::make_unique<entity::render::EntityRenderConfig>(p_label_provider,
                                                         p_position_provider,
                                                         p_scale_factor_provider,
                                                         p_rotation_provider,
                                                         p_flip_horizontally_provider,
                                                         p_flip_vertical_provider);


  auto p_anims = 
    std::make_unique<std::vector<std::unique_ptr<animation::IAnimationRenderConfig>>>();

  for (int i = 0; i < 5; i++) {
    auto p_anim = std::make_unique<AnimationRenderConfig>();

    EXPECT_CALL(*p_anim, Initialise()).Times(1);
    p_anims->push_back(std::move(p_anim));
  }

  ViewAPIMock view_api;

  EntityStateRenderer render_entity = EntityStateRenderer(std::move(p_render_config), 
                                                          std::move(p_anims), 
                                                          &view_api);

  // Call | Assert
  render_entity.Initialise();
}


TEST(EntityStateRendererTest, Update_CallsAnimationConfigurationsUpdate) {
  // Setup
  std::shared_ptr<ValueProviderMock<std::string>> p_label_provider =
    std::make_shared<ValueProviderMock<std::string>>();
  std::shared_ptr<AnimationPositionProviderMock> p_position_provider =
    std::make_shared<AnimationPositionProviderMock>();
  std::shared_ptr<ValueProviderMock<float>> p_scale_factor_provider =
    std::make_shared<ValueProviderMock<float>>();
  std::shared_ptr<ValueProviderMock<float>> p_rotation_provider =
    std::make_shared<ValueProviderMock<float>>();
  std::shared_ptr<ValueProviderMock<bool>> p_flip_horizontally_provider =
    std::make_shared<ValueProviderMock<bool>>();
  std::shared_ptr<ValueProviderMock<bool>> p_flip_vertical_provider =
    std::make_shared<ValueProviderMock<bool>>();

  std::unique_ptr<entity::render::EntityRenderConfig> p_render_config =
    std::make_unique<entity::render::EntityRenderConfig>(p_label_provider,
                                                         p_position_provider,
                                                         p_scale_factor_provider,
                                                         p_rotation_provider,
                                                         p_flip_horizontally_provider,
                                                         p_flip_vertical_provider);

  const float expected_dtime = 12.345F;

  auto p_anims = 
    std::make_unique<std::vector<std::unique_ptr<animation::IAnimationRenderConfig>>>();

  for (int i = 0; i < 5; i++) {
    auto p_anim = std::make_unique<AnimationRenderConfig>();

    EXPECT_CALL(*p_anim, Update(expected_dtime)).Times(1);
    p_anims->push_back(std::move(p_anim));
  }

  ViewAPIMock view_api;

  EntityStateRenderer render_entity = EntityStateRenderer(std::move(p_render_config), 
                                            std::move(p_anims), 
                                            &view_api);

  // Call | Assert
  render_entity.Update(expected_dtime);
}

TEST(EntityStateRendererTest, Render_ExpectedResults) {
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

  std::unique_ptr<std::vector<std::unique_ptr<animation::IAnimationRenderConfig>>> anims =
    std::make_unique<std::vector<std::unique_ptr<animation::IAnimationRenderConfig>>>();


  EntityStateRenderer render_entity = EntityStateRenderer(std::move(p_render_config), std::move(anims), &view_api);

  // Call | Assert
  render_entity.Render(expected_scale, expected_render_offset);
}


TEST(EntityStateRendererTest, Reset_CallsAnimationConfigurationsReset) {
  // Setup
  std::shared_ptr<ValueProviderMock<std::string>> p_label_provider =
    std::make_shared<ValueProviderMock<std::string>>();
  std::shared_ptr<AnimationPositionProviderMock> p_position_provider =
    std::make_shared<AnimationPositionProviderMock>();
  std::shared_ptr<ValueProviderMock<float>> p_scale_factor_provider =
    std::make_shared<ValueProviderMock<float>>();
  std::shared_ptr<ValueProviderMock<float>> p_rotation_provider =
    std::make_shared<ValueProviderMock<float>>();
  std::shared_ptr<ValueProviderMock<bool>> p_flip_horizontally_provider =
    std::make_shared<ValueProviderMock<bool>>();
  std::shared_ptr<ValueProviderMock<bool>> p_flip_vertical_provider =
    std::make_shared<ValueProviderMock<bool>>();

  std::unique_ptr<entity::render::EntityRenderConfig> p_render_config =
    std::make_unique<entity::render::EntityRenderConfig>(p_label_provider,
                                                         p_position_provider,
                                                         p_scale_factor_provider,
                                                         p_rotation_provider,
                                                         p_flip_horizontally_provider,
                                                         p_flip_vertical_provider);


  auto p_anims = 
    std::make_unique<std::vector<std::unique_ptr<animation::IAnimationRenderConfig>>>();

  for (int i = 0; i < 5; i++) {
    auto p_anim = std::make_unique<AnimationRenderConfig>();

    EXPECT_CALL(*p_anim, Reset()).Times(1);
    p_anims->push_back(std::move(p_anim));
  }

  ViewAPIMock view_api;

  EntityStateRenderer render_entity = EntityStateRenderer(std::move(p_render_config), 
                                                          std::move(p_anims), 
                                                          &view_api);

  // Call | Assert
  render_entity.Reset();
}


}
}
}
