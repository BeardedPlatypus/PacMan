#include "stdafx.h"
#include "entity/EntityState.h"


namespace pacman {
namespace state {


  EntityState::EntityState(float x, float y, Direction dir, float speed) :
    _x_axis(EntityAxis(x)), _y_axis(EntityAxis(y)),
    _dir(dir),
    _speed(speed),
    _initial_pos_x(x),
    _initial_pos_y(y),
    _initial_dir(dir), 
    _initial_speed(speed) { }


IEntityAxis* EntityState::GetXAxis() const {
  return (IEntityAxis*) &(this->_x_axis);
}


IEntityAxis* EntityState::GetYAxis() const {
  return (IEntityAxis*) &(this->_y_axis);
}


Direction EntityState::GetDirection() const {
  return this->_dir;
}


void EntityState::SetDirection(Direction dir) {
  this->_dir = dir;
}


float EntityState::GetSpeed() const {
  return this->_speed;
}


void EntityState::SetSpeed(float speed) {
  this->_speed = speed;
}

bool EntityState::IsMoving() const {
  return this->_is_moving;
}


void EntityState::SetIsMoving(bool is_moving) {
  this->_is_moving = is_moving;
}


void EntityState::Reset() {
  this->GetXAxis()->SetPosition(this->_initial_pos_x);
  this->GetYAxis()->SetPosition(this->_initial_pos_y);

  this->SetDirection(this->_initial_dir);
  this->SetSpeed(this->_initial_speed);

  this->_is_moving = false;
}

}
}

