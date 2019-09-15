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


TEST(GameStateTest, GivenAGameStateAndAEntityState_WhenSetPlayerStateIsSet_ThenGetPlayerStateReturnsTheCorrectPointer) {
  // Given
  std::unique_ptr<IEntityState> p_entity_state_mock = 
    std::make_unique<EntityStateMock>();
  auto game_state = IGameState::Construct();

  IEntityState* expected_pointer = p_entity_state_mock.get();

  // When
  game_state->SetPlayerState(std::move(p_entity_state_mock));

  // Then
  EXPECT_EQ(game_state->GetPlayerState(), expected_pointer);
}

} // state
} // pacman