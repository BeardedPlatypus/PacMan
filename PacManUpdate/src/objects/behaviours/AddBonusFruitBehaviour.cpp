#include "pch.h"
#include "objects/behaviours/AddBonusFruitBehaviour.h"


namespace pacman {
namespace update {
namespace object {


  AddBonusFruitBehaviour::AddBonusFruitBehaviour(const state::level::ILevelManager* p_level_manager,
                                               state::field::IFieldObjectManager* p_field_object_manager,
                                               int x_fruit_pos, int y_fruit_pos) :
    _p_level_manager(p_level_manager),
    _p_field_object_manager(p_field_object_manager),
    _x_fruit_pos(x_fruit_pos), 
    _y_fruit_pos(y_fruit_pos) { }


void AddBonusFruitBehaviour::Execute(IUpdatablePlayerEntity* _) {
  if ((this->_p_level_manager->GetDotsConsumedInCurrentLevel() == 70 ||
       this->_p_level_manager->GetDotsConsumedInCurrentLevel() == 170) &&
       this->_p_field_object_manager->GetObjectType(this->_x_fruit_pos, this->_y_fruit_pos) == state::field::FieldObjectType::Undefined) {
    state::field::FieldObject fruit_object = state::field::FieldObject(this->_x_fruit_pos,
                                                                       this->_y_fruit_pos,
                                                                       state::field::FieldObjectType::BonusFruit);
    this->_p_field_object_manager->AddFieldObject(fruit_object);
  }
}

}
}
}
