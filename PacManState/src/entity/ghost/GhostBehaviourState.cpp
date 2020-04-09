#include "stdafx.h"
#include "entity/ghost/GhostBehaviourState.h"

namespace pacman {
namespace state {

GhostBehaviourState::GhostBehaviourState(GhostStateType initial_state) :
    _state_type(initial_state) { }


inline GhostStateType GhostBehaviourState::GetState() const {
  return this->_state_type;
}


inline void GhostBehaviourState::SetState(GhostStateType state) {
  this->_state_type = state;
}

}
}
