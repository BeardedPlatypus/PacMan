#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <entity/render/EntityRenderConfig.h>

#include "ValueProviderMock.h"
#include "AnimationPositionProviderMock.h"

using ::testing::Eq;

namespace pacman {
namespace renderer {
namespace entity {
namespace render {

TEST(EntityRenderConfigTest, Constructor_ExpectedResults) {
  // setup
  std::shared_ptr<IValueProvider<std::string>> p_label_provider = std::make_shared<ValueProviderMock<std::string>>();
  std::shared_ptr<IAnimationPositionProvider> p_position_provider = std::make_shared<AnimationPositionProviderMock>();
  std::shared_ptr<IValueProvider<float>> p_scale_provider = std::make_shared<ValueProviderMock<float>>();
  std::shared_ptr<IValueProvider<float>> p_rotation_provider = std::make_shared<ValueProviderMock<float>>();
  std::shared_ptr<IValueProvider<bool>> p_hor_provider = std::make_shared<ValueProviderMock<bool>>();
  std::shared_ptr<IValueProvider<bool>> p_vert_provider = std::make_shared<ValueProviderMock<bool>>();

  // call
  auto config = EntityRenderConfig(p_label_provider,
                                   p_position_provider,
                                   p_scale_provider,
                                   p_rotation_provider,
                                   p_hor_provider,
                                   p_vert_provider);

  // assert
  ASSERT_THAT(config.GetLabelProvider(), Eq(p_label_provider.get()));
  ASSERT_THAT(config.GetPositionProvider(), Eq(p_position_provider.get()));
  ASSERT_THAT(config.GetScaleProvider(), Eq(p_scale_provider.get()));
  ASSERT_THAT(config.GetRotationProvider(), Eq(p_rotation_provider.get()));
  ASSERT_THAT(config.GetFlipHorizontallyProvider(), Eq(p_hor_provider.get()));
  ASSERT_THAT(config.GetFlipVerticallyProvider(), Eq(p_vert_provider.get()));
}

}
}
}
}
