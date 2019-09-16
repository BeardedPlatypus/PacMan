#include "EntityStateMock.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "GameState.h"


namespace pacman {
namespace state {

TEST(GameStateTest, GivenAGameMode_WhenAGameStateIsConstructedWithThisMode_ThenThisGameStateHasThisMode) {
	// Given 
	auto expected_mode = GameMode::MainMenu;

	// When
	auto game_state = IGameState::Construct();

	// Then
	GameMode retrieved_mode = game_state->GetGameMode();
	EXPECT_EQ(retrieved_mode, expected_mode);
}


TEST(GameStateTest, GivenAGameStateAndAGameMode_WhenThisModeIsSetOnThisState_ThenThisStateHasThisMode) {
	// Given 
	auto game_state = IGameState::Construct();
	auto expected_mode = GameMode::PausedGame;

	// When
	game_state->SetGameMode(expected_mode);

	// Then
	GameMode retrieved_mode = game_state->GetGameMode();
	EXPECT_EQ(retrieved_mode, expected_mode);
}


} // state
} // pacman