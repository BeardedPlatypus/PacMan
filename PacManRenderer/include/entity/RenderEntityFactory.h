#pragma once

#include <memory>

#include <entity/IRenderEntity.h>

#include <IViewAPI.h>
#include "entity/render/GetAxiiContainer.h"
#include "entity/render/GetDirectionContainer.h"
#include "entity/render/IsMovingContainer.h"

namespace pacman {
namespace renderer {
namespace entity {

/// <summary>
/// <see cref="RenderEntityFactor"/> provides the methods to construct the
/// different render entities of the pacman game.
/// </summary>
class RenderEntityFactory {
public:  
  /// <summary>
  /// Constructs the PacMan <see cref="IRenderEntity"/>.
  /// </summary>
  /// <returns>
  /// a <see cref="std::unique_ptr{IRenderEntity}"/> containing the constructed
  /// PacMan render entity.
  /// </returns>
  std::unique_ptr<IRenderEntity> ConstructPacManRenderEntity(view::IViewAPI* p_view_api,
                                                             std::unique_ptr<render::GetDirectionContainer> p_direction_container_anim,
                                                             std::unique_ptr<render::GetDirectionContainer> p_direction_container_rotation,
                                                             std::unique_ptr<render::GetAxiiContainer> p_axii_container,
                                                             std::unique_ptr<render::IsMovingContainer> p_is_moving_container) const;
};

}
}
}
