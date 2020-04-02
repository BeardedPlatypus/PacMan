#pragma once

#include "GameMode.h"
#include "IGameState.h"
#include "entity/ISpatialState.h"

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

  ISpatialState* GetPlayerState() const final;
  void SetPlayerState(std::unique_ptr<ISpatialState> p_new_player_state) final;

  void ConstructNewFieldObjects(const std::vector<std::vector<field::FieldObjectType>>& field_objects) final;

  field::IFieldObjectManager* GetFieldObjectManager() const final;

  score::IScoreBoard* GetScoreBoard() const final;
  void SetScoreBoard(std::unique_ptr<score::IScoreBoard> p_score_board) final;

  level::ILevelManager* GetLevelManager() const final;
  void SetLevelManager(std::unique_ptr<level::ILevelManager> p_level_manager) final;
private:	
	/// <summary>
	/// The current state of this GameState state machine.
	/// </summary>
	GameMode _mode = GameMode::MainMenu;
  
  /// <summary>
  /// A <see cref="std::unique_ptr" /> to the <see cref="field::IField" />
  /// of this <see cref="GameState" />.
  /// </summary>
  std::unique_ptr<field::IField> _p_field;
  
  /// <summary>
  /// A <see cref="std::unique_ptr" /> to the player's
  /// <see cref="ISpatialState" />.
  /// </summary>
  std::unique_ptr<ISpatialState> _p_player_state;
  
  /// <summary>
  /// A <see cref="std::unique_ptr" /> to the <see cref="field::IFieldObjectManager" />.
  /// </summary>
  std::unique_ptr<field::IFieldObjectManager> _p_field_object_manager;
  
  /// <summary>
  /// A <see cref="std::unique_ptr" /> to the <see cref="score::IScoreBoard"/>.
  /// </summary>
  std::unique_ptr<score::IScoreBoard> _p_score_board;
  
  /// <summary>
  /// A <see cref="std::unique_ptr" /> to the <see cref="level::ILevelManager"/>.
  /// </summary>
  std::unique_ptr<level::ILevelManager> _p_level_manager;
};

}
}