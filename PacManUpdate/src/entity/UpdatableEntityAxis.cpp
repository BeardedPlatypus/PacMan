#include "pch.h"
#include "entity/UpdatableEntityAxis.h"


namespace pacman {
namespace update {

UpdatableEntityAxis::UpdatableEntityAxis(state::IEntityAxis* p_axis) : p_axis(p_axis) {
  this->previous_index = this->GetCurrentIndex();
}


float UpdatableEntityAxis::GetPosition() const {
  return this->p_axis->GetPosition();
}


int UpdatableEntityAxis::GetCurrentIndex() const {
  return (int)floorf(this->GetPosition() + 0.5F);
}


int UpdatableEntityAxis::GetPreviousIndex() const {
  return this->previous_index;
}


int UpdatableEntityAxis::GetNextTileCenter() const {
  float pos = this->GetPosition();
  

  if (this->GetCurrentAxisDirection() == AxisDirection::Positive) {
    return (int)ceilf(pos);
  }
  else {
    return (int)floorf(pos);
  }
}


int UpdatableEntityAxis::GetPreviousTileCenter() const {
  float pos = this->GetPosition();
  if (this->GetCurrentAxisDirection() == AxisDirection::Positive) {
    return (int)floorf(pos);
  }
  else {
    return (int)ceilf(pos);
  }
}


void UpdatableEntityAxis::Move(float d_pos) {
  this->previous_index = this->GetCurrentIndex();
  this->p_axis->SetPosition(this->GetPosition() + d_pos);
}

}
}