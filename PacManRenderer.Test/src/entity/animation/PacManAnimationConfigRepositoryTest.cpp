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
  const std::string expected_label = "expected_label";
  ViewAPIMock view_api;

  PacManSpriteConfigRepository spriteRepository = PacManSpriteConfigRepository();
  PacManAnimationConfigRepository animationRepository = PacManAnimationConfigRepository();
  std::shared_ptr<render::IValueProvider<std::string>> p_name_provider =
    std::make_shared<ValueProviderMock<std::string>>();

  // Call
  std::unique_ptr<IAnimationRenderConfig> result =
    animationRepository.ConstructForwardMovingAnimation(&view_api,
                                                        expected_label,
                                                        spriteRepository,
                                                        p_name_provider);

  // Assert
  EXPECT_THAT(result,
    Pointee(Property(&IAnimationRenderConfig::GetLabel, expected_label)));
}

TEST(PacManAnimationConfigRepositoryTest, ConstructBackwardMovingAnimation_ExpectedResult) {
  // Setup
  const std::string expected_label = "expected_label";
  ViewAPIMock view_api;

  PacManSpriteConfigRepository spriteRepository = PacManSpriteConfigRepository();
  PacManAnimationConfigRepository animationRepository = PacManAnimationConfigRepository();
  std::shared_ptr<render::IValueProvider<std::string>> p_name_provider =
    std::make_shared<ValueProviderMock<std::string>>();

  // Call
  std::unique_ptr<IAnimationRenderConfig> result =
    animationRepository.ConstructBackwardMovingAnimation(&view_api,
                                                         expected_label,
                                                         spriteRepository,
                                                         p_name_provider);

  // Assert
  EXPECT_THAT(result,
    Pointee(Property(&IAnimationRenderConfig::GetLabel, expected_label)));
}

}
}
}
}
