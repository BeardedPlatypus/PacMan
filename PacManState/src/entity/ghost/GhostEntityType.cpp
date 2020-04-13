#include "stdafx.h"
#include "entity/ghost/GhostEntityType.h"


namespace pacman {
namespace state {

std::string GetGhostName(GhostEntityType ghost_type) {
	switch (ghost_type)
	{
  case pacman::state::GhostEntityType::Blinky:
    return "blinky";
  case pacman::state::GhostEntityType::Pinky:
    return "pinky";
  case pacman::state::GhostEntityType::Inky:
    return "inky";
  case pacman::state::GhostEntityType::Clyde:
    return "clyde";
  default:
    return "none";
	}
}

}
}
