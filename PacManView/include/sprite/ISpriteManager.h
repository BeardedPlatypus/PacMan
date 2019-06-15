#pragma once
#define DllExport __declspec( dllexport )

#include <string>
#include "texture/ITextureManager.h"
#include "sprite/Sprite.h"
#include "sprite/SpriteAnimation.h"


namespace pacman {
namespace view {

/// <summary>
/// <see cref="ISpriteManager" /> is responsible for storing all Sprites
/// constructed within the PacMan game. It provides methods to request new
/// <see cref="Sprite" />s and <see cref="SpriteAnimation" />s.
/// </summary>
class  DllExport ISpriteManager {
public:  
  /// <summary>
  /// Construct a new <see cref="ISpriteManager" /> with the given 
  /// <paramref name="texture_manager" />.
  /// </summary>
  /// <param name="texture_manager"> The texture manager. </param>
  /// <returns>
  /// A <see cref="std::unique_ptr<ISpriteManager" /> containing a new
  /// <see cref="ISpriteManager" />.
  /// </returns>
  static std::unique_ptr<ISpriteManager> construct(ITextureManager& texture_manager);
  
  /// <summary>
  /// Initialize a new <see cref="Sprite" /> with the given <paramref name="label">,
  /// clipping the texture specified with <paramref name="sprite_sheet_path" />.
  /// </summary>
  /// <param name="label"> The new label of the <see cref="Sprite" />. </param>
  /// <param name="sprite_sheet_path"> The path to the sprite sheet. </param>
  /// <param name="x">
  /// The x-axis pixel location of the clip of the new <see cref="Sprite" />.
  /// </param>
  /// <param name="y">
  /// The y-axis pixel location of the clip of the new <see cref="Sprite" />.
  /// </param>
  /// <param name="w">
  /// The width of the clip of the new <see cref="Sprite" />.
  /// </param>
  /// <param name="h">
  /// The height of the clip of the new <see cref="Sprite" />.
  /// </param>
  virtual void initSprite(const std::string& label,
						  const std::string& sprite_sheet_path,
						  int x, int y, int w, int h) = 0;
  
  /// <summary>
  /// Initialize a new <see cref="Sprite" /> with the given <paramref name="label" />,
  /// describing the whole texture specified with <paramref name="sprite_sheet_path" />.
  /// </summary>
  /// <param name="label"> The new label of the <see cref="Sprite" />. </param>
  /// <param name="sprite_sheet_path"> The path to the sprite sheet. </param>
  virtual void initSprite(const std::string& label,
						  const std::string& sprite_sheet_path) = 0;
  
  /// <summary>
  /// Get the <see cref="Sprite" /> associated with the <paramref name="label" />.
  /// </summary>
  /// <param name="label"> 
  /// The label with which a <see cref="Sprite" /> is associated. 
  /// </param>
  /// <returns>
  /// The <see cref="Sprite" /> associated with the specified 
  /// <paramref name="label" />.
  /// </returns>
  virtual const Sprite& getSprite(const std::string& label) const = 0;
  
  /// <summary>
  /// Initialize a new <see cref="SpriteAnimation" /> with the given 
  /// <paramref name="label" />, <paramref name="time_per_frame" /> and a set
  /// of sprite labels in <paramref name="sprites" />.
  /// </summary>
  /// <param name="label"> The label of the new <see cref="SpriteAnimation" />. </param>
  /// <param name="time_per_frame"> The time per frame. </param>
  /// <param name="sprites"> The set of sprite labels. </param>
  virtual void initSpriteAnimation(const std::string& label,
								   float time_per_frame,
								   const std::vector<std::string>& sprites) = 0;
  
  /// <summary>
  /// Get the <see cref="SpriteAnimation" /> associated with the <paramref name="label" />.
  /// </summary>
  /// <param name="label">
  /// The label with which a <see cref="SpriteAnimation" /> is associated.
  /// </param>
  /// <returns>
  /// The <see cref="SpriteAnimation" /> associated with the specified
  /// <paramref name="label" />.
  /// </returns>
  virtual SpriteAnimation& getSpriteAnimation(const std::string& label) = 0;
};

}
}
