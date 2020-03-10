#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "objects/ObjectLayer.h"

#include "CommonSpriteValues.h"
#include "objects/ObjectSpriteValues.h"

#include "ViewAPIMock.h"
#include "ObjectRendererMock.h"
#include "FieldObjectManagerMock.h"

using ::testing::ReturnRef;

namespace pacman {
namespace renderer {
namespace objects {

TEST(ObjectLayerTest, Initialise_InitialisesSprites) {
  // Setup
  std::unique_ptr<RenderMapping> p_mapping = std::make_unique<RenderMapping>();


  p_mapping->emplace(std::make_pair(state::field::FieldObjectType::SmallDot,
                                    std::make_unique<ObjectRendererMock>()));
  p_mapping->emplace(std::make_pair(state::field::FieldObjectType::BigDot,
                                    std::make_unique<ObjectRendererMock>()));

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


TEST(ObjectLayerTest, Render_CallsSprites) {
  // Setup
  ViewAPIMock view_api;
  std::unique_ptr<RenderMapping> p_mapping = std::make_unique<RenderMapping>();

  float expected_render_offset = 12.3F;
  float expected_scale = 4.F;

  std::unique_ptr<ObjectRendererMock> p_small_dot_renderer =
    std::make_unique<ObjectRendererMock>();
  EXPECT_CALL(*(p_small_dot_renderer), 
              RenderObject(&view_api, 0, 1, expected_scale, expected_render_offset)).Times(1);

  std::unique_ptr<ObjectRendererMock> p_big_dot_renderer =
    std::make_unique<ObjectRendererMock>();
  EXPECT_CALL(*(p_big_dot_renderer), 
              RenderObject(&view_api, 1, 0, expected_scale, expected_render_offset)).Times(1);


  p_mapping->emplace(std::make_pair(state::field::FieldObjectType::SmallDot,
                                    std::move(p_small_dot_renderer)));
  p_mapping->emplace(std::make_pair(state::field::FieldObjectType::BigDot,
                                    std::move(p_big_dot_renderer)));

  FieldObjectManagerMock object_manager;
  std::vector<state::field::FieldObject> field_objs = {
    state::field::FieldObject(0, 1, state::field::FieldObjectType::SmallDot),
    state::field::FieldObject(1, 0, state::field::FieldObjectType::BigDot),
  };

  ON_CALL(object_manager, GetAllFieldObjects()).WillByDefault(ReturnRef(field_objs));

  ObjectLayer layer = ObjectLayer(expected_scale, 
                                  &view_api, 
                                  &object_manager, 
                                  std::move(p_mapping),
                                  expected_render_offset);

  // Call | Assert
  layer.Render();
}


}
}
}
