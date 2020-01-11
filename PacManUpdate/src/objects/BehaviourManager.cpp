#include "pch.h"
#include "objects/BehaviourManager.h"

#include "objects/behaviours/PortalBehaviour.h"

namespace pacman {
namespace update {
namespace object {

BehaviourManager::BehaviourManager() {}


void BehaviourManager::Initialise(const state::field::IField* p_field,
                                  state::field::IFieldObjectManager* p_field_object_manager) {
  this->_p_field_object_manager = p_field_object_manager;
  this->_p_field = p_field;

  InitialiseBehaviours();
  InitialiseBehaviourMapping();
}


void BehaviourManager::InitialiseBehaviours() {
  InitialisePortalBehaviour();
}


void BehaviourManager::InitialiseBehaviourMapping() {
  std::vector<IObjectBehaviour*> portal_behaviours = {
    this->_object_behaviours.at(std::type_index(typeid(PortalBehaviour))).get() 
  };

  this->_behaviour_mapping[state::field::FieldObjectType::Undefined] = std::vector<IObjectBehaviour*>();
  this->_behaviour_mapping[state::field::FieldObjectType::Portal] = portal_behaviours;
  this->_behaviour_mapping[state::field::FieldObjectType::SmallDot] = std::vector<IObjectBehaviour*>();
  this->_behaviour_mapping[state::field::FieldObjectType::BigDot] = std::vector<IObjectBehaviour*>();
}


void BehaviourManager::InitialisePortalBehaviour() {
  // At the time of writing, we only support two portals, which will portal to each other
  // location. As such we determine the first two FieldObjects of type Portal, and use
  // their locations to set up the portal behaviour. 
  std::vector<state::field::FieldIndex> portals = {};

  for (const state::field::FieldObject& field_object : this->_p_field_object_manager->GetAllFieldObjects()) {
    if (field_object.GetType() == state::field::FieldObjectType::Portal) {
      state::field::FieldIndex index = this->_p_field->GetFieldIndex(field_object.GetX(), 
                                                                     field_object.GetY());

      portals.push_back(index);

      if (portals.size() >= 2) {
        break;
      }
    }
  }

  std::unordered_map<state::field::FieldIndex, state::field::FieldIndex> mapping = {
    { portals[0], portals[1] },
    { portals[1], portals[0] },
  };


  this->_object_behaviours[std::type_index(typeid(PortalBehaviour))] =
    std::make_unique<PortalBehaviour>(this->_p_field, mapping);
}


void BehaviourManager::ExecuteBehaviourFor(IUpdatablePlayerEntity* p_entity) {
  int x = p_entity->GetXAxis()->GetCurrentIndex();
  int y = p_entity->GetYAxis()->GetCurrentIndex();

  state::field::FieldObjectType type = this->_p_field_object_manager->GetObjectType(x, y);

  for (IObjectBehaviour* p_behaviour : this->_behaviour_mapping.at(type)) {
    p_behaviour->Execute(p_entity);
  }
}

}
}
}