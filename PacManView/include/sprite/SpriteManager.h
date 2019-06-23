#pragma once

#include <map>
#include <string>

#include "texture/ITextureManager.h"
#include "sprite/ISpriteManager.h"
#include "sprite/Sprite.h"
#include "sprite/SpriteAnimation.h"

namespace pacman {
namespace view {

/// <summary>
/// <see cref="SpriteManager" /> implements <see cref="ISpriteManager" />.
/// It is responsible for storing all <see cref="Sprite" />s  constructed within the PacMan 
/// game. It provides the methods to request new <see cref="Sprite" />s and
/// <see cref="SpriteAnimation" />s.
/// </summary>
class SpriteManager final : public ISpriteManager {
public:	
  /// <summary>
  /// Construct a new <see cref="SpriteManager"/> with the given 
  /// <paramref name="texture_manager" />.
  /// </summary>
  /// <param name="texture_manager">The texture manager.</param>
  SpriteManager(ITextureManager& texture_manager);

  void initSprite(const std::string& label,
                  const std::string& sprite_sheet_path, 
                  int x, int y, int w, int h) final;

  void initSprite(const std::string& label,
                  const std::string& sprite_sheet_path) final;

  bool hasSprite(const std::string& label) const final;

  const Sprite& getSprite(const std::string& label) const final;

  void initSpriteAnimation(const std::string& label,
						   float time_per_frame,
						   const std::vector<std::string>& sprites) final;

  bool hasSpriteAnimation(const std::string& label) const final;

  SpriteAnimation& getSpriteAnimation(const std::string& label) final;

private:	
	/// <summary> 
	/// Map containing labels to <see cref="Sprite" />. 
	/// </summary>
	std::map<std::string, Sprite> sprite_map;
	
	/// <summary>
	/// Map containing labels to <see cref="SpriteAnimation" />.
	/// </summary>
	std::map<std::string, SpriteAnimation> sprite_animation_map;
	
  /// <summary> 
  /// Get the texture associated with the provided 
  /// <paramref name="texture_path" />.
  /// </summary>
  /// <param name="texture_path"> The texture path. </param>
  /// <returns> 
  /// The <see cref="ITexture" /> associated the specified 
  /// <paramref name="texture_path" />
  /// </returns>
  const ITexture& getTexture(const std::string& texture_path);
	
	/// <summary>
	/// A reference to <see cref="ITextureManager" /> this 
	/// <see cref="SpriteManager" /> uses.
	/// </summary>
	ITextureManager& texture_manager;
};

}
}
