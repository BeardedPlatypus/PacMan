#pragma once

#include "objects/behaviours/IObjectBehaviour.h"
#include "entity/IUpdatablePlayerEntity.h"
#include "field/FieldCoordinate.h"

#include <unordered_map>

namespace pacman {
namespace update {
namespace object {

class PortalBehaviour : public IObjectBehaviour {
public:
  PortalBehaviour(IUpdatablePlayerEntity* p_player_entity,
                  const std::unordered_map<const state::field::FieldCoordinate, const state::field::FieldCoordinate>& mapping);

  void Execute(int x, int y) override;
private:
  IUpdatablePlayerEntity* _p_player_entity;

  const std::unordered_map<const state::field::FieldCoordinate, 
                           const state::field::FieldCoordinate>& _portal_mapping;

  void MovePlayerTo(const state::field::FieldCoordinate& new_location);
};

}
}
}
