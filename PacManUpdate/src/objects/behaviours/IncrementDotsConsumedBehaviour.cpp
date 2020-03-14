#include "pch.h"
#include "objects/behaviours/IncrementDotsConsumedBehaviour.h"


namespace pacman {
namespace update {
namespace object {

IncrementDotsConsumedBehaviour::IncrementDotsConsumedBehaviour(state::level::ILevelManager* p_level_manager) :
    _p_level_manager(p_level_manager) { }


inline void IncrementDotsConsumedBehaviour::Execute(IUpdatablePlayerEntity* p_entity) {
  this->_p_level_manager->IncrementDotsConsumedInCurrentLevel();
}

}
}
}
