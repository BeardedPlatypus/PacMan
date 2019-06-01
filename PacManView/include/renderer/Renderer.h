#pragma once

#include "IRenderer.h"
#include <memory>

#include "sdl_util/SDLDestructor.h"


namespace pacman {
namespace view {

/// <summary>
/// Thin wrapper around the SDL_Renderer object.
/// </summary>
/// <seealso cref="IRenderer" />
class Renderer final : public IRenderer {
public:	
	/// <summary>
	/// Construct a new <see cref="Renderer"/>.
	/// </summary>
	Renderer();
	
	/// <summary>
	/// Finalize this instance of the <see cref="Renderer"/> class.
	/// </summary>
	~Renderer() final;
	
	/// <summary>
	/// Initialize this <see cref="Renderer" /> with the specified window pointer.
	/// </summary>
	/// <param name="p_window"> The pointer to the window. </param>
	void Init(SDL_Window* p_window);

	/// <summary>
	/// Copy the specified <paramref name="sprite" /> at the specified 
	/// (<paramref name="x" />, <paramref name="y" />) location with the 
	/// specified <paramref name="scale" />.
	/// </summary>
	/// <param name="sprite">The sprite.</param>
	/// <param name="x">The x location.</param>
	/// <param name="y">The y location.</param>
	/// <param name="scale">The scale.</param>
	void RenderCopy(SDL_Texture* p_texture,
	                const SDL_Rect* p_texture_clip,
				   	const SDL_Rect* p_destination) final;
	
	/// <summary>
	/// Present the current render buffer contents.
	/// </summary>
	void RenderPresent() final;
	
	/// <summary>
	/// Clear the current render buffer contents.
	/// </summary>
	void RenderClear() final;
	
	/// <summary>
	/// Load the texture at <paramref name="file_path" />.
	/// </summary>
	/// <param name="file_path">The file path.</param>
	/// <returns>
	/// A pointer to the loaded texture.
	/// </returns>
	std::unique_ptr<ITexture> LoadTexture(const std::string& file_path) const final;

private:
	/// <summary> A pointer to the renderer. </summary>
	std::unique_ptr<SDL_Renderer, SDL_Destructor<SDL_Renderer>> p_renderer;
};


} // view
} // pacman
