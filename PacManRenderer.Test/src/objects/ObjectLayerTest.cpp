#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "objects/ObjectLayer.h"

#include "CommonSpriteValues.h"
#include "objects/ObjectSpriteValues.h"

#include "ViewAPIMock.h"
#include "FieldObjectManagerMock.h"

#include "objects/ObjectRenderers/BigDotRenderer.h"
#include "objects/ObjectRenderers/SmallDotRenderer.h"

namespace pacman {
namespace renderer {
namespace objects {

TEST(ObjectLayerTest, Initialise_InitialisesSprites) {
  // Setup
  std::unique_ptr<RenderMapping> p_mapping = std::make_unique<RenderMapping>();

  p_mapping->emplace(std::make_pair(state::field::FieldObjectType::SmallDot,
                                    std::make_unique<objects::SmallDotRenderer>()));
  p_mapping->emplace(std::make_pair(state::field::FieldObjectType::BigDot,
                                    std::make_unique<objects::BigDotRenderer>()));

  float expected_render_offset = 12.3F;
  float expected_scale = 4.F;

  ViewAPIMock view_api;

  EXPECT_CALL(view_api, RequestSprite(values::object_sprite_small_dot,
                                      values::dots_sprite_file,
                                      values::small_dot_offset,
                                      values::small_dot_offset,
                                      values::small_dot_tile_size,
                                      values::small_dot_tile_size)).Times(1);
  EXPECT_CALL(view_api, RequestSprite(values::object_sprite_big_dot,
                                      values::dots_sprite_file,
                                      0, 0,
                                      values::big_dot_tile_size,
                                      values::big_dot_tile_size)).Times(1);

  FieldObjectManagerMock object_manager;

  ObjectLayer layer = ObjectLayer(expected_scale, 
                                  &view_api, 
                                  &object_manager, 
                                  std::move(p_mapping),
                                  expected_render_offset);

  // Call | Assert
  layer.Initialise();
}

}
}
}
