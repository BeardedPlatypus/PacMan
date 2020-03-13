#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "objects/ObjectRenderers/SmallDotRenderer.h"

#include "CommonSpriteValues.h"
#include "objects/ObjectSpriteValues.h"

#include "ViewAPIMock.h"


namespace pacman {
namespace renderer {
namespace objects {

TEST(SmallDotRendererTest, Initialise_RequestsCorrectSprites) {
  // Setup
  ViewAPIMock view_api;
  EXPECT_CALL(view_api, RequestSprite(values::object_sprite_small_dot,
                                      values::dots_sprite_file,
                                      values::small_dot_offset,
                                      values::small_dot_offset,
                                      values::small_dot_tile_size,
                                      values::small_dot_tile_size)).Times(1);

  auto renderer = SmallDotRenderer(&view_api);

  // Call | Assert
  renderer.Initialise();
}


TEST(SmallDotRendererTest, RenderObject_RendersViewAPI) {
  // Setup
  const float expected_scale = 4.F;
  const int input_x = 5;
  const int input_y = 3;

  const float render_offset_y = 8.F;

  const float expected_x = (float)(input_x * values::tile_size + 3) * expected_scale;
  const float expected_y = (float)(input_y * values::tile_size + 3) * expected_scale + render_offset_y * expected_scale;

  ViewAPIMock view_api;

  EXPECT_CALL(view_api, 
              RenderSprite(values::object_sprite_small_dot,
                            expected_x,
                            expected_y,
                            expected_scale, 
                            0.F, 
                            false, 
                            false)).Times(1);

  auto renderer = SmallDotRenderer(&view_api);

  // Call | Assert
  renderer.RenderObject(input_x, input_y, expected_scale, render_offset_y);
}

}
}
}
