#include "stdafx.h"
#include "entity/EntityState.h"


namespace pacman {
namespace state {


  EntityState::EntityState(float x, float y, Direction dir, float speed) :
    x_axis(EntityAxis(x)), y_axis(EntityAxis(y)),
    dir(dir),
    speed(speed) { }


IEntityAxis* EntityState::GetXAxis() const {
  return (IEntityAxis*) &(this->x_axis);
}


IEntityAxis* EntityState::GetYAxis() const {
  return (IEntityAxis*) &(this->y_axis);
}


Direction EntityState::GetDirection() const {
  return this->dir;
}


void EntityState::SetDirection(Direction dir) {
  this->dir = dir;
}


float EntityState::GetSpeed() const {
  return this->speed;
}


void EntityState::SetSpeed(float speed) {
  this->speed = speed;
}

}
}

