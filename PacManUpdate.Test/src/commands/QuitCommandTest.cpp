#include <gtest/gtest.h>

#include <commands/QuitCommand.h>


namespace pacman {
namespace update {
namespace commands {

TEST(QuitCommandTest, Execute_SetsGameStateToQuit) {
  // Setup
  auto gameState = state::IGameState::Construct();
  auto quitCommand = GetQuitCommand(gameState.get());

  // Precondition
  ASSERT_NE(gameState->GetGameMode(), state::GameMode::ClosedGame);

  // Call
  quitCommand->Execute();

  // Assert
  ASSERT_EQ(gameState->GetGameMode(), state::GameMode::ClosedGame);
}

}
}
}