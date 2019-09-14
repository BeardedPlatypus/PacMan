#pragma once
#define DllExport __declspec( dllexport )

namespace pacman {
namespace state {

/// <summary>
/// GameMode describes the current state of the game.
/// </summary>
enum DllExport GameMode
{
	MainMenu,
	PausedGame,
	ActiveGame,
	ClosedGame
};

}
}
