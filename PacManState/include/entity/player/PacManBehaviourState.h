#pragma once

#include "entity/player/IPacManBehaviourState.h"

namespace pacman {
namespace state {

/// <summary>
/// <see cref="PacManBehaviourState" /> describes the behavioural state of 
/// the player within the pacman game.
/// </summary>
class PacManBehaviourState final : public IPacManBehaviourState {
public:      
  /// <summary>
  /// Creates a new <see cref="PacManBehaviourState"/>.
  /// </summary>
  /// <param name="initial_state">The initial state.</param>
  explicit PacManBehaviourState(PacManStateType initial_state);

  PacManStateType GetState() const final;
  void SetState(PacManStateType state) final;

private:
  PacManStateType _state_type;
};

}
}
