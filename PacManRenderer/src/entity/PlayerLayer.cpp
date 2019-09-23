#include "pch.h"
#include "entity/PlayerLayer.h"

#include "entity/EntitySpriteValues.h"
#include "field/FieldSpriteValues.h"


namespace pacman {
namespace renderer {

PlayerLayer::PlayerLayer(float scale, 
                         view::IViewManager* p_view_manager,
                         state::IEntityState* p_player_state) :
    scale(scale),
    p_view_manager(p_view_manager),
    p_player_state(p_player_state) { }


void PlayerLayer::Initialise() {
  this->InitialiseSprites();
}


void PlayerLayer::Render() const {  

  float rotation = 0.F;

  switch (this->p_player_state->GetDirection())
  {
  case state::Direction::Down:
    rotation = 90.F;
    break;
  case state::Direction::Left:
    rotation = 180.F;
    break;
  case state::Direction::Up:
    rotation = 270.F;
    break;
  default:
    break;
  }

  this->p_view_manager->renderSprite(values::pacman_default,
                                     (this->p_player_state->GetXAxis()->GetPosition() - 0.5F * 0.5) * (float)values::tile_size * this->scale,
                                     (this->p_player_state->GetYAxis()->GetPosition() - 0.5F * 0.5) * (float)values::tile_size * this->scale,
                                     this->scale * 0.75,
                                     rotation,
                                     false,
                                     false);
}


void PlayerLayer::InitialiseSprites() {
  this->p_view_manager->requestSprite(values::pacman_default,
                                      values::entity_sprite_file,
                                      pacman::view::ClipRect(16, 0, 16, 16));
}

}
}
