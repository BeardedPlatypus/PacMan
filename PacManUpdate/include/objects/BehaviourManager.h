#pragma once

#include "field/object/IFieldObjectManager.h"
#include "objects/behaviours/IObjectBehaviour.h"
#include "entity/IUpdatablePlayerEntity.h"

#include <memory>
#include <typeindex>
#include <unordered_map>
#include <vector>


namespace pacman {
namespace update {
namespace object {

class BehaviourManager {
public:
  BehaviourManager();

  void Initialise(const state::field::IField* p_field, 
                  state::field::IFieldObjectManager* p_field_object_manager);

  void ExecuteBehaviourFor(IUpdatablePlayerEntity* p_entity);

private:
  void InitialiseBehaviours();
  void InitialisePortalBehaviour();
  void InitialiseBehaviourMapping();
  void InitialiseDotsBehaviour();

  const state::field::IField* _p_field;
  state::field::IFieldObjectManager* _p_field_object_manager;

  std::unordered_map<std::type_index, std::unique_ptr<IObjectBehaviour>> _object_behaviours = 
    std::unordered_map<std::type_index, std::unique_ptr<IObjectBehaviour>>();

  std::unordered_map<state::field::FieldObjectType,
                     std::vector<IObjectBehaviour*>> _behaviour_mapping =
    std::unordered_map<state::field::FieldObjectType,
                       std::vector<IObjectBehaviour*>>();
};

}
}
}
