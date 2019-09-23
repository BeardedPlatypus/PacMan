#include "pch.h"
#include "entity/UpdatePlayer.h"

namespace pacman {
namespace update {

state::Direction GetOppositeDirection(state::Direction dir) {
  switch (dir)
  {
  case state::Direction::Up:
    return state::Direction::Down;
  case state::Direction::Down:
    return state::Direction::Up;
  case state::Direction::Left:
    return state::Direction::Right;
  case state::Direction::Right:
    return state::Direction::Left;
  }
}

void UpdatePlayerDirection(IUpdatablePlayerEntity* p_player_entity,
                           state::field::IField* p_field) {
  std::optional<state::Direction> opt_next_direction = p_player_entity->GetNextDirection();
  if (!opt_next_direction.has_value()) return;

  state::Direction next_direction = opt_next_direction.value();
  state::Direction moving_direction = p_player_entity->GetMovingDirection();

  if (moving_direction == next_direction) return;
  if (moving_direction == GetOppositeDirection(next_direction)) {
    p_player_entity->SetMovingDirection(next_direction);
    return;
  }

  IUpdatableEntityAxis* p_x_axis = p_player_entity->GetXAxis();
  IUpdatableEntityAxis* p_y_axis = p_player_entity->GetYAxis();

  IUpdatableEntityAxis* p_active_axis;
  if (moving_direction == state::Direction::Up ||
      moving_direction == state::Direction::Down) {
    p_active_axis = p_y_axis;
  }
  else {
    p_active_axis = p_x_axis;
  }

  if (abs(p_active_axis->GetPosition() - p_active_axis->GetCurrentIndex()) > 0.05) {
    return;
  }

  int next_x_pos = p_x_axis->GetCurrentIndex();
  int next_y_pos = p_y_axis->GetCurrentIndex();

  switch (next_direction)
  {
  case state::Direction::Up:
    next_y_pos -= 1;
    break;
  case state::Direction::Down:
    next_y_pos += 1;
    break;
  case state::Direction::Left:
    next_x_pos -= 1;
    break;
  case state::Direction::Right:
    next_x_pos += 1;
    break;
  default:
    break;
  }

  if (p_field->GetTileType(next_x_pos, next_y_pos) == state::field::TileType::Space) {
    p_player_entity->SetMovingDirection(next_direction);
  }
}



void UpdatePlayerLocation(IUpdatablePlayerEntity* p_player_state,
                          state::field::IField* p_field,
                          float dt) {
  state::Direction player_direction = p_player_state->GetMovingDirection();
  IUpdatableEntityAxis* p_x_axis = p_player_state->GetXAxis();
  IUpdatableEntityAxis* p_y_axis = p_player_state->GetYAxis();

  bool is_move_vertical;
  IUpdatableEntityAxis* p_active_axis;
  if (player_direction == state::Direction::Up ||
    player_direction == state::Direction::Down) {
    p_active_axis = p_y_axis;
    is_move_vertical = true;
  }
  else {
    p_active_axis = p_x_axis;
    is_move_vertical = false;
  }


  int direction_val = 1;

  if (player_direction == state::Direction::Up ||
    player_direction == state::Direction::Left) {
    direction_val = -1;
  }

  float d_pos = p_player_state->GetSpeed() * dt;

  int cur_x_index = p_x_axis->GetCurrentIndex();
  int cur_y_index = p_y_axis->GetCurrentIndex();

  int next_x_index = cur_x_index;
  int next_y_index = cur_y_index;

  if (is_move_vertical) {
    next_y_index += direction_val;
  }
  else {
    next_x_index += direction_val;
  }

  state::field::TileType next_tile_type = p_field->GetTileType(next_x_index, next_y_index);

  if (next_tile_type != state::field::TileType::Space) {
    float distance_left = abs(p_active_axis->GetPosition() - (float) p_active_axis->GetCurrentIndex());
    d_pos = fmin(distance_left, d_pos);
  }

  p_active_axis->Move(d_pos * direction_val);
}

}
}