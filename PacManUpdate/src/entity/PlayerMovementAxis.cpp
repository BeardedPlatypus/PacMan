#include "pch.h"
#include "entity/PlayerMovementAxis.h"

#include <exception>


namespace pacman {
namespace update {

PlayerMovementAxis::PlayerMovementAxis() : 
    time_elapsed(0.F), 
    current_state(InternalState::NoPressed) {
}


void PlayerMovementAxis::Update(float dt) {
  if (this->current_state == InternalState::NegativeReleased ||
      this->current_state == InternalState::PositiveReleased) {
    this->time_elapsed += dt;

    if (this->time_elapsed >= sticky_key_time) {
      this->current_state = InternalState::NoPressed;
    }
  }
}


AxisDirection PlayerMovementAxis::GetNextDirection() const {
  switch (this->current_state)
  {
  case InternalState::NoPressed:
    return AxisDirection::None;
  case InternalState::PositivePressed:
  case InternalState::PositiveReleased:
  case InternalState::NegativeThenPositivePressed:
    return AxisDirection::Positive;
  case InternalState::NegativePressed:
  case InternalState::NegativeReleased:
  case InternalState::PositiveThenNegativePressed:
    return AxisDirection::Negative;
  default:
    throw std::exception();
  }
}


void PlayerMovementAxis::ChangeState(AxisDirection changed_event_arg) {
  switch (this->current_state)
  {
  case InternalState::NoPressed:
  case InternalState::PositiveReleased:
  case InternalState::NegativeReleased:
    switch (changed_event_arg)
    {
    case pacman::update::AxisDirection::Positive:
      this->current_state = InternalState::PositivePressed;
      break;
    case pacman::update::AxisDirection::Negative:
      this->current_state = InternalState::NegativePressed;
      break;
    default:
      break;
    }
    break;
  case InternalState::PositivePressed:
    switch (changed_event_arg)
    {
    case pacman::update::AxisDirection::Positive:
      this->current_state = InternalState::PositiveReleased;
      break;
    case pacman::update::AxisDirection::Negative:
      this->current_state = InternalState::PositiveThenNegativePressed;
      break;
    default:
      break;
    }
    break;
  case InternalState::NegativeThenPositivePressed:
  case InternalState::PositiveThenNegativePressed:
    switch (changed_event_arg)
    {
    case pacman::update::AxisDirection::Positive:
      this->current_state = InternalState::NegativePressed;
      break;
    case pacman::update::AxisDirection::Negative:
      this->current_state = InternalState::PositivePressed;
      break;
    default:
      break;
    }
    break;
  case InternalState::NegativePressed:
    switch (changed_event_arg)
    {
    case pacman::update::AxisDirection::Positive:
      this->current_state = InternalState::NegativeThenPositivePressed;
      break;
    case pacman::update::AxisDirection::Negative:
      this->current_state = InternalState::NegativeReleased;
      break;
    default:
      break;
    }
  default:
    throw std::exception();
  }
}


}
}
