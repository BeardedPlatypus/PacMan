#pragma once
#include "entity/ghost/IGhostBehaviourState.h"

namespace pacman {
namespace state {

/// <summary>
/// <see cref="IPacManBehaviourState" /> describes the behavioural state of 
/// the player within the pacman game.
/// </summary>
class GhostBehaviourState final : public IGhostBehaviourState {
public:      
  /// <summary>
  /// Creates a new <see cref="GhostBehaviourState"/>.
  /// </summary>
  /// <param name="initial_state">The initial state.</param>
  explicit GhostBehaviourState(GhostStateType initial_state);

  GhostStateType GetState() const final;
  void SetState(GhostStateType state) final;

private:
  GhostStateType _state_type;
};

}
}
