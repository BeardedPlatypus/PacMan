#pragma once
#define DllExport __declspec( dllexport )

#include <memory>

#include "entity/IEntityManager.h"
#include "entity/IEntityState.h"
#include "entity/player/IPacManBehaviourState.h"
#include "entity/ghost/GhostBehaviourState.h"


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
  /// Gets a pointer to the state of the player.
  /// </summary>
  /// <returns>
  /// A pointer to the state of the player.
  /// </returns>
  virtual IEntityState<IPacManBehaviourState>* GetPlayerState() const = 0;
      
  /// <summary>
  /// Sets the state of the player to the specified <paramref name="p_player_state" />.
  /// </summary>
  /// <param name="p_player_state">Pointer to the state of the player.</param>
  /// <postcondition>
  /// | (new this)->GetPlayerState() == p_player_state.get();
  /// </postcondition>
  virtual void SetPlayerState(std::unique_ptr<IEntityState<IPacManBehaviourState>> p_player_state) = 0;
  
  /// <summary>
  /// Gets a pointer to the state of Blinky.
  /// </summary>
  /// <returns>
  /// A pointer to the state of Blinky.
  /// </returns>
  virtual IEntityState<IGhostBehaviourState>* GetBlinkyState() const = 0;

  /// <summary>
  /// Sets the state of Blinky to the specified <paramref name="p_blinky_state" />.
  /// </summary>
  /// <param name="p_blinky_state">Pointer to the state of Blinky.</param>
  /// <postcondition>
  /// | (new this)->GetBlinkyState() == p_blinky_state.get();
  /// </postcondition>
  virtual void SetBlinkyState(std::unique_ptr<IEntityState<IGhostBehaviourState>> p_blinky_state) = 0;

  /// <summary>
  /// Gets a pointer to the state of Pinky.
  /// </summary>
  /// <returns>
  /// A pointer to the state of Pinky.
  /// </returns>
  virtual IEntityState<IGhostBehaviourState>* GetPinkyState() const = 0;

  /// <summary>
  /// Sets the state of Pinky to the specified <paramref name="p_pinky_state" />.
  /// </summary>
  /// <param name="p_pinky_state">Pointer to the state of Pinky.</param>
  /// <postcondition>
  /// | (new this)->GetPinkyState() == p_pinky_state.get();
  /// </postcondition>
  virtual void SetPinkyState(std::unique_ptr<IEntityState<IGhostBehaviourState>> p_pinky_state) = 0;
  
  /// <summary>
  /// Gets a pointer to the state of Inky.
  /// </summary>
  /// <returns>
  /// A pointer to the state of Inky.
  /// </returns>
  virtual IEntityState<IGhostBehaviourState>* GetInkyState() const = 0;

  /// <summary>
  /// Sets the state of Inky to the specified <paramref name="p_inky_state" />.
  /// </summary>
  /// <param name="p_inky_state">Pointer to the state of Inky.</param>
  /// <postcondition>
  /// | (new this)->GetInkyState() == p_inky_state.get();
  /// </postcondition>
  virtual void SetInkyState(std::unique_ptr<IEntityState<IGhostBehaviourState>> p_inky_state) = 0;

  /// <summary>
  /// Gets a pointer to the state of Clyde.
  /// </summary>
  /// <returns>
  /// A pointer to the state of Clyde.
  /// </returns>
  virtual IEntityState<IGhostBehaviourState>* GetClydeState() const = 0;

  /// <summary>
  /// Sets the state of Clyde to the specified <paramref name="p_clyde_state" />.
  /// </summary>
  /// <param name="p_clyde_state">Pointer to the state of Clyde.</param>
  /// <postcondition>
  /// | (new this)->GetClydeState() == p_clyde_state.get();
  /// </postcondition>
  virtual void SetClydeState(std::unique_ptr<IEntityState<IGhostBehaviourState>> p_clyde_state) = 0;
};

}
}
