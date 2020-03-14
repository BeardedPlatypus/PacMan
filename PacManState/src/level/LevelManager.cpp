#include "stdafx.h"
#include "level/LevelManager.h"


namespace pacman {
namespace state {
namespace level {

LevelManager::LevelManager(unsigned int n_dots) : _total_n_dots(n_dots) { }


inline unsigned int LevelManager::GetCurrentLevel() const { 
  return this->_current_level; 
}


void LevelManager::IncrementCurrentLevel() {
  this->_current_level += 1;
  this->_consumed_dots = 0;
}

inline unsigned int LevelManager::GetTotalNDots() const { 
  return this->_total_n_dots; 
}


inline unsigned int LevelManager::GetDotsLeftInCurrentLevel() const {
  return this->GetTotalNDots() - this->GetDotsConsumedInCurrentLevel();
}


inline unsigned int LevelManager::GetDotsConsumedInCurrentLevel() const {
  return this->_consumed_dots;
}


inline void LevelManager::IncrementDotsConsumedInCurrentLevel() {
  this->_consumed_dots += 1;
}

}
}
}
