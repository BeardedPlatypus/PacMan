#include "stdafx.h"
#include "entity/EntityState.h"


namespace pacman {
namespace state {


  EntityState::EntityState(float x, float y, Direction dir, float speed) :
    x(x), y(y),
    dir(dir),
    speed(speed) { }


float EntityState::GetXPosition() const {
  return this->x;
}


void EntityState::SetXPosition(float new_x) {
  this->x = new_x;
}

float EntityState::GetYPosition() const {
  return this->y;
}


void EntityState::SetYPosition(float new_y) {
  this->y = new_y;
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

