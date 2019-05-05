#pragma once
#define DllExport __declspec( dllexport )


#include <SDL.h>

namespace pacman {
namespace view {

class DllExport Sprite {
public:	
	/// <summary>
	/// Construct a new instance of the <see cref="Sprite"/> class.
	/// </summary>
	/// <param name="tex">Reference to the texture on which this sprite is located.</param>
	/// <param name="x">The x position of the sprite within the texture.</param>
	/// <param name="y">The y position of the sprite within the texture.</param>
	/// <param name="w">The width of the sprite.</param>
	/// <param name="h">The height of the sprite.</param>
	Sprite(SDL_Texture& tex,
		   int x, int y, int w, int h);

	Sprite(SDL_Texture& tex);

	void Render(SDL_Renderer& renderer,
				float x, float y, float scale) const;

private:
	SDL_Texture& texture;
	SDL_Rect clip;
};

}
}
