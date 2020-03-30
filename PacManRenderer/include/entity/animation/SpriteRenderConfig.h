#pragma once

#include <string>

namespace pacman {
namespace renderer {
namespace entity {
namespace animation {

/// <summary>
/// <see cerf="SpriteRenderConfig"/> contains all relevant data to
/// initialise and render a sprite.
/// </summary>
class SpriteRenderConfig {
public:  
  /// <summary>
  /// Creates a new <see cref="SpriteRenderConfig"/>.
  /// </summary>
  /// <param name="sprite_label">The sprite label.</param>
  /// <param name="texture_file_path">The texture file path.</param>
  /// <param name="x">The x position of the sprite.</param>
  /// <param name="y">The y position of the sprite.</param>
  /// <param name="w">The width of the sprite.</param>
  /// <param name="h">The height of the sprite.</param>
  SpriteRenderConfig(const std::string& sprite_label,
                     const std::string& texture_file_path,
                     int x, int y, int w, int h) : 
      _sprite_label(sprite_label),
      _texture_file_path(texture_file_path),
      _x(x), _y(y), _w(w), _h(h) { }
  
  /// <summary>
  /// Gets the sprite label.
  /// </summary>
  /// <returns>The sprite label.</returns>
  inline const std::string GetSpriteLabel() const { return this->_sprite_label; }
  
  /// <summary>
  /// Gets the texture file path.
  /// </summary>
  /// <returns>The texture file path.</returns>
  inline const std::string GetTextureFilePath() const { return this->_texture_file_path; }  

  /// <summary>
  /// Gets the x position of the sprite.
  /// </summary>
  /// <returns>The x position of the sprite.</returns>
  inline int GetX() const { return this->_x; }

  /// <summary>
  /// Gets the y position of the sprite.
  /// </summary>
  /// <returns>The y position of the sprite.</returns>
  inline int GetY() const { return this->_y; }
  
  /// <summary>
  /// Gets the width of the sprite.
  /// </summary>
  /// <returns>The width of the sprite.</returns>
  inline int GetW() const { return this->_w; }

  /// <summary>
  /// Gets the height of the sprite.
  /// </summary>
  /// <returns>The height of the sprite.</returns>
  inline int GetH() const { return this->_h; }
private:
  const std::string _sprite_label;
  const std::string _texture_file_path;

  const int _x; 
  const int _y; 
  const int _w;
  const int _h;
};

}
}
}
}
