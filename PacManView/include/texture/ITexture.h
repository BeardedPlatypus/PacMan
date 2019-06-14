#pragma once
#define DllExport __declspec( dllexport )

#include <SDL2/SDL.h>
#include <renderer/IRenderer.h>


namespace pacman {
namespace view {

/// <summary>
/// ITexture describes the interface with which the View system interacts
/// with textures.
/// </summary>
class DllExport ITexture {
public:
	virtual ~ITexture() {}

	/// <summary>
	/// Get the dimensions of this <see cref="ITexture" />.
	/// </summary>
	/// <returns> 
	/// An <see cref="SDL_Rect" /> describing the dimensions of this texture. 
	/// </returns>
	virtual SDL_Rect GetDimensions() const = 0;
	
	/// <summary>
	/// Render the specified <paramref name="clip" /> of this 
	/// <see cref="ITexture" /> to the specified <paramref name="dst" />.
	/// </summary>
	/// <param name="renderer"> The renderer. </param>
	/// <param name="clip"> The section of the texture to render. </param>
	/// <param name="dst"> The destination to which the render. </param>
	virtual void Render(IRenderer& renderer,
						SDL_Rect& clip,
						SDL_Rect& dst) const = 0;
};

}
}