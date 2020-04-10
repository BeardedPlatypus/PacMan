#include "stdafx.h"
#include "entity/EntityManager.h"

namespace pacman {
namespace state {

EntityManager::EntityManager() { }


IEntityState<IPacManBehaviourState>* EntityManager::GetPlayerState() const {
  return this->_p_player_state.get();
}


void EntityManager::SetPlayerState(std::unique_ptr<IEntityState<IPacManBehaviourState>> p_player_state) {
  this->_p_player_state = std::move(p_player_state);
}


IEntityState<IGhostBehaviourState>* EntityManager::GetBlinkyState() const {
  return this->_p_blinky_state.get();
}


void EntityManager::SetBlinkyState(std::unique_ptr<IEntityState<IGhostBehaviourState>> p_blinky_state) {
  this->_p_blinky_state = std::move(p_blinky_state);
}


IEntityState<IGhostBehaviourState>* EntityManager::GetPinkyState() const {
  return this->_p_pinky_state.get();
}


void EntityManager::SetPinkyState(std::unique_ptr<IEntityState<IGhostBehaviourState>> p_pinky_state) {
  this->_p_pinky_state = std::move(p_pinky_state);
}


IEntityState<IGhostBehaviourState>* EntityManager::GetInkyState() const {
  return this->_p_inky_state.get();
}


void EntityManager::SetInkyState(std::unique_ptr<IEntityState<IGhostBehaviourState>> p_inky_state) {
  this->_p_inky_state = std::move(p_inky_state);
}


IEntityState<IGhostBehaviourState>* EntityManager::GetClydeState() const {
  return this->_p_clyde_state.get();
}


void EntityManager::SetClydeState(std::unique_ptr<IEntityState<IGhostBehaviourState>> p_clyde_state) {
  this->_p_clyde_state = std::move(p_clyde_state);
}

}
}
