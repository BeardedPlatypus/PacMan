#pragma once

#include <memory>
#include <SDL2/SDL.h>

#include "renderer/IViewCore.h"
#include "renderer/Renderer.h"
#include "renderer/IRendererFactory.h"

#include "sdl_util/SDLDestructor.h"
#include "sdl_util/IDispatcher.h"

namespace pacman {
namespace view {

/// <summary>
/// <see cref="ViewCore"/> implements <see cref="IViewCore"/>. 
/// It provides a thin wrapper around the SDL initialisation functionality.
/// </summary>
/// <seealso cref="IViewCore"/>
class ViewCore final : public IViewCore {
public:	
 	/// <summary>
	/// Construct a new <see cref="ViewCore"/>.
	/// </summary>
	/// <param name="p_sdl_dispatcher"> The SDL dispatcher. </param>
	ViewCore(std::unique_ptr<sdl::IDispatcher> p_sdl_dispatcher,
		       const IRendererFactory& renderer_factory);
	
	/// <summary>
	/// Finalizes this <see cref="ViewCore"/>.
	/// </summary>
	~ViewCore() override;
	
	/// <summary> 
	/// Initialise this <see cref="IViewCore"/>.
	/// </summary>
	/// <param name="screen_width"> Width of the screen. </param>
	/// <param name="screen_height"> Height of the screen. </param>
  /// <exception cref="ViewException"> 
	/// <paramref name="screen_width"/> <= 0 || <paramref name="screen_height"/> <= 0.
	/// </exception>
	void Initialise(int screen_width, int screen_height) final;
	
	/// <summary>
	/// Get the <see cref="IRenderer"/> of this <see cref="IViewCore"/>.
	/// </summary>
	/// <returns>
	/// The <see cref="IRenderer"/> of this <see cref="IViewCore"/>.
	/// </returns>
	inline IRenderer& GetRenderer() const { return *this->_p_renderer; }
	
private:	
	/// <summary>
	/// Initialise SDL features.
	/// </summary>
	void InitialiseSDL();
	
	/// <summary>
	/// Initialise the SDL_image features.
	/// </summary>
	void InitialiseSDLImage();
	
	/// <summary>
	/// Initialise the SDL window.
	/// </summary>
	/// <param name="screenWidth"> Width of the screen. </param>
	/// <param name="screenHeight"> Height of the screen. </param>
	void InitialiseWindow(int screenWidth, int screenHeight);

	/// <summary> 
	/// A pointer to the <see cref="Renderer" /> of this <see cref="ViewCore" />. 
	/// </summary>
	std::unique_ptr<IRenderer> _p_renderer;

	/// <summary> 
	/// The pointer to the <see cref="SDL_window" /> of this <see cref="ViewManager" />.
	/// </summary>
	std::unique_ptr<SDL_Window, SDL_Destructor<SDL_Window>> _p_window;
	
	/// <summary> 
	/// Whether SDL has been initialised. 
	/// </summary>
	bool _sdl_initialised;

	/// <summary> 
	/// Whether SDL_image has been initialised. 
	/// </summary>
	bool _sdl_image_initialised;
	
	/// <summary>
	/// The pointer to the <see cref="sdl::IDispatcher"/> of this <see cref="ViewCore"/>.
	/// </summary>
	std::unique_ptr<sdl::IDispatcher> _p_sdl_dispatcher;
};

}
}
