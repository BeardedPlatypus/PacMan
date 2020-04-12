#pragma once

#include <memory>
#include <vector>

#include <IViewAPI.h>

#include "entity/animation/IAnimationRenderConfig.h"
#include "entity/animation/GhostSpriteConfigRepository.h"
#include "entity/render/IValueProvider.h" 

namespace pacman {
namespace renderer {
namespace entity {
namespace animation {

/// <summary>
/// <see cref="GhostAnimationConfigRepository"/> contains the methods to 
/// construct the different <see cref="IAnimationRenderConfig"/> objects used
/// by the ghost entities.
/// </summary>
class GhostAnimationConfigRepository {
public:
  std::unique_ptr<IAnimationRenderConfig> ConstructMovingHorizontalAnimation(view::IViewAPI* p_view_api,
                                                                             const std::string& unique_label_id,
                                                                             state::GhostEntityType ghost_entity_type,
                                                                             const GhostSpriteConfigRepository& sprite_repository) const;

  std::unique_ptr<IAnimationRenderConfig> ConstructMovingUpAnimation(view::IViewAPI* p_view_api,
                                                                     const std::string& unique_label_id,
                                                                     state::GhostEntityType ghost_entity_type,
                                                                     const GhostSpriteConfigRepository& sprite_repository) const;

  std::unique_ptr<IAnimationRenderConfig> ConstructMovingDownAnimation(view::IViewAPI* p_view_api,
                                                                       const std::string& unique_label_id,
                                                                       state::GhostEntityType ghost_entity_type,
                                                                       const GhostSpriteConfigRepository& sprite_repository) const;
};

}
}
}
}
