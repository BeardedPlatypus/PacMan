#include "stdafx.h"
#include "entity/PacManBehaviourState.h"

namespace pacman {
namespace state {

PacManBehaviourState::PacManBehaviourState(PacManStateType initial_state) :
    _state_type(initial_state) { }


inline PacManStateType PacManBehaviourState::GetState() const {
  return this->_state_type;
}


inline void PacManBehaviourState::SetState(PacManStateType state) {
  this->_state_type = state;
}

}
}
