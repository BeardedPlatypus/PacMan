#include "pch.h"
#include "objects/behaviours/PortalBehaviour.h"


namespace pacman {
namespace update {
namespace object {

PortalBehaviour::PortalBehaviour(IUpdatablePlayerEntity* p_player_entity,
                                 const std::unordered_map<const state::field::FieldCoordinate, const state::field::FieldCoordinate>& mapping) :
    _p_player_entity(p_player_entity), 
    _portal_mapping(std::unordered_map<const state::field::FieldCoordinate, const state::field::FieldCoordinate>(mapping)) {
}


void PortalBehaviour::Execute(int x, int y) {
  state::field::FieldCoordinate coord = { x = x, y = y };
  if (this->_portal_mapping.find(coord) == this->_portal_mapping.cend()) {
    return;
  }

  this->MovePlayerTo(this->_portal_mapping.at(coord));
}


void PortalBehaviour::MovePlayerTo(const state::field::FieldCoordinate& new_location) {
  this->_p_player_entity->GetXAxis()->SetPosition((float)new_location.x);
  this->_p_player_entity->GetYAxis()->SetPosition((float)new_location.y);
}

}
}
}