#pragma once

#include <memory>
#include <SDL2/SDL.h>

#include "renderer/IViewCore.h"
#include "renderer/Renderer.h"
#include "sdl_util/SDLDestructor.h"


namespace pacman {
namespace view {

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

/// <summary>
/// <see cref="ViewCore" /> implements <see cref="IViewCore" />. 
/// It provides a thin wrapper around the SDL initialisation functionality.
/// </summary>
/// <seealso cref="IViewCore" />
class ViewCore final : public IViewCore {
public:	
	/// <summary>
	/// Construct a new <see cref="ViewCore"/>.
	/// </summary>
	ViewCore();
	
	/// <summary>
	/// Finalize this <see cref="ViewCore"/>.
	/// </summary>
	~ViewCore();
	
	/// <summary> 
	/// Initialise this <see cref="IViewCore" />.
	/// </summary>
	void initialise() final;
	
	/// <summary>
	/// Get the <see cref="IRenderer" /> of this <see cref="IViewCore" />.
	/// </summary>
	/// <returns>
	/// The <see cref="IRenderer" /> of this <see cref="IViewCore" />.
	/// </returns>
	inline IRenderer& getRenderer() const { return *this->p_renderer; }
	
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

	/// <summary> 
	/// A pointer to the <see cref="Renderer" /> of this <see cref="ViewCore" />. 
	/// </summary>
	std::unique_ptr<Renderer> p_renderer;

	/// <summary> 
	/// The pointer to the <see cref="SDL_window" /> of this <see cref="ViewManager" />.
	/// </summary>
	std::unique_ptr<SDL_Window, SDL_Destructor<SDL_Window>> p_window;
	
	/// <summary> 
	/// Whether SDL has been initialised. 
	/// </summary>
	bool sdl_initialised;

	/// <summary> 
	/// Whether SDL_image has been initialised. 
	/// </summary>
	bool sdl_image_initialised;
};

}
}
