#pragma once
#define DllExport __declspec( dllexport )

#include <ICommand.h>
#include <entity/IEntityState.h>


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
  ChangePlayerDirectionCommand(state::IEntityState* p_player_state,
                               state::Direction direction);

  void Execute() final;

private:  
  /// <summary>
  /// The player's <see cref="state::IEntityState" /> this command changes.
  /// </summary>
  state::IEntityState* p_player_state;
  
  /// <summary>
  /// The direction to which the player's direction will be set.
  /// </summary>
  state::Direction direction;
};

DllExport std::unique_ptr<controller::ICommand> GetChangePlayerDirectionCommand(state::IEntityState* p_player_state,
                                                                                state::Direction direction);

}
}
}

