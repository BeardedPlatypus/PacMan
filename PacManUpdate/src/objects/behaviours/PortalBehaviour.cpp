#include "pch.h"
#include "objects/behaviours/PortalBehaviour.h"


namespace pacman {
namespace update {
namespace object {

PortalBehaviour::PortalBehaviour(const state::field::IField* p_field,
                                 const std::unordered_map<state::field::FieldIndex, state::field::FieldIndex> mapping) :
    _p_field(p_field),
    _portal_mapping(mapping) {
}


void PortalBehaviour::Execute(IUpdatablePlayerEntity* p_entity, int x, int y) {
  state::field::FieldIndex index = this->_p_field->GetFieldIndex(x, y);

  if (this->_portal_mapping.find(index) == this->_portal_mapping.cend()) {
    return;
  }

  this->MovePlayerTo(p_entity, this->_portal_mapping.at(index));
}


void PortalBehaviour::MovePlayerTo(IUpdatablePlayerEntity* p_entity,
                                   state::field::FieldIndex new_location) {
  float x_loc = this->_p_field->GetXFromFieldIndex(new_location);
  p_entity->GetXAxis()->SetPosition(x_loc);
  
  float y_loc = this->_p_field->GetYFromFieldIndex(new_location);
  p_entity->GetYAxis()->SetPosition(y_loc);
}

}
}
}