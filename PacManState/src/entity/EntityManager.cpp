#include "stdafx.h"
#include "entity/EntityManager.h"

namespace pacman {
namespace state {

EntityManager::EntityManager() { }


IEntityState<IPacManBehaviourState>* EntityManager::GetPlayerState() const {
  return this->p_player_state.get();
}


void EntityManager::SetPlayerState(std::unique_ptr<IEntityState<IPacManBehaviourState>> p_new_player_state) {
  this->p_player_state = std::move(p_new_player_state);
}

}
}
