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
  /// Constructs the specified initial state.
  /// </summary>
  /// <param name="initial_state">The initial state.</param>
  /// <returns>
  /// A new <see cref="std::unique_ptr{IPacManBehaviourState}"/> with the given
  /// initial state.
  /// </returns>
  static std::unique_ptr<IPacManBehaviourState> Construct(PacManStateType initial_state);

  /// <summary>
  /// Gets the state of this <see cref="IPacManBehaviourState"/>.
  /// </summary>
  /// <returns>
  /// The state of this <see cref="IPacManBehaviourState"/>.
  /// </returns>
  virtual PacManStateType GetState() const = 0;
  
  /// <summary>
  /// Sets the state of this <see cref="IPacManBehaviourState" />.
  /// </summary>
  /// <param name="state">The new state.</param>
  virtual void SetState(PacManStateType state) = 0;
};

}
}
