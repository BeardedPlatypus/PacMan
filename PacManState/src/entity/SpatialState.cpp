#include "stdafx.h"
#include "entity/SpatialState.h"


namespace pacman {
namespace state {


  SpatialState::SpatialState(float x, float y, Direction dir, float speed) :
    _x_axis(EntityAxis(x)), _y_axis(EntityAxis(y)),
    _dir(dir),
    _speed(speed),
    _initial_pos_x(x),
    _initial_pos_y(y),
    _initial_dir(dir), 
    _initial_speed(speed) { }


IEntityAxis* SpatialState::GetXAxis() const {
  return (IEntityAxis*) &(this->_x_axis);
}


IEntityAxis* SpatialState::GetYAxis() const {
  return (IEntityAxis*) &(this->_y_axis);
}


Direction SpatialState::GetDirection() const {
  return this->_dir;
}


void SpatialState::SetDirection(Direction dir) {
  this->_dir = dir;
}


float SpatialState::GetSpeed() const {
  return this->_speed;
}


void SpatialState::SetSpeed(float speed) {
  this->_speed = speed;
}

bool SpatialState::IsMoving() const {
  return this->_is_moving;
}


void SpatialState::SetIsMoving(bool is_moving) {
  this->_is_moving = is_moving;
}


void SpatialState::Reset() {
  this->GetXAxis()->SetPosition(this->_initial_pos_x);
  this->GetYAxis()->SetPosition(this->_initial_pos_y);

  this->SetDirection(this->_initial_dir);
  this->SetSpeed(this->_initial_speed);

  this->_is_moving = false;
}

}
}

