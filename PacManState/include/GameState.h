#pragma once

#include "GameMode.h"
#include "IGameState.h"
#include "entity/IEntityState.h"

namespace pacman {
namespace state {

/// <summary>
/// The GameState describes the overall state of the Game.
/// </summary>
class GameState final : public IGameState {
public:			
	/// <summary>
	/// Construct a new instance of the <see cref="GameState"/> class.
	/// </summary>
	GameState();

	GameMode GetGameMode() const final;
	void SetGameMode(GameMode game_mode) final;

  field::IField* GetField() const final;
  void ConstructNewField(const std::vector<std::vector<field::TileType>>& tiles);

  IEntityState* GetPlayerState() const final;
  void SetPlayerState(std::unique_ptr<IEntityState> p_player_state) final;

private:	
	/// <summary>
	/// The current state of this GameState state machine.
	/// </summary>
	GameMode mode;
  
  /// <summary>
  /// A <see cref="std::unique_ptr" /> to the <see cref="field::IField" />
  /// of this <see cref="GameState" />.
  /// </summary>
  std::unique_ptr<field::IField> p_field;
  
  /// <summary>
  /// A <see cref="std::unique_ptr" /> to the player's
  /// <see cref="IEntityState" />.
  /// </summary>
  std::unique_ptr<IEntityState> p_player_state;
};

}
}