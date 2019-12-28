#pragma once

#include "IRenderer.h"
#include <memory>

#include "sdl_util/SDLDestructor.h"


namespace pacman {
namespace view {

/// <summary>
/// Thin wrapper around the SDL_Renderer object.
/// </summary>
/// <seealso cref="IRenderer"/>
class Renderer final : public IRenderer {
public:	
	/// <summary>
	/// Create a new <see cref="Renderer"/>.
	/// </summary>
	Renderer();
	
	/// <summary>
	/// Finalize this instance of the <see cref="Renderer"/> class.
	/// </summary>
	~Renderer() final;
	
	/// <summary>
	/// Initialize this <see cref="Renderer"/> with the specified window pointer.
	/// </summary>
	/// <param name="p_window"> The pointer to the window. </param>
	void Init(SDL_Window* p_window);

  void RenderCopy(SDL_Texture* p_texture,
	                const SDL_Rect* p_texture_clip,
                  const SDL_Rect* p_destination,
                  float angle, 
                  bool flip_horizontally,
                  bool flip_vertically) final;
	void RenderPresent() final;
	void RenderClear() final;
	std::unique_ptr<ITexture> LoadTexture(const std::string& file_path) const final;

private:
	/// <summary> A pointer to the renderer. </summary>
	std::unique_ptr<SDL_Renderer, SDL_Destructor<SDL_Renderer>> _p_renderer;
};


} // view
} // pacman
