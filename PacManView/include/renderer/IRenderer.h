#pragma once
#define DllExport __declspec( dllexport )

#include <SDL2\SDL.h>
#include <string>
#include <memory>


namespace pacman {
namespace view {

class ITexture;

/// <summary>
/// IRenderer interface defines the functions to render SDL objects. 
/// </summary>
class DllExport IRenderer {
public:	
	/// <summary>
	/// Construct a new <see cref="IRenderer" />.
	/// </summary>
	/// <returns>
	/// A <see cref="std::unique_ptr" /> to a new <see cref="IRenderer" />
	/// </returns>
	static std::unique_ptr<IRenderer> construct();

	virtual ~IRenderer() {}

	/// <summary>
	/// Copy the specified <paramref name="sprite" /> at the specified 
	/// (<paramref name="x" />, <paramref name="y" />) location with the 
	/// specified <paramref name="scale" />.
	/// </summary>
	/// <param name="sprite">The sprite.</param>
	/// <param name="x">The x location.</param>
	/// <param name="y">The y location.</param>
	/// <param name="scale">The scale.</param>
	virtual void RenderCopy(SDL_Texture* p_texture,
							const SDL_Rect* p_texture_clip,
							const SDL_Rect* p_destination) = 0;

	/// <summary>
	/// Present the current render buffer contents.
	/// </summary>
	virtual void RenderPresent() = 0;

	/// <summary>
	/// Clear the current render buffer contents.
	/// </summary>
	virtual void RenderClear() = 0;

	/// <summary>
	/// Load the texture at <paramref name="file_path" />.
	/// </summary>
	/// <param name="file_path"> The file path. </param>
	/// <returns> A pointer to the loaded texture. </returns>
	virtual std::unique_ptr<ITexture> LoadTexture(const std::string& file_path) const = 0;
};

}
}
