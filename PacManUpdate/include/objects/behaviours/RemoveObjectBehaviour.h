#pragma once

#include "objects/behaviours/IObjectBehaviour.h"
#include "field/object/IFieldObjectManager.h"

namespace pacman {
namespace update {
namespace object {

class RemoveObjectBehaviour : public IObjectBehaviour {
public:
  explicit RemoveObjectBehaviour(state::field::IFieldObjectManager* p_object_manager);

  void Execute(IUpdatablePlayerEntity* p_entity) override;

private:
  state::field::IFieldObjectManager* _p_object_manager;
};

}
}
}
