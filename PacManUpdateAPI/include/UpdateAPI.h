#pragma once
#include "IUpdateAPI.h"

#include "entity/IUpdatablePlayerEntity.h"
#include "objects/BehaviourManager.h"

namespace pacman {
namespace update {

class UpdateAPI final : public IUpdateAPI {
public:
  UpdateAPI(state::IGameState* p_game_state,
            controller::api::IControllerAPI* p_controller_manager);

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
  controller::api::IControllerAPI* p_controller_manager;

  std::unique_ptr<IUpdatablePlayerEntity> p_player_entity;

  std::unique_ptr<object::BehaviourManager> p_behaviour_manager =
    std::make_unique<object::BehaviourManager>();
};

}
}
