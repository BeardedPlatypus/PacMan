#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "entity/animation/PacManSpriteConfigRepository.h"

using ::testing::Property;
using ::testing::AllOf;
using ::testing::ElementsAre;
using ::testing::Pointee;

namespace pacman {
namespace renderer {
namespace entity {
namespace animation {

TEST(PacManSpriteConfigRepositoryTest, GetMovingSpriteConfigs_ExpectedResults) {
  // Setup
  PacManSpriteConfigRepository repository = PacManSpriteConfigRepository();

  // Call
  std::vector<std::shared_ptr<SpriteRenderConfig>> result =
    repository.GetMovingSpriteConfigs();

  // Assert
  EXPECT_THAT(result, ElementsAre(
    Pointee(AllOf(
      Property(&SpriteRenderConfig::GetSpriteLabel, values::pacman_default),
      Property(&SpriteRenderConfig::GetTextureFilePath, values::entity_sprite_file),
      Property(&SpriteRenderConfig::GetX, 16),
      Property(&SpriteRenderConfig::GetY,  0),
      Property(&SpriteRenderConfig::GetW, 16),
      Property(&SpriteRenderConfig::GetH, 16))),
    Pointee(AllOf(
      Property(&SpriteRenderConfig::GetSpriteLabel, values::pacman_moving_anim_0),
      Property(&SpriteRenderConfig::GetTextureFilePath, values::entity_sprite_file),
      Property(&SpriteRenderConfig::GetX,  0),
      Property(&SpriteRenderConfig::GetY, 0),
      Property(&SpriteRenderConfig::GetW, 16),
      Property(&SpriteRenderConfig::GetH, 16))),
    Pointee(AllOf(
      Property(&SpriteRenderConfig::GetSpriteLabel, values::pacman_moving_anim_1),
      Property(&SpriteRenderConfig::GetTextureFilePath, values::entity_sprite_file),
      Property(&SpriteRenderConfig::GetX, 32),
      Property(&SpriteRenderConfig::GetY,  0),
      Property(&SpriteRenderConfig::GetW, 16),
      Property(&SpriteRenderConfig::GetH, 16)))
  ));
}

}
}
}
}
