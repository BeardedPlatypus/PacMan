#include "pch.h"

#include "gtest/gtest.h"
#include "GameState.h"

namespace pacman {
namespace state {

TEST(GameStateTest, GivenAGameMode_WhenAGameStateIsConstructedWithThisMode_ThenThisGameStateHasThisMode) {
	// Given 
	auto expected_mode = GameMode::PausedGame;

	// When
	auto game_state = GameState(expected_mode);

	// Then
	GameMode retrieved_mode = game_state.getGameMode();
	EXPECT_EQ(retrieved_mode, 
			  expected_mode);
}


TEST(GameStateTest, GivenAGameStateAndAGameMode_WhenThisModeIsSetOnThisState_ThenThisStateHasThisMode) {
	// Given 
	auto game_state = GameState(GameMode::ClosedGame);
	auto expected_mode = GameMode::PausedGame;

	// When
	game_state.setGameMode(expected_mode);

	// Then
	GameMode retrieved_mode = game_state.getGameMode();
	EXPECT_EQ(retrieved_mode, 
			  expected_mode);
}

} // state
} // pacman