#pragma once

#include "objects/behaviours/IObjectBehaviour.h"
#include "level/ILevelManager.h"


namespace pacman {
namespace update {
namespace object {

/// <summary>
/// <see cref="IncrementDotsConsumedBehaviour"/> is responsible for incrementing
/// the number of dots consumed when a dot is consumed.
/// </summary>
/// <seealso cref="IObjectBehaviour" />
class IncrementDotsConsumedBehaviour final : public IObjectBehaviour {
public:  
  /// <summary>
  /// Creates a new <see cref="IncrementDotsConsumedBehaviour"/>.
  /// </summary>
  /// <param name="p_level_manager">
  /// A pointer to the <see cref="ILevelManager"/> that should be updated.
  /// </param>
  explicit IncrementDotsConsumedBehaviour(state::level::ILevelManager* p_level_manager);
  
  void Execute(IUpdatablePlayerEntity* p_entity) final;

private:
  state::level::ILevelManager* _p_level_manager;
};

}
}
}
