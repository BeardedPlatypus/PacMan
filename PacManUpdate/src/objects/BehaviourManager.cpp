#include "pch.h"
#include "objects/BehaviourManager.h"

#include "objects/behaviours/PortalBehaviour.h"
#include "objects/behaviours/RemoveObjectBehaviour.h"
#include "objects/behaviours/BigDotScoreBehaviour.h"
#include "objects/behaviours/SmallDotScoreBehaviour.h"
#include "objects/behaviours/IncrementDotsConsumedBehaviour.h"
#include "objects/behaviours/AddBonusFruitBehaviour.h"
#include "objects/behaviours/BonusFruitScoreBehaviour.h"
#include "objects/behaviours/WinRoundBehaviour.h"


namespace pacman {
namespace update {
namespace object {

BehaviourManager::BehaviourManager() {}



void BehaviourManager::Initialise(const state::field::IField* p_field,
                                  state::field::IFieldObjectManager* p_field_object_manager,
                                  state::score::IScoreBoard* p_score_board, 
                                  state::level::ILevelManager* p_level_manager) {
  this->_p_field_object_manager = p_field_object_manager;
  this->_p_field = p_field;
  this->_p_score_board = p_score_board;
  this->_p_level_manager = p_level_manager;

  this->InitialiseBehaviours();
  this->InitialiseBehaviourMapping();
}


void BehaviourManager::InitialiseBehaviours() {
  this->InitialisePortalBehaviour();
  this->InitialiseObjectBehaviour();
}


void BehaviourManager::InitialiseBehaviourMapping() {

  std::vector<IObjectBehaviour*> portal_behaviours = {
    this->_object_behaviours.at(std::type_index(typeid(PortalBehaviour))).get() 
  };

  std::vector<IObjectBehaviour*> small_dots_behaviours = {
    this->_object_behaviours.at(std::type_index(typeid(RemoveObjectBehaviour))).get(),
    this->_object_behaviours.at(std::type_index(typeid(IncrementDotsConsumedBehaviour))).get(),
    this->_object_behaviours.at(std::type_index(typeid(AddBonusFruitBehaviour))).get(),
    this->_object_behaviours.at(std::type_index(typeid(SmallDotScoreBehaviour))).get(),
    this->_object_behaviours.at(std::type_index(typeid(WinRoundBehaviour))).get(),
  };

  std::vector<IObjectBehaviour*> big_dots_behaviours = {
    this->_object_behaviours.at(std::type_index(typeid(RemoveObjectBehaviour))).get(),
    this->_object_behaviours.at(std::type_index(typeid(IncrementDotsConsumedBehaviour))).get(),
    this->_object_behaviours.at(std::type_index(typeid(AddBonusFruitBehaviour))).get(),
    this->_object_behaviours.at(std::type_index(typeid(BigDotScoreBehaviour))).get(),
    this->_object_behaviours.at(std::type_index(typeid(WinRoundBehaviour))).get(),
  };

  std::vector<IObjectBehaviour*> bonus_fruit_behaviours = {
    this->_object_behaviours.at(std::type_index(typeid(RemoveObjectBehaviour))).get(),
    this->_object_behaviours.at(std::type_index(typeid(BonusFruitScoreBehaviour))).get(),
  };

  this->_behaviour_mapping[state::field::FieldObjectType::Undefined] = std::vector<IObjectBehaviour*>();
  this->_behaviour_mapping[state::field::FieldObjectType::Portal] = portal_behaviours;
  this->_behaviour_mapping[state::field::FieldObjectType::SmallDot] = small_dots_behaviours;
  this->_behaviour_mapping[state::field::FieldObjectType::BigDot] = big_dots_behaviours;
  this->_behaviour_mapping[state::field::FieldObjectType::BonusFruit] = bonus_fruit_behaviours;
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


void BehaviourManager::InitialiseObjectBehaviour() {
  this->_object_behaviours[std::type_index(typeid(RemoveObjectBehaviour))] =
    std::make_unique<RemoveObjectBehaviour>(this->_p_field_object_manager);
  this->_object_behaviours[std::type_index(typeid(IncrementDotsConsumedBehaviour))] =
    std::make_unique<IncrementDotsConsumedBehaviour>(this->_p_level_manager);
  this->_object_behaviours[std::type_index(typeid(AddBonusFruitBehaviour))] =
    std::make_unique<AddBonusFruitBehaviour>(this->_p_level_manager, 
                                             this->_p_field_object_manager, 
                                             11, 15);
  this->_object_behaviours[std::type_index(typeid(BigDotScoreBehaviour))] =
    std::make_unique<BigDotScoreBehaviour>(this->_p_score_board);
  this->_object_behaviours[std::type_index(typeid(SmallDotScoreBehaviour))] =
    std::make_unique<SmallDotScoreBehaviour>(this->_p_score_board);
  this->_object_behaviours[std::type_index(typeid(BonusFruitScoreBehaviour))] =
    std::make_unique<BonusFruitScoreBehaviour>(this->_p_score_board,
                                               this->_p_level_manager);
  this->_object_behaviours[std::type_index(typeid(WinRoundBehaviour))] =
    std::make_unique<WinRoundBehaviour>(this->_p_level_manager,
                                        this->_p_field_object_manager);
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
