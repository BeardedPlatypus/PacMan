#pragma once
#include "entity/IUpdatablePlayerEntity.h"


namespace pacman {
namespace update {
namespace object {

/// <summary>
/// <see cref="IObjectBehaviour"/> defines the interface for object
/// behaviours which can be executed by the <see cref="BehaviourManager"/>.
/// </summary>
class IObjectBehaviour {
public:  
  /// <summary>
  /// Finalizes this <see cref="IObjectBehaviour"/>.
  /// </summary>
  virtual ~IObjectBehaviour() = default;
  
  /// <summary>
  /// Executes this <see cref="IObjectBehaviour"/>.
  /// </summary>
  /// <param name="p_entity">
  /// The <see cref="IUpdatablePlayerEntity"/> on which this behaviour should act.
  /// </param>
  /// <param name="x"> The x location at which this behaviour is executed. </param>
  /// <param name="y"> The y location at which this behaviour is executed. </param>
  virtual void Execute(IUpdatablePlayerEntity* p_entity) = 0;
};

}
}
}
