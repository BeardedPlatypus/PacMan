#pragma once

#include "manager/IUpdateManager.h"
#include "entity/IUpdatablePlayerEntity.h"


namespace pacman {
namespace update {

class UpdateManager final : public IUpdateManager {
public:
  UpdateManager(state::IGameState* p_game_state,
                controller::IControllerManager* p_controller_manager);

  void Initialise() final;
  void Update(float dl) final;

private:  
  /// <summary>
  /// Initialise the commands within the <see cref="controller::IControllerManager" />.
  /// </summary>
  void InitialiseCommands();
  
  /// <summary>
  /// A pointer to the <see cref="IGameState" />
  /// </summary>
  state::IGameState* p_game_state;
  
  /// <summary>
  /// A pointer to the <see cref="controller::IControllerManager" />.
  /// </summary>
  controller::IControllerManager* p_controller_manager;

  std::unique_ptr<IUpdatablePlayerEntity> p_player_entity;

};


}
}
