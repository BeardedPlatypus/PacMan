#include "stdafx.h"
#include "entity/IEntityManager.h"

#include "entity/EntityManager.h"


namespace pacman {
namespace state {

std::unique_ptr<IEntityManager> IEntityManager::Construct() {
  return std::make_unique<EntityManager>();
}

}
}
