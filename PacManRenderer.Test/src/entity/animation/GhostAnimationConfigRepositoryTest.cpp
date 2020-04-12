#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "entity/animation/GhostAnimationConfigRepository.h"
#include "ViewAPIMock.h"

#include "ValueProviderMock.h"


using ::testing::Property;
using ::testing::Pointee;

namespace pacman {
namespace renderer {
namespace entity {
namespace animation {

class GhostTypeBasedTest : public ::testing::TestWithParam<state::GhostEntityType> {
public:
  static std::vector<state::GhostEntityType> GetTestData() {
    return {
      state::GhostEntityType::Blinky,
      state::GhostEntityType::Pinky,
      state::GhostEntityType::Inky,
      state::GhostEntityType::Clyde,
    };
  }
};


TEST_P(GhostTypeBasedTest, ConstructMovingHorizontalAnimation_ExpectedResult) {
  // Setup
  const std::string expected_label = "expected_label";
  ViewAPIMock view_api;

  GhostSpriteConfigRepository spriteRepository = GhostSpriteConfigRepository();
  GhostAnimationConfigRepository animationRepository = GhostAnimationConfigRepository();
  std::shared_ptr<render::IValueProvider<std::string>> p_name_provider =
    std::make_shared<ValueProviderMock<std::string>>();

  // Call
  std::unique_ptr<IAnimationRenderConfig> result =
    animationRepository.ConstructMovingHorizontalAnimation(&view_api,
                                                           expected_label,
                                                           GetParam(),
                                                           spriteRepository);

  // Assert
  EXPECT_THAT(result,
    Pointee(Property(&IAnimationRenderConfig::GetLabel, expected_label)));
}


TEST_P(GhostTypeBasedTest, ConstructMovingUpAnimation_ExpectedResult) {
  // Setup
  const std::string expected_label = "expected_label";
  ViewAPIMock view_api;

  GhostSpriteConfigRepository spriteRepository = GhostSpriteConfigRepository();
  GhostAnimationConfigRepository animationRepository = GhostAnimationConfigRepository();
  std::shared_ptr<render::IValueProvider<std::string>> p_name_provider =
    std::make_shared<ValueProviderMock<std::string>>();

  // Call
  std::unique_ptr<IAnimationRenderConfig> result =
    animationRepository.ConstructMovingUpAnimation(&view_api,
                                                   expected_label,
                                                   GetParam(),
                                                   spriteRepository);

  // Assert
  EXPECT_THAT(result,
    Pointee(Property(&IAnimationRenderConfig::GetLabel, expected_label)));
}


TEST_P(GhostTypeBasedTest, ConstructMovingDownAnimation_ExpectedResult) {
  // Setup
  const std::string expected_label = "expected_label";
  ViewAPIMock view_api;

  GhostSpriteConfigRepository spriteRepository = GhostSpriteConfigRepository();
  GhostAnimationConfigRepository animationRepository = GhostAnimationConfigRepository();
  std::shared_ptr<render::IValueProvider<std::string>> p_name_provider =
    std::make_shared<ValueProviderMock<std::string>>();

  // Call
  std::unique_ptr<IAnimationRenderConfig> result =
    animationRepository.ConstructMovingDownAnimation(&view_api,
                                                     expected_label,
                                                     GetParam(),
                                                     spriteRepository);

  // Assert
  EXPECT_THAT(result,
    Pointee(Property(&IAnimationRenderConfig::GetLabel, expected_label)));
}


INSTANTIATE_TEST_SUITE_P(GhostAnimationConfigRepositoryTest,
                         GhostTypeBasedTest,
                         ::testing::ValuesIn(GhostTypeBasedTest::GetTestData()));


}
}
}
}
