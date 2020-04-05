#pragma once
#define DllExport __declspec( dllexport )

#include <memory>
#include "entity/PacManStateType.h"

namespace pacman {
namespace state {

/// <summary>
/// <see cref="IPacManBehaviourState" /> describes the behavioural state of 
/// the player within the pacman game.
/// </summary>
class DllExport IPacManBehaviourState {
public:  
  /// <summary>
  /// Gets the state of this <see cref="IPacManBehaviourState"/>.
  /// </summary>
  /// <returns>
  /// The state of this <see cref="IPacManBehaviourState"/>.
  /// </returns>
  virtual PacManStateType GetState() const = 0;
};

}
}
