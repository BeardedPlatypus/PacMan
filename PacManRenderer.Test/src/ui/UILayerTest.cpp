#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <ui/UILayer.h>

#include "StringRendererMock.h"

namespace pacman {
namespace renderer {

TEST(UILayerTest, Initialise_CallsStringRendererInitialise) {
  // Setup
  std::unique_ptr<StringRendererMock> p_string_renderer =
    std::make_unique<StringRendererMock>();

  EXPECT_CALL(*p_string_renderer, Initialise()).Times(1);

  auto p_render_data =
    std::make_unique<std::vector<std::unique_ptr<ui::IStringRenderData>>>();

  UILayer layer = UILayer(1.F, 
                          std::move(p_string_renderer), 
                          std::move(p_render_data),
                          0.F);

  // Call
  layer.Initialise();
}

}
}
