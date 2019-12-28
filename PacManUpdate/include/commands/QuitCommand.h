#pragma once
#define DllExport __declspec( dllexport )

// TODO: Fix weird buggy behaviour from this path.
#include "../../PacManControllerAPI/include/IControllerCommand.h"
#include <IGameState.h>


namespace pacman {
namespace update {
namespace commands {
  
/// <summary>
/// The <see cref="QuitCommand" /> sets the <see cref="IGameState" /> to quit.
/// </summary>
/// <seealso cref="controller::ICommand" />
class QuitCommand final : public controller::api::IControllerCommand {
public:  
  /// <summary>
  /// Construct a new <see cref="QuitCommand"/>.
  /// </summary>
  /// <param name="p_game_state">A pointer to the <see cref="IGameState" />.</param>
  explicit QuitCommand(state::IGameState* p_game_state);
  
  void Execute() final;
private:  
  /// <summary>
  /// A pointer to the game state this <see cref="QuitCommand" /> changes.
  /// </summary>
  state::IGameState* p_game_state;
};

DllExport std::unique_ptr<controller::api::IControllerCommand> GetQuitCommand(state::IGameState* p_game_state);

}
}
}
