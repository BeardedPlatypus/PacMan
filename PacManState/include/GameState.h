#pragma once
#define DllExport __declspec( dllexport )


namespace pacman {
namespace state {

/// <summary>
/// GameMode describes the current state of the game.
/// </summary>
enum GameMode
{
	MainMenu,
	PausedGame,
	ActiveGame,
	ClosedGame
};

/// <summary>
/// The GameState describes the overall state of the Game.
/// </summary>
class DllExport GameState {
public:			
	/// <summary>
	/// Construct a new instance of the <see cref="GameState"/> class.
	/// </summary>
	/// <param name="game_mode"> The game mode. </param>
	GameState(GameMode game_mode);


	/// <summary>
	/// Construct a new instance of the <see cref="GameState"/> class.
	/// </summary>
	GameState();
	
	/// <summary>
	/// Get the game mode of this GameState.
	/// </summary>
	/// <returns></returns>
	GameMode getGameMode() const;
	
	/// <summary>
	/// Set the game mode of this GameState.
	/// </summary>
	/// <post-condition>	
	/// (new this)->getGameMode() == game_mode
	/// </post-condition>	
	void setGameMode(GameMode game_mode);

private:	
	/// <summary>
	/// The current state of this GameState state machine.
	/// </summary>
	GameMode mode;
};

}
}