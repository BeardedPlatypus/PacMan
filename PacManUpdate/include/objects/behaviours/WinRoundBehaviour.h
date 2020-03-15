#pragma once

#include "objects/behaviours/IObjectBehaviour.h"
#include "level/ILevelManager.h"
#include "field/object/IFieldObjectManager.h"


namespace pacman {
namespace update {
namespace object {

class WinRoundBehaviour final : public IObjectBehaviour {
public:  
  /// <summary>
  /// Creates a new <see cref="WinRoundBehaviour" />.
  /// </summary>
  /// <param name="p_level_manager">A pointer to the <see cref="state::level::ILevelManager" />.</param>
  /// <param name="p_field_object_manager">The p field object manager.</param>
  WinRoundBehaviour(state::level::ILevelManager* p_level_manager,
                    state::field::IFieldObjectManager* p_field_object_manager);
  
  void Execute(IUpdatablePlayerEntity* p_entity) final;

private:
  state::level::ILevelManager* _p_level_manager;
  state::field::IFieldObjectManager* _p_field_object_manager;
};

}
}
}
