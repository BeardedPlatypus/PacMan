#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "manager/LayerManager.h"

#include "RenderLayerMock.h"


namespace pacman {
namespace renderer {
namespace objects {

TEST(LayerManagerTest, Initialise_CallsCorrectLayers) {
  // Setup
  std::vector<std::unique_ptr<IRenderLayer>> render_layers = { };

  for (size_t i = 0; i < 5; ++i) {
    std::unique_ptr<RenderLayerMock> p_layer = std::make_unique<RenderLayerMock>();
    EXPECT_CALL(*(p_layer), Initialise()).Times(1);

    render_layers.push_back(std::move(p_layer));
  }

  LayerManager layer_manager = LayerManager(render_layers);

  // Call
  layer_manager.Initialise();
}

TEST(LayerManagerTest, Update_CallsCorrectLayers) {
  // Setup
  const float dtime = 0.513F;
  std::vector<std::unique_ptr<IRenderLayer>> render_layers = { };

  for (size_t i = 0; i < 5; ++i) {
    std::unique_ptr<RenderLayerMock> p_layer = std::make_unique<RenderLayerMock>();
    EXPECT_CALL(*(p_layer), Update(dtime)).Times(1);

    render_layers.push_back(std::move(p_layer));
  }

  LayerManager layer_manager = LayerManager(render_layers);

  // Call
  layer_manager.Update(dtime);
}

TEST(LayerManagerTest, Render_CallsCorrectLayers) {
  // Setup
  std::vector<std::unique_ptr<IRenderLayer>> render_layers = { };

  for (size_t i = 0; i < 5; ++i) {
    std::unique_ptr<RenderLayerMock> p_layer = std::make_unique<RenderLayerMock>();
    EXPECT_CALL(*(p_layer), Render()).Times(1);

    render_layers.push_back(std::move(p_layer));
  }

  LayerManager layer_manager = LayerManager(render_layers);

  // Call
  layer_manager.Render();
}

}
}
}