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


TEST(GameStateTest, SetScoreBoard_ExpectedResults) {
  // Setup
	auto game_state = IGameState::Construct();
	
	std::unique_ptr<score::IScoreBoard> p_score_board =
		score::IScoreBoard::Construct();
	score::IScoreBoard* p_expected_score_board =
		p_score_board.get();

	// Call
	game_state->SetScoreBoard(std::move(p_score_board));

	// Assert
	score::IScoreBoard* retrieved_score_board = game_state->GetScoreBoard();
	EXPECT_EQ(retrieved_score_board, p_expected_score_board);
}


TEST(GameStateTest, SetLevelManager_ExpectedResults) {
  // Setup
	auto game_state = IGameState::Construct();
	
	std::unique_ptr<level::ILevelManager> p_level_manager =
		level::ILevelManager::Construct(30.0);
	level::ILevelManager* p_expected_level_manager =
		p_level_manager.get();

	// Call
	game_state->SetLevelManager(std::move(p_level_manager));

	// Assert
	EXPECT_EQ(game_state->GetLevelManager(), p_expected_level_manager);
}

} // state
} // pacman
