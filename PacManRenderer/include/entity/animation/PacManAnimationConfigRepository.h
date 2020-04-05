#pragma once

#include <memory>
#include <vector>

#include <IViewAPI.h>

#include "entity/animation/IAnimationRenderConfig.h"
#include "entity/animation/PacManSpriteConfigRepository.h"
#include "entity/render/IValueProvider.h" 

namespace pacman {
namespace renderer {
namespace entity {
namespace animation {

/// <summary>
/// <see cref="PacManAnimationConfigRepository"/> contains the methods to 
/// construct the different <see cref="IAnimationRenderConfig"/> objects used
/// by the pacman entity.
/// </summary>
class PacManAnimationConfigRepository {
public:  
  /// <summary>
  /// Constructs the forward moving animation config.
  /// </summary>
  /// <returns>
  /// A <see cref="std::unique_ptr{IAnimationConfig}"/> containing the newly
  /// constructed animation config.
  /// </returns>
  std::unique_ptr<IAnimationRenderConfig> ConstructForwardMovingAnimation(view::IViewAPI* p_view_api,
                                                                          const std::string& unique_label_id,
                                                                          const PacManSpriteConfigRepository& sprite_repository,
                                                                          std::shared_ptr<render::IValueProvider<std::string>> p_active_label_provider) const;
  
  /// <summary>
  /// Constructs the backward moving animation config.
  /// </summary>
  /// A <see cref="std::unique_ptr{IAnimationConfig}"/> containing the newly
  /// constructed animation config.
  /// </returns>
  std::unique_ptr<IAnimationRenderConfig> ConstructBackwardMovingAnimation(view::IViewAPI* p_view_api,
                                                                           const std::string& unique_label_id,
                                                                           const PacManSpriteConfigRepository& sprite_repository,
                                                                           std::shared_ptr<render::IValueProvider<std::string>> p_active_label_provider) const;
};

}
}
}
}
