#pragma once

#include <IViewAPI.h>
#include <entity/IEntityManager.h>

#include "IRenderLayer.h"
#include "entity/PlayerMovementAnimation.h"

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
              view::IViewAPI* p_view_api,
              state::IEntityState* p_player_state,
              float render_offset_y);

  void Initialise() final;
  void Update(float dtime);
  void Render() const final;

private:    
  /// <summary>
  /// Initialises the sprites used by this <see cref="EntityLayer" />.
  /// </summary>
  void InitialiseSprites();

  void UpdateActiveAnimation(PlayerMovementAnimation next_anim);

  PlayerMovementAnimation GetNextAnimation() const;

  PlayerMovementAnimation active_anim = PlayerMovementAnimation::Forward;

  const std::string& GetActiveAnimationLabel() const;

  /// <summary>
  /// The scale to render with.
  /// </summary>
  const float scale;

  /// <summary>
  /// A pointer to the <see cref="IViewManager" /> used by this 
  /// <see cref="EntityLayer" />. 
  /// </summary>
  view::IViewAPI* p_view_api;
  
  /// <summary>
  /// A pointer to the <see cref="IEntityManager" /> used by this
  /// <see cref="EntityLayer" />. 
  /// </summary>
  state::IEntityState* p_player_state;

  /// <summary>
  /// The render offset of this layer
  /// </summary>
  const float render_offset_y;
};

}
}
