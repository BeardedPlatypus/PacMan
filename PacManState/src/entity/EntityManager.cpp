#include "stdafx.h"
#include "entity/EntityManager.h"


namespace pacman {
namespace state {

EntityManager::EntityManager() {

}


IEntityState* EntityManager::GetPlayerState() const {
  return this->p_player_state.get();
}


void EntityManager::SetPlayerState(std::unique_ptr<IEntityState> p_player_state) {
  this->p_player_state = std::move(p_player_state);
}


}
}
