#pragma once
#define DllExport __declspec( dllexport )

#include <ICommand.h>
#include <entity/IEntityState.h>

#include "entity/IUpdatablePlayerEntity.h"

namespace pacman {
namespace update {
namespace commands {
  
/// <summary>
/// The <see cref="ChangePlayerDirectionCommand" /> sets the <see cref="state::Direction" /> of the
/// player's <see cref="IEntityState" />.
/// </summary>
/// <seealso cref="controller::ICommand" />
class ChangePlayerDirectionCommand final : public controller::ICommand {
public:  
  /// <summary>
  /// Construct a new <see cref="ChangePlayerDirectionCommand"/>.
  /// </summary>
  /// <param name="p_player_state">Pointer to the player's <see cref="state::IEntityState" />.</param>
  ChangePlayerDirectionCommand(IUpdatablePlayerEntity* p_player_state,
                               std::optional<state::Direction> direction);

  void Execute() final;

private:  
  /// <summary>
  /// The player's <see cref="state::IEntityState" /> this command changes.
  /// </summary>
  IUpdatablePlayerEntity* p_player_state;
  
  /// <summary>
  /// The direction to which the player's direction will be set.
  /// </summary>
  std::optional<state::Direction> direction;
};


/// <summary>
/// Get a new command which changes the direction of the provided 
/// <paramref cref="p_player_state"/> to the provided 
/// <paramref cref="direction"/> when executed.
/// </summary>
/// <param name="p_player_state"/>A pointer to the player state to be updated.</param>
/// <param name="direction"/>The direction to which the player state is changed.</param>
/// <returns>
/// An <see cref="controller::ICommand"/> which changes the direction 
/// of the provided player state.
/// </returns>
DllExport std::unique_ptr<controller::ICommand> GetChangePlayerDirectionCommand(IUpdatablePlayerEntity* p_player_state,
                                                                                std::optional<state::Direction> direction);

}
}
}

