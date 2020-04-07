#pragma once

#include "entity/IEntityManager.h"
#include "gmock/gmock.h"


class EntityManagerMock: public pacman::state::IEntityManager {
public:
  MOCK_METHOD(pacman::state::IEntityState<pacman::state::IPacManBehaviourState>*, GetPlayerState, (), (const));
  MOCK_METHOD(void, SetPlayerState, (std::unique_ptr<pacman::state::IEntityState<pacman::state::IPacManBehaviourState>> p_player_state));
};
