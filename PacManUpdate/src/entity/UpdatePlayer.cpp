#include "pch.h"
#include "entity/UpdatePlayer.h"


namespace pacman {
namespace update {

void UpdatePlayer(state::IEntityState* p_player_state,
                  state::field::IField* p_field,
                  float dt) {
  state::Direction player_direction = p_player_state->GetDirection();
  float direction_val = 1.F;
  
  if (player_direction == state::Direction::Up ||
    player_direction == state::Direction::Left) {
    direction_val = -1.F;
  }

  auto d_pos = p_player_state->GetSpeed() * dt * direction_val;
  if (player_direction == state::Direction::Up ||
      player_direction == state::Direction::Down) {
    p_player_state->SetYPosition(p_player_state->GetYPosition() + d_pos);
  }
  else {
    p_player_state->SetXPosition(p_player_state->GetXPosition() + d_pos);
  }

}

}
}