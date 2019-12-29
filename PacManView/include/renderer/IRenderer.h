#pragma once

#include <SDL2/SDL.h>
#include <string>
#include <memory>


namespace pacman {
namespace view {

class ITexture;

/// <summary>
/// <see cref="IRenderer"/> interface defines the functions to render SDL objects. 
/// </summary>
class IRenderer {
public:	
	/// <summary>
	/// Construct a new <see cref="IRenderer"/>.
	/// </summary>
	/// <returns>
	/// A <see cref="std::unique_ptr"/> to a new <see cref="IRenderer"/>
	/// </returns>
	static std::unique_ptr<IRenderer> Construct();

	virtual ~IRenderer() = default;

	/// <summary>
	/// Initialise this <see cref="IRenderer"/> with the specified window pointer.
	/// </summary>
	/// <param name="p_window"> The pointer to the window. </param>
	virtual void Init(SDL_Window* p_window) = 0;

  /// <summary>
  /// Copy the specified <paramref name="sprite"/> at the specified
  /// (<paramref name="x"/>, <paramref name="y"/>) location with the
  /// specified <paramref name="scale"/> to the render buffer.
  /// </summary>
  /// <param name="p_texture"> The p texture. </param>
  /// <param name="p_texture_clip"> The p texture clip. </param>
  /// <param name="p_destination"> The p destination. </param>
  /// <param name="angle"> The angle in degrees. </param>
  /// <param name="flip_horizontally"> If set to <c>true</c> [flip horizontally]. </param>
  /// <param name="flip_vertically"> If set to <c>true</c> [flip vertically]. </param>
  virtual void RenderCopy(SDL_Texture* p_texture,
							            const SDL_Rect* p_texture_clip,
							            const SDL_Rect* p_destination,
                          float angle, 
                          bool flip_horizontally,
                          bool flip_vertically) = 0;

	/// <summary>
	/// Present the current render buffer contents.
	/// </summary>
	virtual void RenderPresent() = 0;

	/// <summary>
	/// Clear the current render buffer contents.
	/// </summary>
	virtual void RenderClear() = 0;

	/// <summary>
	/// Load the texture at <paramref name="file_path"/>.
	/// </summary>
	/// <param name="file_path"> The file path. </param>
	/// <returns> A pointer to the loaded texture. </returns>
	virtual std::unique_ptr<ITexture> LoadTexture(const std::string& file_path) const = 0;
};

}
}
