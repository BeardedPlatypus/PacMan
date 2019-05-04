#include "stdafx.h"
#include "PlayerState.h"


namespace pacman {
namespace state {

PlayerState::PlayerState(float x, float y, float speed) : location_x(x), 
                                                          location_y(y),
                                                	      speed(speed) {
}

float PlayerState::getLocationX() const {
  return this->location_x;
}

void PlayerState::setLocationX(float new_x) {
  this->location_x = new_x;
}

float PlayerState::getLocationY() const {
  return this->location_y;
}

void PlayerState::setLocationY(float new_y) {
  this->location_y = new_y;
}

float PlayerState::getSpeed() const {
  return this->speed;
}

void PlayerState::setSpeed(float new_speed) {
  this->speed = new_speed;
}

} // state
} // pacman