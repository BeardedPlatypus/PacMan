#pragma once
#define DllExport __declspec( dllexport )

#include <memory>
#include "entity/ghost/GhostStateType.h"

namespace pacman {
namespace state {

/// <summary>
/// <see cref="IGhostBehaviourState" /> describes the behavioural state of 
/// a ghost within the pacman game.
/// </summary>
class DllExport IGhostBehaviourState {
public:    
  /// <summary>
  /// Constructs a new <see cref="IGhostBehaviourState"/> with the given
  /// <paramref cref="initial_state"/>.
  /// </summary>
  /// <param name="initial_state">The initial state.</param>
  /// <returns>
  /// A new <see cref="std::unique_ptr{IGhostBehaviourState}"/> with the given
  /// initial state.
  /// </returns>
  static std::unique_ptr<IGhostBehaviourState> Construct(GhostStateType initial_state);

  /// <summary>
  /// Gets the state of this <see cref="IGhostBehaviourState"/>.
  /// </summary>
  /// <returns>
  /// The state of this <see cref="IGhostBehaviourState"/>.
  /// </returns>
  virtual GhostStateType GetState() const = 0;
  
  /// <summary>
  /// Sets the state of this <see cref="IGhostBehaviourState" />.
  /// </summary>
  /// <param name="state">The new state.</param>
  virtual void SetState(GhostStateType state) = 0;
};

}
}
