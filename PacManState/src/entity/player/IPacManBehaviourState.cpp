#include "stdafx.h"
#include "entity/player/IPacManBehaviourState.h"
#include "entity/player/PacManBehaviourState.h"


namespace pacman {
namespace state {

std::unique_ptr<IPacManBehaviourState> IPacManBehaviourState::Construct(PacManStateType initial_state) {
  return std::make_unique<PacManBehaviourState>(initial_state);
}

}
}
