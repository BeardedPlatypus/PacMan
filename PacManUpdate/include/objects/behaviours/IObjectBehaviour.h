#pragma once
#include "entity/IUpdatablePlayerEntity.h"


namespace pacman {
namespace update {
namespace object {

class IObjectBehaviour {
public:
  virtual ~IObjectBehaviour() = default;

  virtual void Execute(IUpdatablePlayerEntity* p_entity, int x, int y) = 0;
};

}
}
}
