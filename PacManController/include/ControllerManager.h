#pragma once
#define DllExport __declspec( dllexport )

#include <SDL2/SDL.h>
#include <GameState.h>
#include <memory>

namespace pacman {
namespace controller {

class DllExport ControllerManager {
public:
	ControllerManager();
	
 	/// <summary>
	/// Update this ControllerManager.
	/// </summary>
	void update(state::GameState& state) const;

private:
	std::unique_ptr<SDL_Event> p_event;
};


} // controller
} // pacman
