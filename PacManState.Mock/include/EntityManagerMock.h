#pragma once

#include "entity/IEntityManager.h"
#include "gmock/gmock.h"


class EntityManagerMock: public pacman::state::IEntityManager {
public:
  MOCK_METHOD(pacman::state::IEntityState<pacman::state::IPacManBehaviourState>*, GetPlayerState, (), (const));
  MOCK_METHOD(void, SetPlayerState, (std::unique_ptr<pacman::state::IEntityState<pacman::state::IPacManBehaviourState>> p_player_state));
  
  MOCK_METHOD(pacman::state::IEntityState<pacman::state::IGhostBehaviourState>*, GetBlinkyState, (), (const));
  MOCK_METHOD(void, SetBlinkyState, (std::unique_ptr<pacman::state::IEntityState<pacman::state::IGhostBehaviourState>> p_blinky_state));

  MOCK_METHOD(pacman::state::IEntityState<pacman::state::IGhostBehaviourState>*, GetPinkyState, (), (const));
  MOCK_METHOD(void, SetPinkyState, (std::unique_ptr<pacman::state::IEntityState<pacman::state::IGhostBehaviourState>> p_pinky_state));

  MOCK_METHOD(pacman::state::IEntityState<pacman::state::IGhostBehaviourState>*, GetInkyState, (), (const));
  MOCK_METHOD(void, SetInkyState, (std::unique_ptr<pacman::state::IEntityState<pacman::state::IGhostBehaviourState>> p_inky_state));

  MOCK_METHOD(pacman::state::IEntityState<pacman::state::IGhostBehaviourState>*, GetClydeState, (), (const));
  MOCK_METHOD(void, SetClydeState, (std::unique_ptr<pacman::state::IEntityState<pacman::state::IGhostBehaviourState>> p_clyde_state));
};
