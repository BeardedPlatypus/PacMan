#include "pch.h"
#include "objects/behaviours/WinRoundBehaviour.h"


namespace pacman {
namespace update {
namespace object {


  WinRoundBehaviour::WinRoundBehaviour(state::level::ILevelManager* p_level_manager,
                                       state::field::IFieldObjectManager* p_field_object_manager) :
    _p_level_manager(p_level_manager),
    _p_field_object_manager(p_field_object_manager) { }


void WinRoundBehaviour::Execute(IUpdatablePlayerEntity* p_player_entity) {
  if (this->_p_level_manager->GetDotsLeftInCurrentLevel() == 0) {
    this->_p_field_object_manager->ResetFieldObjects();
    this->_p_level_manager->IncrementCurrentLevel();
    p_player_entity->Reset();
  }
}

}
}
}
