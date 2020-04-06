#include "stdafx.h"
#include "entity/IPacManBehaviourState.h"
#include "entity/PacManBehaviourState.h"


namespace pacman {
namespace state {

std::unique_ptr<IPacManBehaviourState> IPacManBehaviourState::Construct(PacManStateType initial_state) {
  return std::make_unique<PacManBehaviourState>(initial_state);
}

}
}
