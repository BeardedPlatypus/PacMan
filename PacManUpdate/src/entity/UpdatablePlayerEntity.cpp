#include "pch.h"
#include "entity/UpdatablePlayerEntity.h"


namespace pacman {
namespace update {

UpdatablePlayerEntity::UpdatablePlayerEntity(state::IEntityState* p_player_state) :
    p_player_state(p_player_state),
    active_axis(0) {
  this->axii = { 
    IUpdatableEntityAxis::Construct(this->p_player_state->GetXAxis()), 
    IUpdatableEntityAxis::Construct(this->p_player_state->GetYAxis()) 
  };

  this->movement_axii = {
    IPlayerMovementAxis::Construct(),
    IPlayerMovementAxis::Construct(),
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


}
}