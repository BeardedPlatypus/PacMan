#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "entity/animation/GhostSpriteConfigRepository.h"

using ::testing::Property;
using ::testing::AllOf;
using ::testing::ElementsAre;
using ::testing::Pointee;

namespace pacman {
namespace renderer {
namespace entity {
namespace animation {


TEST(GhostSpriteConfigRepositoryTest, Constructor_ExpectedResults) {
  // Call
  GhostSpriteConfigRepository repository = GhostSpriteConfigRepository();

  // Assert
  std::vector<std::pair<state::GhostEntityType, std::string>> ghosts = {
    std::make_pair(state::GhostEntityType::Blinky, "blinky"),
    std::make_pair(state::GhostEntityType::Pinky,  "pinky"),
    std::make_pair(state::GhostEntityType::Inky,   "inky"),
    std::make_pair(state::GhostEntityType::Clyde,  "clyde"),
  };

  for (size_t i = 0; i < ghosts.size(); i++) {
    const state::GhostEntityType t = ghosts.at(i).first;
    const std::string& name = ghosts.at(i).second;

    EXPECT_THAT(repository.GetMovingHorizontalSpriteConfigs(t),
        ElementsAre(
          Pointee(AllOf(
            Property(&SpriteRenderConfig::GetSpriteLabel, name + "_moving_horizontal_0"),
            Property(&SpriteRenderConfig::GetTextureFilePath, values::entity_sprite_file),
            Property(&SpriteRenderConfig::GetX, (0 * 2) * 16),
            Property(&SpriteRenderConfig::GetY, (i + 2) * 16),
            Property(&SpriteRenderConfig::GetW, 16),
            Property(&SpriteRenderConfig::GetH, 16))),
          Pointee(AllOf(
            Property(&SpriteRenderConfig::GetSpriteLabel, name + "_moving_horizontal_1"),
            Property(&SpriteRenderConfig::GetTextureFilePath, values::entity_sprite_file),
            Property(&SpriteRenderConfig::GetX, (0 * 2 + 1) * 16),
            Property(&SpriteRenderConfig::GetY, (i + 2) * 16),
            Property(&SpriteRenderConfig::GetW, 16),
            Property(&SpriteRenderConfig::GetH, 16)))));
    EXPECT_THAT(repository.GetMovingUpSpriteConfigs(t),
        ElementsAre(
          Pointee(AllOf(
            Property(&SpriteRenderConfig::GetSpriteLabel, name + "_moving_up_0"),
            Property(&SpriteRenderConfig::GetTextureFilePath, values::entity_sprite_file),
            Property(&SpriteRenderConfig::GetX, (1 * 2) * 16),
            Property(&SpriteRenderConfig::GetY, (i + 2) * 16),
            Property(&SpriteRenderConfig::GetW, 16),
            Property(&SpriteRenderConfig::GetH, 16))),
          Pointee(AllOf(
            Property(&SpriteRenderConfig::GetSpriteLabel, name + "_moving_up_1"),
            Property(&SpriteRenderConfig::GetTextureFilePath, values::entity_sprite_file),
            Property(&SpriteRenderConfig::GetX, (1 * 2 + 1) * 16),
            Property(&SpriteRenderConfig::GetY, (i + 2) * 16),
            Property(&SpriteRenderConfig::GetW, 16),
            Property(&SpriteRenderConfig::GetH, 16)))));
    EXPECT_THAT(repository.GetMovingDownSpriteConfigs(t),
        ElementsAre(
          Pointee(AllOf(
            Property(&SpriteRenderConfig::GetSpriteLabel, name + "_moving_down_0"),
            Property(&SpriteRenderConfig::GetTextureFilePath, values::entity_sprite_file),
            Property(&SpriteRenderConfig::GetX, (2 * 2) * 16),
            Property(&SpriteRenderConfig::GetY, (i + 2) * 16),
            Property(&SpriteRenderConfig::GetW, 16),
            Property(&SpriteRenderConfig::GetH, 16))),
          Pointee(AllOf(
            Property(&SpriteRenderConfig::GetSpriteLabel, name + "_moving_down_1"),
            Property(&SpriteRenderConfig::GetTextureFilePath, values::entity_sprite_file),
            Property(&SpriteRenderConfig::GetX, (2 * 2 + 1) * 16),
            Property(&SpriteRenderConfig::GetY, (i + 2) * 16),
            Property(&SpriteRenderConfig::GetW, 16),
            Property(&SpriteRenderConfig::GetH, 16)))));
  }
}

}
}
}
}
