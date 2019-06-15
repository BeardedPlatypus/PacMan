#pragma once
#define DllExport __declspec( dllexport )

#include <SDL2\SDL.h>
#include <string>
#include <memory>

#include "PlayerState.h"
#include "sdl_util/SDLDestructor.h"
#include "renderer/Renderer.h"

#include "texture/ITextureManager.h"
#include "sprite/SpriteManager.h"

namespace pacman {
namespace view {

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


/// <summary>
/// The <see cref="RenderManager"> provides an interface to the PacManView 
/// module. It provides the methods to initialise, register, and render a set
/// of sprites.
/// </summary>
class DllExport RenderManager {
public:				
	/// <summary>
	/// Construct a new <see cref="RenderManager"/>.
	/// </summary>
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
	/// Renders the specified given the specified time passed.
	/// </summary>
	/// <param name="dtime"> The change in time. </param>
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
	
	/// <summary> A pointer to the renderer. </summary>
	std::unique_ptr<Renderer> p_renderer;


	std::unique_ptr<ITextureManager> p_texture_manager;
	std::unique_ptr<SpriteManager> p_sprite_manager;

	SpriteAnimation* p_anim1;
	SpriteAnimation* p_anim2;
	SpriteAnimation* p_anim3;
	SpriteAnimation* p_anim4;
	SpriteAnimation* p_anim5;
};

} // view
} // pacman
