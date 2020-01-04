#pragma once

#include "objects/behaviours/IObjectBehaviour.h"
#include "entity/IUpdatablePlayerEntity.h"
#include "IGameState.h"

#include <unordered_map>

namespace pacman {
namespace update {
namespace object {

class PortalBehaviour : public IObjectBehaviour {
public:
  PortalBehaviour(const state::field::IField* p_field,
                  const std::unordered_map<int, int> mapping);

  void Execute(IUpdatablePlayerEntity* p_entity, int x, int y) override;
private:
  const state::field::IField* _p_field;

  const std::unordered_map<state::field::FieldIndex, state::field::FieldIndex> _portal_mapping;

  void MovePlayerTo(IUpdatablePlayerEntity* p_entity,
                    state::field::FieldIndex new_location);
};

}
}
}
