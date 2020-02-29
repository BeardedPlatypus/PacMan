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

  UILayer layer = UILayer(1.F, std::move(p_string_renderer), 0.F);

  // Call
  layer.Initialise();
}

}
}
