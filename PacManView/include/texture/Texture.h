#pragma once

#include "texture/ITexture.h"
#include "sdl_util/SDLDestructor.h"


namespace pacman {
namespace view {

/// <summary>
/// Thin wrapper around the SDL_Texture object.
/// </summary>
/// <seealso cref="ITexture" />
class Texture final : public ITexture {
public:	
	/// <summary>
	/// Construct a new <see cref="Texture"/> with the given 
	/// <paramref name="p_tex" />.
	/// </summary>
	/// <param name="p_tex">
	/// A pointer to the texture which is managed by this 
	/// <see cref="Texture" />.
	/// </param>
	Texture(SDL_Texture* p_tex);
	
	/// <summary>
	/// Get the dimensions of this <see cref="ITexture" />.
	/// </summary>
	/// <returns>
	/// An <see cref="SDL_Rect" /> describing the dimensions of this texture.
	/// </returns>
	SDL_Rect GetDimensions() const final;
	
  /// <summary>
  /// Render the specified <paramref name="clip" /> of this
  /// <see cref="ITexture" /> to the specified <paramref name="dst" />.
  /// </summary>
  /// <param name="renderer">The renderer.</param>
  /// <param name="clip">The section of the texture to render.</param>
  /// <param name="dst">The destination to which the render.</param>
  /// <param name="angle">The angle in degrees.</param>
  /// <param name="flip_horizontally">if set to <c>true</c> [flip horizontally].</param>
  /// <param name="flip_vertically">if set to <c>true</c> [flip vertically].</param>
  void Render(IRenderer& renderer,
				      SDL_Rect& clip,
				      SDL_Rect& dst,
              float angle, 
              bool flip_horizontally,
              bool flip_vertically) const final;

private:		
	/// <summary> A pointer to the SDL_Texture object. </summary>
	std::unique_ptr<SDL_Texture, SDL_Destructor<SDL_Texture>> p_tex;
};

}
}
