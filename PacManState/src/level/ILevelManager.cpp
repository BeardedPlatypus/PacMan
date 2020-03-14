#include "stdafx.h"
#include "level/ILevelManager.h"
#include "level/LevelManager.h"


namespace pacman {
namespace state {
namespace level {

std::unique_ptr<ILevelManager> ILevelManager::Construct(unsigned int n_dots) {
  return std::make_unique<LevelManager>(n_dots);
}

}
}
}
