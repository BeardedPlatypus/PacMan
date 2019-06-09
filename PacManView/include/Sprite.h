#pragma once
#define DllExport __declspec( dllexport )

#include <SDL2/SDL.h>

#include "renderer/IRenderer.h"
#include "texture/ITexture.h"


namespace pacman {
namespace view {

/// <summary>
/// A Sprite describing a clipped section of a <see cref="ITexture" />. 
/// It contains the logic to render this section at a given position, with a
/// given size.
/// </summary>
class DllExport Sprite {
public:	
	/// <summary>
	/// Construct a new instance of the <see cref="Sprite"/> class.
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
	/// Construct a new instance of the <see cref="Sprite"/> class 
	/// describing the whole <paramref name="tex" />.
	/// </summary>
	/// <param name="tex"> 
	/// Reference to the texture which this sprite describes. 
	/// </param>
	Sprite(const ITexture& tex);
	
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
	/// Render this <see cref="Sprite" /> with the given 
	/// <paramref name="renderer /> at the given location with the given scale.
	/// </summary>
	/// <param name="renderer">The renderer used .</param>
	/// <param name="x"> The x location. </param>
	/// <param name="y"> The y location. </param>
	/// <param name="scale"> The scale. </param>
	void Render(IRenderer& renderer, float x, float y, float scale) const;

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
