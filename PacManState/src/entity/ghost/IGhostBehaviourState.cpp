#include "stdafx.h"
#include "entity/ghost/IGhostBehaviourState.h"
#include "entity/ghost/GhostBehaviourState.h"


namespace pacman {
namespace state {

std::unique_ptr<IGhostBehaviourState> IGhostBehaviourState::Construct(GhostStateType initial_state) {
  return std::make_unique<GhostBehaviourState>(initial_state);
}

}
}
