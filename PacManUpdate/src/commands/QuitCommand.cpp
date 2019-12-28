#include "pch.h"
#include "commands/QuitCommand.h"


namespace pacman {
namespace update {
namespace commands {

QuitCommand::QuitCommand(state::IGameState* p_game_state) : p_game_state(p_game_state) { }


void QuitCommand::Execute() {
  this->p_game_state->SetGameMode(state::GameMode::ClosedGame);
}


std::unique_ptr<controller::api::IControllerCommand> GetQuitCommand(state::IGameState* p_game_state) {
  return std::make_unique<QuitCommand>(p_game_state);
}

}
}
}