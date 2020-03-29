#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "entity/animation/SpriteRenderConfig.h"

using ::testing::Eq;

namespace pacman {
namespace renderer {
namespace entity {
namespace animation {

TEST(SpriteRenderConfigTest, Constructor_ExpectedResults) {
  // Setup
  const std::string expected_sprite_label = "sprite_label";
  const std::string expected_texture_file_path = "texture_file_path.png";
  const int x = 1;
  const int y = 2;
  const int w = 3;
  const int h = 4;

  // Call
  auto sprite_render_config = SpriteRenderConfig(expected_sprite_label, 
                                                 expected_texture_file_path,
                                                 x, y, w, h);

  // Assert
  EXPECT_THAT(sprite_render_config.GetSpriteLabel(), Eq(expected_sprite_label));
  EXPECT_THAT(sprite_render_config.GetTextureFilePath(), Eq(expected_texture_file_path));
  EXPECT_THAT(sprite_render_config.GetX(), Eq(x));
  EXPECT_THAT(sprite_render_config.GetY(), Eq(y));
  EXPECT_THAT(sprite_render_config.GetW(), Eq(w));
  EXPECT_THAT(sprite_render_config.GetH(), Eq(h));
}

}
}
}
}
