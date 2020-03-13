#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "objects/ObjectRenderers/BigDotRenderer.h"

#include "CommonSpriteValues.h"
#include "objects/ObjectSpriteValues.h"

#include "ViewAPIMock.h"


namespace pacman {
namespace renderer {
namespace objects {

TEST(BigDotRendererTest, Initialise_RequestsCorrectSprites) {
  // Setup
  ViewAPIMock view_api;
  EXPECT_CALL(view_api, RequestSprite(values::object_sprite_big_dot,
                                      values::dots_sprite_file,
                                      0, 0,
                                      values::big_dot_tile_size,
                                      values::big_dot_tile_size)).Times(1);

  auto renderer = BigDotRenderer(&view_api);

  // Call | Assert
  renderer.Initialise();
}


TEST(BigDotRendererTest, RenderObject_RendersViewAPI) {
  // Setup
  const float expected_scale = 3.F;
  const int input_x = 8;
  const int input_y = 2;

  const float render_offset_y = 8.F;

  const float expected_x = (float)(input_x * values::tile_size) * expected_scale;
  const float expected_y = (float)(input_y * values::tile_size) * expected_scale + render_offset_y * expected_scale;

  ViewAPIMock view_api;

  EXPECT_CALL(view_api, 
              RenderSprite(values::object_sprite_big_dot,
                            expected_x,
                            expected_y,
                            expected_scale, 
                            0.F, 
                            false, 
                            false)).Times(1);

  auto renderer = BigDotRenderer(&view_api);

  // Call | Assert
  renderer.RenderObject(input_x, input_y, expected_scale, render_offset_y);
}

}
}
}
