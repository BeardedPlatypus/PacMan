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
  void SetPlayerState(std::unique_ptr<IEntityState<IPacManBehaviourState>> p_new_player_state) final;
private:
  /// <summary>
  /// A <see cref="std::unique_ptr" /> to the <see cref="IEntityState" />
  /// describing the player state of this <see cref="IEntityState"/>
  /// </summary>
  std::unique_ptr<IEntityState<IPacManBehaviourState>> p_player_state;
};

}
}
