#pragma once
#define DllExport __declspec( dllexport )

#include <memory>

#include "entity/IEntityManager.h"
#include "entity/ISpatialState.h"


namespace  pacman {
namespace state {
  
/// <summary>
/// <see cref="IEntityManager" /> describes the state of the different 
/// <see cref="ISpatialState"/> of the entities within this pacman game.
/// </summary>
class DllExport IEntityManager {
public:
  /// <summary>
  /// Construct a new <see cref="ISpatialState" /> with the given parameters.
  /// </summary>
  /// <returns></returns>
  static std::unique_ptr<IEntityManager> Construct();

  /// <summary>
  /// Get a pointer to the state of the player.
  /// </summary>
  /// <returns>A pointer to the state of the player.</returns>
  virtual ISpatialState* GetPlayerState() const = 0;
      
  /// <summary>
  /// Set the state of the player to the specified <paramref name="p_player_state" />.
  /// </summary>
  /// <param name="p_player_state">Pointer to the state of the player.</param>
  /// <postcondition>
  /// | (new this)->GetPlayerState() == p_player_state.get();
  /// </postcondition>
  virtual void SetPlayerState(std::unique_ptr<ISpatialState> p_player_state) = 0;
};

}
}
