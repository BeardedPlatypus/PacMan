#pragma once

#include "objects/behaviours/IObjectBehaviour.h"
#include "level/ILevelManager.h"
#include "field/object/IFieldObjectManager.h"


namespace pacman {
namespace update {
namespace object {

class AddBonusFruitBehaviour final : public IObjectBehaviour {
public:  
  /// <summary>
  /// Creates a new <see cref="AddBonusFruitBehaviour" />.
  /// </summary>
  /// <param name="p_level_manager">A pointer to the <see cref="state::level::ILevelManager" />.</param>
  /// <param name="p_field_object_manager">The p field object manager.</param>
  /// <param name="x">The x-location to place the fruit at.</param>
  /// <param name="y">The y-location to place the fruit at.</param>
  AddBonusFruitBehaviour(const state::level::ILevelManager* p_level_manager,
                         state::field::IFieldObjectManager* p_field_object_manager,
                         int x_fruit_pos, int y_fruit_pos);
  
  void Execute(IUpdatablePlayerEntity* p_entity) final;

private:
  const state::level::ILevelManager* _p_level_manager;
  state::field::IFieldObjectManager* _p_field_object_manager;
  int _x_fruit_pos;
  int _y_fruit_pos;
};

}
}
}
