#include "pch.h"
#include "objects/behaviours/RemoveObjectBehaviour.h"


namespace pacman {
namespace update {
namespace object {

RemoveObjectBehaviour::RemoveObjectBehaviour(state::field::IFieldObjectManager* p_object_manager) :
    _p_object_manager(p_object_manager) { }


void RemoveObjectBehaviour::Execute(IUpdatablePlayerEntity* p_entity) {
  this->_p_object_manager->RemoveFieldObject(p_entity->GetXAxis()->GetCurrentIndex(),
                                             p_entity->GetYAxis()->GetCurrentIndex());
  
}

}
}
}