#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <ui/UILayer.h>
#include <ui/font/StaticStringRenderData.h>

#include "StringRendererMock.h"


using ::testing::Ref;


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


TEST(UILayerTest, Render_CallsStringRendererRenderString) {
  // Setup
  std::unique_ptr<StringRendererMock> p_string_renderer =
    std::make_unique<StringRendererMock>();

  const float expected_scale = 4.0F;

  auto p_render_data =
    std::make_unique<std::vector<std::unique_ptr<ui::IStringRenderData>>>();

  auto p_data = std::make_unique<ui::StaticStringRenderData>("test string", 1.F, 2.F, 3.F, ui::Justification::Centre);
  ui::IStringRenderData* p_data_element = p_data.get();
  EXPECT_CALL(*p_string_renderer, RenderString(Ref(*p_data_element), expected_scale)).Times(1);

  p_render_data->push_back(std::move(p_data));

  UILayer layer = UILayer(expected_scale, 
                          std::move(p_string_renderer), 
                          std::move(p_render_data),
                          0.F);

  // Call
  layer.Render();
}


}
}
