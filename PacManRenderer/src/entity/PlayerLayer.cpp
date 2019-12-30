#include "pch.h"
#include "entity/PlayerLayer.h"

#include "entity/EntitySpriteValues.h"
#include "field/FieldSpriteValues.h"


namespace pacman {
namespace renderer {

PlayerLayer::PlayerLayer(float scale, 
                         view::IViewAPI* p_view_api,
                         state::IEntityState* p_player_state) :
    scale(scale),
    p_view_api(p_view_api),
    p_player_state(p_player_state) { }


void PlayerLayer::Initialise() {
  this->InitialiseSprites();
}


void PlayerLayer::Update(float dtime) {
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

  this->p_view_api->RenderSpriteAnimation(values::pacman_moving_anim,
                                          (this->p_player_state->GetXAxis()->GetPosition() - 0.5F * 0.5F) * (float)values::tile_size * this->scale,
                                          (this->p_player_state->GetYAxis()->GetPosition() - 0.5F * 0.5F) * (float)values::tile_size * this->scale,
                                          this->scale * 0.75F,
                                          rotation,
                                          false,
                                          false);
}


void PlayerLayer::InitialiseSprites() {
  this->p_view_api->RequestSprite(values::pacman_default,
                                  values::entity_sprite_file,
                                  16, 0, 16, 16);

  auto anim_0_label = "pacman_moving_anim_0";
  this->p_view_api->RequestSprite(anim_0_label,
                                  values::entity_sprite_file,
                                  0, 0, 16, 16);

  auto anim_2_label = "pacman_moving_anim_2";
  this->p_view_api->RequestSprite(anim_2_label,
                                  values::entity_sprite_file,
                                  32, 0, 16, 16);

  std::vector<std::string> pacman_anim_sprites = {
    anim_0_label,
    values::pacman_default,
    anim_2_label,
    values::pacman_default,
  };

	this->p_view_api->RequestSpriteAnimation(values::pacman_moving_anim, 0.175F, pacman_anim_sprites);
}

}
}
