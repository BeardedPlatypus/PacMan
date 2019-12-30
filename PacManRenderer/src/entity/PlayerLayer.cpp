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
  PlayerMovementAnimation next_anim = this->GetNextAnimation();

  if (next_anim != this->active_anim) {
    this->UpdateActiveAnimation(next_anim);
  }

  this->p_view_api->UpdateAnimation(this->GetActiveAnimationLabel(), dtime);
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

  this->p_view_api->RenderSpriteAnimation(this->GetActiveAnimationLabel(),
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

  std::vector<std::string> pacman_anim_back_sprites = {
    values::pacman_default,
    anim_2_label,
    values::pacman_default,
    anim_0_label,
  };

	this->p_view_api->RequestSpriteAnimation(values::pacman_moving_anim_back, 0.175F, pacman_anim_sprites);
}


PlayerMovementAnimation PlayerLayer::GetNextAnimation() const {
  state::Direction current_direction = this->p_player_state->GetDirection();

  if (current_direction == state::Direction::Down ||
      current_direction == state::Direction::Right) {
    return PlayerMovementAnimation::Forward;
  }
  else {
    return PlayerMovementAnimation::Backward;
  }
}


const std::string& ToLabel(PlayerMovementAnimation anim) {
  if (anim == PlayerMovementAnimation::Forward) {
    return values::pacman_moving_anim;
  }
  else {
    return values::pacman_moving_anim_back;
  }
}


void PlayerLayer::UpdateActiveAnimation(PlayerMovementAnimation next_anim) {
  const std::string& label = ToLabel(next_anim);

  float prev_time = this->p_view_api->GetAnimationTime(this->GetActiveAnimationLabel());
  float anim_time = 0.175F * 4.F;
  float new_time = anim_time - prev_time;

  this->p_view_api->SetAnimationToTime(label, new_time);
  this->active_anim = next_anim;
}


const std::string& PlayerLayer::GetActiveAnimationLabel() const {
  return ToLabel(this->active_anim);
}




}
}
