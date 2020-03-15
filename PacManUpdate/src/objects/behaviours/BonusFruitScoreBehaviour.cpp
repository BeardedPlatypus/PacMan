#include "pch.h"
#include "objects/behaviours/BonusFruitScoreBehaviour.h"


namespace pacman {
namespace update {
namespace object {


BonusFruitScoreBehaviour::BonusFruitScoreBehaviour(state::score::IScoreBoard* p_score_board,
                                                   const state::level::ILevelManager* p_level_manager) :
    AbstractScoreBehaviour(p_score_board),
    _p_level_manager(p_level_manager) { }


unsigned int BonusFruitScoreBehaviour::GetScoreIncrement() const {
  if (this->_p_level_manager->GetCurrentLevel() < 1) {
    return 100;
  }

  if (this->_p_level_manager->GetCurrentLevel() < 2) {
    return 300;
  }
  
  if (this->_p_level_manager->GetCurrentLevel() < 3) {
    return 500;
  }

  if (this->_p_level_manager->GetCurrentLevel() < 5) {
    return 700;
  }

  if (this->_p_level_manager->GetCurrentLevel() < 7) {
    return 1000;
  }

  if (this->_p_level_manager->GetCurrentLevel() < 9) {
    return 2000;
  }

  if (this->_p_level_manager->GetCurrentLevel() < 11) {
    return 3000;
  }

  return 5000;
}

}
}
}
