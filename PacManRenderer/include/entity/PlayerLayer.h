#pragma once

#include <manager/IViewManager.h>
#include <entity/IEntityManager.h>

#include "IRenderLayer.h"


namespace pacman {
namespace renderer {
  
class PlayerLayer final : public IRenderLayer {
public:  
  /// <summary>
  /// Construct a new <see cref="PlayerLayer" />.
  /// </summary>
  /// <param name="scale">The scale.</param>
  /// <param name="p_view_manager">A pointer to the view manager.</param>
  /// <param name="p_player_state">A pointer to the player state.</param>
  /// <precondition>
  /// | p_view_manager != nullptr
  /// | p_player_state != nullptr
  /// </precondition>
  PlayerLayer(float scale,
              view::IViewManager* p_view_manager,
              state::IEntityState* p_player_state);

  void Initialise() final;
  void Render() const final;

private:    
  /// <summary>
  /// Initialises the sprites used by this <see cref="EntityLayer" />.
  /// </summary>
  void InitialiseSprites();

  /// <summary>
  /// The scale to render with.
  /// </summary>
  const float scale;

  /// <summary>
  /// A pointer to the <see cref="IViewManager" /> used by this 
  /// <see cref="EntityLayer" />. 
  /// </summary>
  view::IViewManager* p_view_manager;
  
  /// <summary>
  /// A pointer to the <see cref="IEntityManager" /> used by this
  /// <see cref="EntityLayer" />. 
  /// </summary>
  state::IEntityState* p_player_state;
};

}
}
