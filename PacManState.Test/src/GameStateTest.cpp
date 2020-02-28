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


TEST(GameStateTest, SetPlayerState_ExpectedResults) {
	// Setup
	auto game_state = IGameState::Construct();

	std::unique_ptr<EntityStateMock> p_entity_state = std::make_unique<EntityStateMock>();
	EntityStateMock* p_expected_state = p_entity_state.get();

	// Call
	game_state->SetPlayerState(std::move(p_entity_state));

	// Assert
	IEntityState* retrieved_state = game_state->GetPlayerState();
	EXPECT_EQ(retrieved_state, p_expected_state);
}

} // state
} // pacman
