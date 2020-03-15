#include "pch.h"
#include "entity/UpdatablePlayerEntity.h"


namespace pacman {
namespace update {

UpdatablePlayerEntity::UpdatablePlayerEntity(state::IEntityState* p_player_state,
                                             std::unique_ptr<IUpdatableEntityAxis> p_x_axis,
                                             std::unique_ptr<IUpdatableEntityAxis> p_y_axis,
                                             std::unique_ptr<IPlayerMovementAxis> p_x_movement_axis,
                                             std::unique_ptr<IPlayerMovementAxis> p_y_movement_axis) :
    p_player_state(p_player_state) {
  this->axii = {
    std::move(p_x_axis),
    std::move(p_y_axis),
  };

  this->movement_axii = {
    std::move(p_x_movement_axis),
    std::move(p_y_movement_axis),
  };
}

inline AxisType UpdatablePlayerEntity::GetActiveAxisType() const {
  if (this->active_axis == 0) {
    return AxisType::X;
  }
  else {
    return AxisType::Y;
  }
}


inline void UpdatablePlayerEntity::SetActiveAxisType(AxisType new_active_axis_type) {
  if (new_active_axis_type == AxisType::X) {
    this->active_axis = 0;
  }
  else {
    this->active_axis = 1;
  }
}


inline IUpdatableEntityAxis* UpdatablePlayerEntity::GetXAxis() const {
  return this->axii[0].get();
}


inline IUpdatableEntityAxis* UpdatablePlayerEntity::GetYAxis() const {
  return this->axii[1].get();
}


inline IUpdatableEntityAxis* UpdatablePlayerEntity::GetActiveAxis() const {
  return this->axii[this->active_axis].get();
}


inline IPlayerMovementAxis* UpdatablePlayerEntity::GetPlayerMovementXAxis() const {
  return this->movement_axii[0].get();
}


inline IPlayerMovementAxis* UpdatablePlayerEntity::GetPlayerMovementYAxis() const {
  return this->movement_axii[1].get();
}


inline IPlayerMovementAxis* UpdatablePlayerEntity::GetActivePlayerMovementAxis() const {
  return this->movement_axii[this->active_axis].get();
}


inline IPlayerMovementAxis* UpdatablePlayerEntity::GetInactivePlayerMovementAxis() const {
  return this->movement_axii[abs(this->active_axis - 1)].get();
}


inline void UpdatablePlayerEntity::SwapActiveAxis() {
  this->active_axis = abs(this->active_axis - 1);
}


inline float UpdatablePlayerEntity::GetSpeed() const {
  return this->p_player_state->GetSpeed();
}


inline state::Direction UpdatablePlayerEntity::GetMovingDirection() const {
  return this->p_player_state->GetDirection();
}


inline void UpdatablePlayerEntity::SetMovingDirection(state::Direction direction) {
  this->p_player_state->SetDirection(direction);
}


void UpdatablePlayerEntity::Update(float dt) {
  this->movement_axii[0]->Update(dt);
  this->movement_axii[1]->Update(dt);
}


void UpdatablePlayerEntity::SetIsMoving(bool is_moving) {
  this->p_player_state->SetIsMoving(is_moving);
}


inline void UpdatablePlayerEntity::Reset() {
  this->p_player_state->Reset();
  this->GetXAxis()->SetCurrentAxisDirection(AxisDirection::None);
  this->GetYAxis()->SetCurrentAxisDirection(AxisDirection::None);
  this->GetPlayerMovementXAxis()->ChangeState(state_machine::PlayerControlEvent::Reset);
  this->GetPlayerMovementYAxis()->ChangeState(state_machine::PlayerControlEvent::Reset);
  this->SetActiveAxisType(AxisType::X);
}

}
}
