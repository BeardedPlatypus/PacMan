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


bool ShouldFlipDirection(AxisDirection next_dir,
                         AxisDirection cur_dir) {
  return next_dir != AxisDirection::None && next_dir != cur_dir;
}


bool HasOtherDirection(IUpdatablePlayerEntity* p_player_entity) {
  return p_player_entity->GetInactivePlayerMovementAxis()->GetNextDirection() != AxisDirection::None;
}


bool IsAtTileCenter(IUpdatablePlayerEntity* p_player_entity) {
  return abs(p_player_entity->GetActiveAxis()->GetPosition() -
             p_player_entity->GetActiveAxis()->GetCurrentIndex()) < 0.05;
}


AxisDirection GetOppositeDirection(AxisDirection direction) {
  switch (direction)
  {
  case AxisDirection::Positive:
    return AxisDirection::Negative;
  case AxisDirection::Negative:
    return AxisDirection::Positive;
  case AxisDirection::None:
  default:
    return AxisDirection::None;
  }
}


void SetActiveDirection(IUpdatablePlayerEntity* p_player_entity,
                        AxisDirection next_direction) {
  p_player_entity->GetActiveAxis()->SetCurrentAxisDirection(next_direction);
}

void UpdatePlayerDirection(IUpdatablePlayerEntity* p_player_entity,
                           state::field::IField* p_field) {
  AxisDirection next_active_direction =
    p_player_entity->GetActivePlayerMovementAxis()->GetNextDirection();
  AxisDirection cur_active_direction =
    p_player_entity->GetActiveAxis()->GetCurrentAxisDirection();

  if (ShouldFlipDirection(next_active_direction, cur_active_direction)) {
    SetActiveDirection(p_player_entity, next_active_direction);
    return;
  }

  if (!IsAtTileCenter(p_player_entity) ||
      !HasOtherDirection(p_player_entity)) {
    return;
  }

  IUpdatableEntityAxis* p_active_axis = 
    p_player_entity->GetActiveAxis();

  int next_pos_x_location = p_player_entity->GetXAxis()->GetCurrentIndex();
  int next_pos_y_location = p_player_entity->GetYAxis()->GetCurrentIndex();

  if (p_player_entity->GetActiveAxisType() == AxisType::X) {
    switch (p_player_entity->GetPlayerMovementYAxis()->GetNextDirection())
    {
    case AxisDirection::Positive:
      next_pos_y_location += 1;
      break;
    case AxisDirection::Negative:
      next_pos_y_location -= 1;
      break;
    case AxisDirection::None:
    default:
      break;
    }
  }
  else {
    switch (p_player_entity->GetPlayerMovementXAxis()->GetNextDirection())
    {
    case AxisDirection::Positive:
      next_pos_x_location += 1;
      break;
    case AxisDirection::Negative:
      next_pos_x_location -= 1;
      break;
    case AxisDirection::None:
    default:
      break;
    }
  }

  if (p_field->GetTileType(next_pos_x_location, next_pos_y_location) == state::field::TileType::Space) {
    if (p_player_entity->GetActiveAxisType() == AxisType::X)
      p_player_entity->SetActiveAxisType(AxisType::Y);
    else
      p_player_entity->SetActiveAxisType(AxisType::X);
  }
}


void UpdatePlayerLocation(IUpdatablePlayerEntity* p_player_state,
                          state::field::IField* p_field,
                          float dt) {
  IUpdatableEntityAxis* p_x_axis = p_player_state->GetXAxis();
  IUpdatableEntityAxis* p_y_axis = p_player_state->GetYAxis();

  IUpdatableEntityAxis* p_active_axis = p_player_state->GetActiveAxis();
  bool is_move_vertical = p_player_state->GetActiveAxisType() == AxisType::Y;

  int direction_val;

  switch (p_active_axis->GetCurrentAxisDirection())
  {
  case AxisDirection::Negative:
    direction_val = -1;
    break;
  case AxisDirection::Positive:
    direction_val = 1;
    break;
  case AxisDirection::None:
    direction_val = 0;
    break;
  default:
    break;
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