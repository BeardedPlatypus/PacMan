#pragma once
#define DllExport __declspec( dllexport )

#include <SDL.h>
#include <string>
#include <memory>

#include "PlayerState.h"
#include "sdl_util/SDLDestructor.h"

#include "TextureManager.h"
#include "SpriteManager.h"

namespace pacman {
namespace view {

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class DllExport RenderManager {
public:	
	RenderManager();

	/// <summary>
	/// Destruct this <see cref="RenderManager"/>.
	/// </summary>
	~RenderManager();
		
	/// <summary>
	/// Initialize this <see cref="RenderManager"/>.
	/// </summary>
	void init();
	
	/// <summary>
	/// Render the current frame.
	/// </summary>
	/// <param name="entity">The entity.</param>
	void render(float dtime) const;

private:
	/// <summary>
	/// Initialise SDL features.
	/// </summary>
	void initialiseSDL();
	
	/// <summary>
	/// Initialise the SDL_image features.
	/// </summary>
	void initialiseSDLImage();
	
	/// <summary>
	/// Initialise the SDL window.
	/// </summary>
	void initialiseWindow();

	/// <summary> A pointer to the window. </summary>
	std::unique_ptr<SDL_Window, SDL_Destructor<SDL_Window>> p_window;
	
	/// <summary>
	/// Initialise the SDL renderer.
	/// </summary>
	void initialiseRenderer();

	/// <summary> A pointer to the renderer. </summary>
	std::unique_ptr<SDL_Renderer, SDL_Destructor<SDL_Renderer>> p_renderer;


	std::unique_ptr<TextureManager> p_texture_manager;
	std::unique_ptr<SpriteManager> p_sprite_manager;

	SpriteAnimation* p_anim1;
	SpriteAnimation* p_anim2;
	SpriteAnimation* p_anim3;
	SpriteAnimation* p_anim4;
	SpriteAnimation* p_anim5;
};

} // view
} // pacman
