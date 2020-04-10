#pragma once

#include "entity/IEntityManager.h"


namespace pacman {
namespace state {

/// <summary>
/// <see cref="EntityManager"/> provides a concrete implementation of
/// <see cref="IEntityManager"/> and is responsible for describing the
/// state of the different entities within this pacman game.
/// </summary>
/// <seealso cref="IEntityManager" />
class EntityManager final : public IEntityManager {  
public:  
  /// <summary>
  /// Construct a new <see cref="EntityManager"/>.
  /// </summary>
  EntityManager();

  IEntityState<IPacManBehaviourState>* GetPlayerState() const final;
  void SetPlayerState(std::unique_ptr<IEntityState<IPacManBehaviourState>> p_player_state) final;

  IEntityState<IGhostBehaviourState>* GetBlinkyState() const final;
  void SetBlinkyState(std::unique_ptr<IEntityState<IGhostBehaviourState>> p_blinky_state) final;

  IEntityState<IGhostBehaviourState>* GetPinkyState() const final;
  void SetPinkyState(std::unique_ptr<IEntityState<IGhostBehaviourState>> p_pinky_state) final;

  IEntityState<IGhostBehaviourState>* GetInkyState() const final;
  void SetInkyState(std::unique_ptr<IEntityState<IGhostBehaviourState>> p_inky_state) final;

  IEntityState<IGhostBehaviourState>* GetClydeState() const final;
  void SetClydeState(std::unique_ptr<IEntityState<IGhostBehaviourState>> p_clyde_state) final;
private:
  /// <summary>
  /// A <see cref="std::unique_ptr" /> to the <see cref="IEntityState" />
  /// describing the player state of this <see cref="IEntityState"/>
  /// </summary>
  std::unique_ptr<IEntityState<IPacManBehaviourState>> _p_player_state;

  /// <summary>
  /// A <see cref="std::unique_ptr" /> to the <see cref="IEntityState" />
  /// describing the blinky state of this <see cref="IEntityState"/>
  /// </summary>
  std::unique_ptr<IEntityState<IGhostBehaviourState>> _p_blinky_state;

  /// <summary>
  /// A <see cref="std::unique_ptr" /> to the <see cref="IEntityState" />
  /// describing the pinky state of this <see cref="IEntityState"/>
  /// </summary>
  std::unique_ptr<IEntityState<IGhostBehaviourState>> _p_pinky_state;

  /// <summary>
  /// A <see cref="std::unique_ptr" /> to the <see cref="IEntityState" />
  /// describing the inky state of this <see cref="IEntityState"/>
  /// </summary>
  std::unique_ptr<IEntityState<IGhostBehaviourState>> _p_inky_state;

  /// <summary>
  /// A <see cref="std::unique_ptr" /> to the <see cref="IEntityState" />
  /// describing the clyde state of this <see cref="IEntityState"/>
  /// </summary>
  std::unique_ptr<IEntityState<IGhostBehaviourState>> _p_clyde_state;
};

}
}
