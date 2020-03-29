#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "ViewAPIMock.h"
#include "AnimationUpdateBehaviourMock.h"

#include "entity/animation/AnimationRenderConfig.h"

using ::testing::Eq;
using ::testing::Return;

namespace pacman {
namespace renderer {
namespace entity {
namespace animation {

TEST(AnimationRenderConfigTest, GetLabel_ExpectedResults) {
  // Setup
  ViewAPIMock view_api;
  const std::string expected_label = "label";

  AnimationRenderConfig config = AnimationRenderConfig(&view_api,
                                                       expected_label,
                                                       1.F,
                                                       std::vector<std::string>(),
                                                       std::vector<SpriteRenderConfig>(),
                                                       std::make_unique<AnimationUpdateBehaviourMock>());

  // Call
  std::string result = config.GetLabel();

  // Assert
  EXPECT_THAT(result, Eq(expected_label));
}



TEST(AnimationRenderConfigTest, Update_CallsUpdateBehaviour) {
  // Setup
  const float dtime = 5.123F;

  ViewAPIMock view_api;

  std::unique_ptr<AnimationUpdateBehaviourMock> p_update_behaviour =
    std::make_unique<AnimationUpdateBehaviourMock>();
  EXPECT_CALL(*p_update_behaviour, Update(dtime)).Times(1);

  AnimationRenderConfig config = AnimationRenderConfig(&view_api,
                                                       "label",
                                                       1.F,
                                                       std::vector<std::string>(),
                                                       std::vector<SpriteRenderConfig>(),
                                                       std::move(p_update_behaviour));

  // Call | Assert
  config.Update(dtime);
}



TEST(AnimationRenderConfigTest, Reset_CallsResetAnimation) {
  // Setup
  const std::string animation_label = "label";
  ViewAPIMock view_api;
  EXPECT_CALL(view_api, ResetAnimationTime(animation_label)).Times(1);

  AnimationRenderConfig config = AnimationRenderConfig(&view_api,
                                                       animation_label,
                                                       1.F,
                                                       std::vector<std::string>(),
                                                       std::vector<SpriteRenderConfig>(),
                                                       std::make_unique<AnimationUpdateBehaviourMock>());

  // Call | Assert
  config.Reset();
}

TEST(AnimationRenderConfigTest, Initialise_CallsViewAPICorrectly) {
  const std::string anim_label = "anim_label";
  const float frame_time = 1.23F;

  const std::vector<SpriteRenderConfig> sprites = {
    SpriteRenderConfig("label_a", "tex_1", 1,  2,  3,  4),
    SpriteRenderConfig("label_b", "tex_2", 5,  6,  7,  8),
    SpriteRenderConfig("label_c", "tex_3", 9, 10, 11, 12),
  };

  const std::vector<std::string> frames = {
    sprites[0].GetSpriteLabel(),
    sprites[1].GetSpriteLabel(),
    sprites[0].GetSpriteLabel(),
    sprites[2].GetSpriteLabel(),
    sprites[0].GetSpriteLabel(),
  };

  ViewAPIMock view_api;
  EXPECT_CALL(view_api, HasSprite(sprites[0].GetSpriteLabel()))
    .Times(1)
    .WillOnce(Return(false));

  EXPECT_CALL(view_api, RequestSprite(sprites[0].GetSpriteLabel(), 
                                      sprites[0].GetTextureFilePath(),
                                      sprites[0].GetX(),
                                      sprites[0].GetY(),
                                      sprites[0].GetW(),
                                      sprites[0].GetH()))
    .Times(1);

  EXPECT_CALL(view_api, HasSprite(sprites[1].GetSpriteLabel()))
    .Times(1)
    .WillOnce(Return(true));

  EXPECT_CALL(view_api, HasSprite(sprites[2].GetSpriteLabel()))
    .Times(1)
    .WillOnce(Return(false));

  EXPECT_CALL(view_api, RequestSprite(sprites[2].GetSpriteLabel(), 
                                      sprites[2].GetTextureFilePath(),
                                      sprites[2].GetX(),
                                      sprites[2].GetY(),
                                      sprites[2].GetW(),
                                      sprites[2].GetH()))
    .Times(1);

  EXPECT_CALL(view_api, RequestSpriteAnimation(anim_label, frame_time, frames))
    .Times(1);

  AnimationRenderConfig config = AnimationRenderConfig(&view_api,
                                                       anim_label,
                                                       frame_time,
                                                       frames,
                                                       sprites,
                                                       std::make_unique<AnimationUpdateBehaviourMock>());

  // Call | Assert
  config.Initialise();
}

}
}
}
}
