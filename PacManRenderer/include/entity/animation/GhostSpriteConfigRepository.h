#pragma onc
#include <memory>
#include <vector>
#include <unordered_map>

#include "entity/animation/SpriteRenderConfig.h"
#include "entity/EntitySpriteValues.h"

#include <entity/ghost/GhostEntityType.h>
#include <util/EnumClassHash.h>

namespace pacman {
namespace renderer {
namespace entity {
namespace animation {

/// <summary>
/// <see cref="GhostSpriteConfigFactory"/> contains the methods to create
/// the sets of sprites for each ghost animation.
/// Where applicable, the methods require a <see cref="state::GhostEntityType"/>
/// to retrieve the animation corresponding with the specified type.
/// </summary>
class GhostSpriteConfigRepository {
public:
  /// <summary>
  /// Creates a new <see cref="GhostSpriteConfigRepository"/>.
  /// </summary>
  GhostSpriteConfigRepository();

  /// <summary>
  /// Gets the <see cref="SpriteRenderConfig"/> corresponding with the moving horizontal animation
  /// of the specified <paramref cref="ghost_entity_type"/>.
  /// </summary>
  /// <param name="ghost_type">Type of the ghost.</param>
  /// <returns>
  /// A vector containing the pointers to the appropriate <see cref="SpriteRenderConfig"/>.
  /// </returns>
  std::vector<std::shared_ptr<SpriteRenderConfig>> GetMovingHorizontalSpriteConfigs(state::GhostEntityType ghost_type) const;

  /// <summary>
  /// Gets the <see cref="SpriteRenderConfig"/> corresponding with the moving up animation
  /// of the specified <paramref cref="ghost_entity_type"/>.
  /// </summary>
  /// <param name="ghost_type">Type of the ghost.</param>
  /// <returns>
  /// A vector containing the pointers to the appropriate <see cref="SpriteRenderConfig"/>.
  /// </returns>
  std::vector<std::shared_ptr<SpriteRenderConfig>> GetMovingUpSpriteConfigs(state::GhostEntityType ghost_type) const;

  /// <summary>
  /// Gets the <see cref="SpriteRenderConfig"/> corresponding with the moving down animation
  /// of the specified <paramref cref="ghost_entity_type"/>.
  /// </summary>
  /// <param name="ghost_type">Type of the ghost.</param>
  /// <returns>
  /// A vector containing the pointers to the appropriate <see cref="SpriteRenderConfig"/>.
  /// </returns>
  std::vector<std::shared_ptr<SpriteRenderConfig>> GetMovingDownSpriteConfigs(state::GhostEntityType ghost_type) const;

private:
  void InitialiseMovingSpriteConfigs();

  std::unordered_map<state::GhostEntityType,
                     std::vector<std::shared_ptr<SpriteRenderConfig>>,
                     EnumClassHash> moving_horizontal_sprites =
    std::unordered_map<state::GhostEntityType, std::vector<std::shared_ptr<SpriteRenderConfig>>, EnumClassHash>();

  std::unordered_map<state::GhostEntityType,
                     std::vector<std::shared_ptr<SpriteRenderConfig>>,
                     EnumClassHash> moving_up_sprites =
    std::unordered_map<state::GhostEntityType, std::vector<std::shared_ptr<SpriteRenderConfig>>, EnumClassHash>();

  std::unordered_map<state::GhostEntityType,
                     std::vector<std::shared_ptr<SpriteRenderConfig>>,
                     EnumClassHash> moving_down_sprites =
    std::unordered_map<state::GhostEntityType, std::vector<std::shared_ptr<SpriteRenderConfig>>, EnumClassHash>();
};

}
}
}
}
