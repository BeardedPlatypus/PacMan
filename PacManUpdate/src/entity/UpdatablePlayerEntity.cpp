#include "pch.h"
#include "entity/UpdatablePlayerEntity.h"


namespace pacman {
namespace update {

UpdatablePlayerEntity::UpdatablePlayerEntity(state::IEntityState* p_player_state) :
    p_player_state(p_player_state) {
  this->p_x_axis = IUpdatableEntityAxis::Construct(this->p_player_state->GetXAxis());
  this->p_y_axis = IUpdatableEntityAxis::Construct(this->p_player_state->GetYAxis());
}


IUpdatableEntityAxis* UpdatablePlayerEntity::GetXAxis() const {
  return this->p_x_axis.get();
}


IUpdatableEntityAxis* UpdatablePlayerEntity::GetYAxis() const {
  return this->p_y_axis.get();
}


float UpdatablePlayerEntity::GetSpeed() const {
  return this->p_player_state->GetSpeed();
}


state::Direction UpdatablePlayerEntity::GetMovingDirection() const {
  return this->p_player_state->GetDirection();
}


void UpdatablePlayerEntity::SetMovingDirection(state::Direction direction) {
  this->p_player_state->SetDirection(direction);
}


std::optional<state::Direction> UpdatablePlayerEntity::GetNextDirection() const {
  return this->next_direction;
}


void UpdatablePlayerEntity::SetNextDirection(std::optional<state::Direction> direction) {
  this->next_direction = direction;
}

}
}