#pragma once

#include <SDL2/SDL.h>

#include "renderer/IRenderer.h"
#include "texture/ITexture.h"


namespace pacman {
namespace view {

/// <summary>
/// <see cref="Sprite"/> describes a clipped section of a <see cref="ITexture"/>. 
/// It contains the logic to render this section at a given position, with a
/// given size.
/// </summary>
class Sprite {
public:	
	/// <summary>
	/// Create a new <see cref="Sprite"/> describing the specified subsection
	/// of <paramref name="tex"/>.
	/// </summary>
	/// <param name="tex"> 
	/// Reference to the texture on which this sprite is located.
	/// </param>
	/// <param name="x"> The x position of the sprite within the texture. </param>
	/// <param name="y"> The y position of the sprite within the texture. </param>
	/// <param name="w"> The width of the sprite. </param>
	/// <param name="h"> The height of the sprite. </param>
	Sprite(const ITexture& tex, int x, int y, int w, int h);
	
	/// <summary>
	/// Creates a new <see cref="Sprite"/> describing the whole <paramref name="tex"/>.
	/// </summary>
	/// <param name="tex"> 
	/// Reference to the texture which this sprite describes. 
	/// </param>
	explicit Sprite(const ITexture& tex);
	
	/// <summary>
	/// Get the clipping rectangle of this <see cref="Sprite" />.
	/// </summary>
	/// <returns> 
	/// An SDL_rect describing the clipping rectangle of this 
	/// <see cref="Sprite" />.
	/// </returns>
	inline SDL_Rect GetClip() const { return this->clip; }
	
	/// <summary>
	/// Get the <see cref="ITexture"> of this <see cref="Sprite" />.
	/// </summary>
	/// <returns> 
	/// The <see cref="ITexture"> of this <see cref="Sprite" />. 
	/// </returns>
	inline const ITexture& GetTexture() const { return this->texture; }
	
  /// <summary>
  /// Renders the specified renderer.
  /// </summary>
  /// <param name="renderer">The renderer.</param>
  /// <param name="x">The x.</param>
  /// <param name="y">The y.</param>
  /// <param name="scale">The scale.</param>
  /// <param name="angle">The angle.</param>
  /// <param name="flip_horizontally">if set to <c>true</c> [flip horizontally].</param>
  /// <param name="flip_vertically">if set to <c>true</c> [flip vertically].</param>
  void Render(IRenderer& renderer,
              float x, 
              float y, 
              float scale,
              float angle,
              bool flip_horizontally,
              bool flip_vertically) const;

private:	
	/// <summary> 
	/// The <see cref="ITexture" /> which this <see cref="Sprite" /> links to.
	/// </summary>
	const ITexture& texture;	

	/// <summary> 
	/// The section of the <see cref="ITexture" /> of this sprite. 
	/// </summary>
	SDL_Rect clip;
};

}
}
