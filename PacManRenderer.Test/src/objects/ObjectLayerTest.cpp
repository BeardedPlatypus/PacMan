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

TEST(ObjectLayerTest, Initialise_InitialisesRenderers) {
  // Setup
  std::unique_ptr<RenderMapping> p_mapping = std::make_unique<RenderMapping>();

  std::unique_ptr<ObjectRendererMock> p_small_dot_renderer =
    std::make_unique<ObjectRendererMock>();
  EXPECT_CALL(*p_small_dot_renderer, Initialise()).Times(1);

  std::unique_ptr<ObjectRendererMock> p_big_dot_renderer =
    std::make_unique<ObjectRendererMock>();
  EXPECT_CALL(*p_big_dot_renderer, Initialise()).Times(1);

  p_mapping->emplace(std::make_pair(state::field::FieldObjectType::SmallDot,
                                    std::move(p_small_dot_renderer)));
  p_mapping->emplace(std::make_pair(state::field::FieldObjectType::BigDot,
                                    std::move(p_big_dot_renderer)));

  float expected_render_offset = 12.3F;
  float expected_scale = 4.F;

  ViewAPIMock view_api;

  FieldObjectManagerMock object_manager;

  ObjectLayer layer = ObjectLayer(expected_scale, 
                                  &object_manager, 
                                  std::move(p_mapping),
                                  expected_render_offset);

  // Call | Assert
  layer.Initialise();
}


TEST(ObjectLayerTest, Render_CallsSprites) {
  // Setup
  std::unique_ptr<RenderMapping> p_mapping = std::make_unique<RenderMapping>();

  float expected_render_offset = 12.3F;
  float expected_scale = 4.F;

  std::unique_ptr<ObjectRendererMock> p_small_dot_renderer =
    std::make_unique<ObjectRendererMock>();
  EXPECT_CALL(*(p_small_dot_renderer), 
              RenderObject(0, 1, expected_scale, expected_render_offset)).Times(1);

  std::unique_ptr<ObjectRendererMock> p_big_dot_renderer =
    std::make_unique<ObjectRendererMock>();
  EXPECT_CALL(*(p_big_dot_renderer), 
              RenderObject( 1, 0, expected_scale, expected_render_offset)).Times(1);


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
                                  &object_manager, 
                                  std::move(p_mapping),
                                  expected_render_offset);

  // Call | Assert
  layer.Render();
}


}
}
}
