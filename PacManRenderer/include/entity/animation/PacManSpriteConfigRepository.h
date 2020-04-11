#pragma once

#include <memory>
#include <vector>

#include "entity/animation/SpriteRenderConfig.h"
#include "entity/EntitySpriteValues.h"

namespace pacman {
namespace renderer {
namespace entity {
namespace animation {

/// <summary>
/// <see cref="PacManSpriteConfigFactory"/> contains the methods to create
/// all sets of sprites per animation of the player character. Each of these 
/// sets of sprites has a corresponding method.
/// </summary>
class PacManSpriteConfigRepository {
public:  
  /// <summary>
  /// Gets the PacMan moving animation sprite configs.
  /// </summary>
  /// <returns>
  /// The set of sprites required for the PacMan moving animation.
  /// </returns>
  std::vector<std::shared_ptr<SpriteRenderConfig>> GetMovingSpriteConfigs() const;

private:
  std::shared_ptr<SpriteRenderConfig> p_default =
    std::make_shared<SpriteRenderConfig>(values::pacman_default,
                                         values::entity_sprite_file,
                                         values::entity_tile_size * 1,
                                         values::entity_tile_size * 0,
                                         values::entity_tile_size * 1,
                                         values::entity_tile_size * 1);

  std::shared_ptr<SpriteRenderConfig> p_moving_0 =
    std::make_shared<SpriteRenderConfig>(values::pacman_moving_anim_0,
                                         values::entity_sprite_file,
                                         values::entity_tile_size * 0,
                                         values::entity_tile_size * 0,
                                         values::entity_tile_size * 1,
                                         values::entity_tile_size * 1);

  std::shared_ptr<SpriteRenderConfig> p_moving_1 =
    std::make_shared<SpriteRenderConfig>(values::pacman_moving_anim_1,
                                         values::entity_sprite_file,
                                         values::entity_tile_size * 2,
                                         values::entity_tile_size * 0,
                                         values::entity_tile_size * 1,
                                         values::entity_tile_size * 1);
};

}
}
}
}
