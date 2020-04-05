#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "entity/animation/PacManAnimationConfigRepository.h"
#include "ViewAPIMock.h"

#include "ValueProviderMock.h"


using ::testing::Property;
using ::testing::AllOf;
using ::testing::ElementsAre;
using ::testing::Pointee;

namespace pacman {
namespace renderer {
namespace entity {
namespace animation {

TEST(PacManAnimationConfigRepositoryTest, ConstructForwardMovingAnimation_ExpectedResult) {
  // Setup
  ViewAPIMock view_api;

  PacManSpriteConfigRepository spriteRepository = PacManSpriteConfigRepository();
  PacManAnimationConfigRepository animationRepository = PacManAnimationConfigRepository();
  std::shared_ptr<render::IValueProvider<std::string>> p_name_provider =
    std::make_shared<ValueProviderMock<std::string>>();

  // Call
  std::unique_ptr<IAnimationRenderConfig> result =
    animationRepository.ConstructForwardMovingAnimation(&view_api,
                                                        "_1",
                                                        spriteRepository,
                                                        p_name_provider);

  // Assert
  EXPECT_THAT(result,
    Pointee(Property(&IAnimationRenderConfig::GetLabel, values::pacman_moving_anim + "_1")));
}

TEST(PacManAnimationConfigRepositoryTest, ConstructBackwardMovingAnimation_ExpectedResult) {
  // Setup
  ViewAPIMock view_api;

  PacManSpriteConfigRepository spriteRepository = PacManSpriteConfigRepository();
  PacManAnimationConfigRepository animationRepository = PacManAnimationConfigRepository();
  std::shared_ptr<render::IValueProvider<std::string>> p_name_provider =
    std::make_shared<ValueProviderMock<std::string>>();

  // Call
  std::unique_ptr<IAnimationRenderConfig> result =
    animationRepository.ConstructBackwardMovingAnimation(&view_api,
                                                          "_1",
                                                          spriteRepository,
                                                          p_name_provider);

  // Assert
  EXPECT_THAT(result,
    Pointee(Property(&IAnimationRenderConfig::GetLabel, values::pacman_moving_anim_back + "_1")));
}

}
}
}
}
