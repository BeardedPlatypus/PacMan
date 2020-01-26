#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "objects/ObjectRenderers/BigDotRenderer.h"

#include "CommonSpriteValues.h"
#include "objects/ObjectSpriteValues.h"

#include "ViewAPIMock.h"


namespace pacman {
namespace renderer {
namespace objects {

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

  auto renderer = BigDotRenderer();

  // Call | Assert
  renderer.RenderObject(&view_api, input_x, input_y, expected_scale, render_offset_y);
}

}
}
}
