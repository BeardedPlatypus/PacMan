#include "pch.h"
#include "entity/util/PlayerUpdateUtils.h"


namespace pacman {
namespace update {
namespace util {

bool IsActive(const IUpdatablePlayerEntity* p_player_entity) {
  return !(p_player_entity->GetActiveAxis()->GetCurrentAxisDirection() == AxisDirection::None &&
           p_player_entity->GetActivePlayerMovementAxis()->GetNextDirection() == AxisDirection::None);
}


bool ShouldUpdateDirectionActiveAxis(const IUpdatablePlayerEntity* p_player_entity) {
  AxisDirection next_active_direction =
    p_player_entity->GetActivePlayerMovementAxis()->GetNextDirection();
  AxisDirection cur_active_direction =
    p_player_entity->GetActiveAxis()->GetCurrentAxisDirection();

  return next_active_direction != AxisDirection::None && 
         next_active_direction != cur_active_direction;
}


void UpdateDirectionActiveAxis(const IUpdatablePlayerEntity* p_player_entity) {
  IUpdatableEntityAxis* p_active_axis = p_player_entity->GetActiveAxis();
  const IPlayerMovementAxis* p_movement_axis = p_player_entity->GetActivePlayerMovementAxis();

  p_active_axis->SetCurrentAxisDirection(p_movement_axis->GetNextDirection());
}


inline int GetDirectionValue(AxisDirection direction) {
  switch (direction)
  {
  case AxisDirection::Negative:
    return -1;
  case AxisDirection::Positive:
    return 1;
  default:
    return 0;
  }
}


bool HasOtherDirection(const IUpdatablePlayerEntity* p_player_entity) {
  return p_player_entity->GetInactivePlayerMovementAxis()->GetNextDirection() != AxisDirection::None;
}


float GetDistanceToNextCenter(const IUpdatablePlayerEntity* p_player_entity) {
  const IUpdatableEntityAxis* p_active_axis = p_player_entity->GetActiveAxis();

  float pos = p_active_axis->GetPosition();
  return abs(pos - p_active_axis->GetNextTileCenter());
}


float GetDistanceToPreviousCenter(const IUpdatablePlayerEntity* p_player_entity) {
  const IUpdatableEntityAxis* p_active_axis = p_player_entity->GetActiveAxis();

  float pos = p_active_axis->GetPosition();
  return abs(pos - p_active_axis->GetPreviousTileCenter());
}


bool CanMoveToPosition(const state::field::IField* p_field, int x, int y) {
  state::field::TileType next_tile_type = p_field->GetTileType(x, y);
  return next_tile_type == state::field::TileType::Space;
}


bool CanMoveInNextDirectionAtNextTileCenter(const IUpdatablePlayerEntity* p_player_entity,
                                            const state::field::IField* p_field) {
  const IUpdatableEntityAxis* x_axis = p_player_entity->GetXAxis();
  const IUpdatableEntityAxis* y_axis = p_player_entity->GetYAxis();

  int next_x; 
  int next_y;

  int direction_val = GetDirectionValue(p_player_entity->GetInactivePlayerMovementAxis()->GetNextDirection());
  if (p_player_entity->GetActiveAxisType() == AxisType::X) {
    next_x = x_axis->GetNextTileCenter();
    next_y = y_axis->GetCurrentIndex() + direction_val;
  }
  else {
    next_x = x_axis->GetCurrentIndex() + direction_val;
    next_y = y_axis->GetNextTileCenter();
  }

  return CanMoveToPosition(p_field, next_x, next_y);
}


bool CanMoveInNextDirectionAtPreviousTileCenter(const IUpdatablePlayerEntity* p_player_entity,
                                                const state::field::IField* p_field) {
  const IUpdatableEntityAxis* x_axis = p_player_entity->GetXAxis();
  const IUpdatableEntityAxis* y_axis = p_player_entity->GetYAxis();

  int next_x; 
  int next_y;

  int direction_val = GetDirectionValue(p_player_entity->GetInactivePlayerMovementAxis()->GetNextDirection());
  if (p_player_entity->GetActiveAxisType() == AxisType::X) {
    next_x = x_axis->GetPreviousTileCenter();
    next_y = y_axis->GetCurrentIndex() + direction_val;
  }
  else {
    next_x = x_axis->GetCurrentIndex() + direction_val;
    next_y = y_axis->GetPreviousTileCenter();
  }

  return CanMoveToPosition(p_field, next_x, next_y);
}


void MoveOnActiveAxis(const IUpdatablePlayerEntity* p_player_entity,
                      float distance,
                      bool moveInOppositeDirection) {
  int direction_val = GetDirectionValue(p_player_entity->GetActiveAxis()->GetCurrentAxisDirection());
  
  if (moveInOppositeDirection) direction_val *= -1;

  p_player_entity->GetActiveAxis()->Move(distance * direction_val);
}

float GetConfinedDistanceToMove(const IUpdatablePlayerEntity* p_player_entity,
                                const state::field::IField* p_field,
                                float max_distance_to_move) {
  float distance_to_move = max_distance_to_move;

  const IUpdatableEntityAxis* p_active_axis = p_player_entity->GetActiveAxis();
  bool is_move_vertical = p_player_entity->GetActiveAxisType() == AxisType::Y;

  int direction_val = GetDirectionValue(p_active_axis->GetCurrentAxisDirection());

  int next_x_index = p_player_entity->GetXAxis()->GetCurrentIndex();
  int next_y_index = p_player_entity->GetYAxis()->GetCurrentIndex();

  if (is_move_vertical) {
    next_y_index += direction_val;
  }
  else {
    next_x_index += direction_val;
  }

  if (!CanMoveToPosition(p_field, next_x_index, next_y_index)) {
    float distance_left = abs(p_active_axis->GetPosition() - (float) p_active_axis->GetCurrentIndex());
    distance_to_move = fmin(distance_left, distance_to_move);
  }

  return distance_to_move;
}


void ConditiallyMoveDistance(IUpdatablePlayerEntity* p_player_entity,
                             const state::field::IField* p_field,
                             float max_distance_to_move) {
  float distance_to_move = util::GetConfinedDistanceToMove(p_player_entity, 
                                                           p_field, 
                                                           max_distance_to_move);

  if (abs(distance_to_move) < 0.00001) {
    p_player_entity->SetIsMoving(false);
  }
  else {
    p_player_entity->SetIsMoving(true);
    MoveOnActiveAxis(p_player_entity, distance_to_move);
  }

}


void UpdateDirection(IUpdatablePlayerEntity* p_player_entity) {
  AxisType axis_type = p_player_entity->GetActiveAxisType();
  AxisDirection axis_direction = p_player_entity->GetActiveAxis()->GetCurrentAxisDirection();

  if (axis_type == AxisType::X) {
    if (axis_direction == AxisDirection::Negative) {
      p_player_entity->SetMovingDirection(state::Direction::Left);
    }
    else if (axis_direction == AxisDirection::Positive){
      p_player_entity->SetMovingDirection(state::Direction::Right);
    }
  }
  else if (axis_type == AxisType::Y) {
    if (axis_direction == AxisDirection::Negative) {
      p_player_entity->SetMovingDirection(state::Direction::Up);
    }
    else if (axis_direction == AxisDirection::Positive){
      p_player_entity->SetMovingDirection(state::Direction::Down);
    }
  }
}


void UpdatePreviousDirection(const IUpdatablePlayerEntity* p_player_entity) {
  p_player_entity->GetActiveAxis()->SetPreviousAxisDirection(p_player_entity->GetActiveAxis()->GetCurrentAxisDirection());
}

}
}
}
