#include "stdafx.h"
#include "IGameState.h"

#include "GameState.h"

namespace pacman {
namespace state {

std::unique_ptr<IGameState> IGameState::Construct() {
  return std::make_unique<GameState>();
}

}
}