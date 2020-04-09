#pragma once
#define DllExport __declspec( dllexport )

#include <memory>

#include "entity/IEntityManager.h"
#include "entity/IEntityState.h"
#include "entity/player/IPacManBehaviourState.h"


namespace  pacman {
namespace state {
  
/// <summary>
/// <see cref="IEntityManager" /> describes the state of the different 
/// <see cref="IEntityState"/> of the entities within this pacman game.
/// </summary>
class DllExport IEntityManager {
public:
  /// <summary>
  /// Construct a new <see cref="IEntityManager"/>
  /// </summary>
  /// <returns>
  /// A <see cref="std::unique_ptr{IEntityManager}"/> containing the newly
  /// created entity manager.
  /// </returns>
  static std::unique_ptr<IEntityManager> Construct();

  /// <summary>
  /// Get a pointer to the state of the player.
  /// </summary>
  /// <returns>A pointer to the state of the player.</returns>
  virtual IEntityState<IPacManBehaviourState>* GetPlayerState() const = 0;
      
  /// <summary>
  /// Set the state of the player to the specified <paramref name="p_player_state" />.
  /// </summary>
  /// <param name="p_player_state">Pointer to the state of the player.</param>
  /// <postcondition>
  /// | (new this)->GetPlayerState() == p_player_state.get();
  /// </postcondition>
  virtual void SetPlayerState(std::unique_ptr<IEntityState<IPacManBehaviourState>> p_player_state) = 0;
};

}
}
