#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "entity/EntityLayer.h"

#include "EntityStateRendererMock.h"

namespace pacman {
namespace renderer {

TEST(EntityLayer, Initialise_InitialisesRenderEntities) {
  // Setup
  auto p_entities = std::make_unique<std::vector<std::unique_ptr<entity::IEntityStateRenderer>>>();

  for (size_t i = 0; i < 3; i++) {
    auto p_entity = std::make_unique<EntityStateRendererMock>();
    EXPECT_CALL(*(p_entity), Initialise()).Times(1);

    p_entities->push_back(std::move(p_entity));
  }

  auto layer = EntityLayer(std::move(p_entities), 0.F, 0.F);

  // Call | Assert
  layer.Initialise();
}


TEST(EntityLayer, Update_UpdatesRenderEntities) {
  // Setup
  const float expected_dtime = 12.3F;
  auto p_entities = std::make_unique<std::vector<std::unique_ptr<entity::IEntityStateRenderer>>>();

  for (size_t i = 0; i < 3; i++) {
    auto p_entity = std::make_unique<EntityStateRendererMock>();
    EXPECT_CALL(*(p_entity), Update(expected_dtime)).Times(1);

    p_entities->push_back(std::move(p_entity));
  }

  auto layer = EntityLayer(std::move(p_entities), 0.F, 0.F);

  // Call | Assert
  layer.Update(expected_dtime);
}


TEST(EntityLayer, Render_RendersRenderEntities) {
  // Setup
  const float expected_scale  = 12.3F;
  const float expected_offset = 45.6F;
  auto p_entities = std::make_unique<std::vector<std::unique_ptr<entity::IEntityStateRenderer>>>();

  for (size_t i = 0; i < 3; i++) {
    auto p_entity = std::make_unique<EntityStateRendererMock>();
    EXPECT_CALL(*(p_entity), Render(expected_scale, expected_offset)).Times(1);

    p_entities->push_back(std::move(p_entity));
  }

  auto layer = EntityLayer(std::move(p_entities), expected_scale, expected_offset);

  // Call | Assert
  layer.Render();
}

}
}