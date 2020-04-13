#pragma once

#include <memory>

#include <entity/IRenderEntity.h>
#include "entity/IEntityState.h"

#include "entity/player/IPacManBehaviourState.h"
#include "entity/ghost/IGhostBehaviourState.h"
#include "entity/ghost/GhostEntityType.h"

#include <IViewAPI.h>

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
                                                             state::IEntityState<state::IPacManBehaviourState>* p_entity_state) const;

  std::unique_ptr<IRenderEntity> ConstructGhostRenderEntity(view::IViewAPI* p_view_api,
                                                            state::GhostEntityType ghost_type,
                                                            state::IEntityState<state::IGhostBehaviourState>* p_entity_state) const;
};

}
}
}
