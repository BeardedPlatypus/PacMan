#pragma once

#include <string>
#include "texture/ITextureManager.h"
#include "sprite/Sprite.h"
#include "sprite/ISpriteAnimation.h"


namespace pacman {
namespace view {

/// <summary>
/// <see cref="ISpriteManager"/> is responsible for storing all Sprites
/// constructed within the PacMan game. It provides methods to request new
/// <see cref="Sprite"/>s and <see cref="SpriteAnimation"/>s.
/// </summary>
class ISpriteManager {
public:  
  /// <summary>
  /// Construct a new <see cref="ISpriteManager"/> with the given 
  /// <paramref name="texture_manager"/>.
  /// </summary>
  /// <param name="texture_manager"> The texture manager. </param>
  /// <returns>
  /// A <see cref="std::unique_ptr<ISpriteManager"/> containing a new
  /// <see cref="ISpriteManager"/>.
  /// </returns>
  static std::unique_ptr<ISpriteManager> Construct(ITextureManager& texture_manager);
  
  /// <summary>
  /// Initialise a new <see cref="Sprite"/> with the given <paramref name="label">,
  /// clipping the texture specified with <paramref name="sprite_sheet_path"/>.
  /// </summary>
  /// <param name="label"> The new label of the <see cref="Sprite"/>. </param>
  /// <param name="sprite_sheet_path"> The path to the sprite sheet. </param>
  /// <param name="x">
  /// The x-axis pixel location of the clip of the new <see cref="Sprite"/>.
  /// </param>
  /// <param name="y">
  /// The y-axis pixel location of the clip of the new <see cref="Sprite"/>.
  /// </param>
  /// <param name="w">
  /// The width of the clip of the new <see cref="Sprite"/>.
  /// </param>
  /// <param name="h">
  /// The height of the clip of the new <see cref="Sprite"/>.
  /// </param>
  /// <exception cref="ViewException"> 
  /// this->HasSprite(label) ||
  /// <paramref name="w" /> <= 0 || <paramref name="h" /> <= 0
  /// </exception>
  virtual void InitSprite(const std::string& label,
						              const std::string& sprite_sheet_path,
						              int x, int y, int w, int h) = 0;
  
  /// <summary>
  /// Initialise a new <see cref="Sprite"/> with the given <paramref name="label"/>,
  /// describing the whole texture specified with <paramref name="sprite_sheet_path"/>.
  /// </summary>
  /// <param name="label"> The new label of the <see cref="Sprite"/>. </param>
  /// <param name="sprite_sheet_path"> The path to the sprite sheet. </param>
  /// <exception cref="ViewException"> 
  /// this->HasSprite(label)
  /// </exception>
  virtual void InitSprite(const std::string& label,
						              const std::string& sprite_sheet_path) = 0;
  
  /// <summary>
  /// Determine whether a <see cref="Sprite"/> with the corresponding 
  /// <paramref name="label"/> exists within this <see cref="ISpriteManager"/>.
  /// </summary>
  /// <param name="label"> The label of the <see cref="Sprite"/>. </param>
  /// <returns>
  /// <c>true</c> if the specified <see cref="Sprite"/> exists within this
  /// <see cref="ISpriteManager"/>; 
  /// otherwise, <c>false</c>.
  /// </returns>
  virtual bool HasSprite(const std::string& label) const = 0;
  
  /// <summary>
  /// Get the <see cref="Sprite"/> associated with the <paramref name="label"/>.
  /// </summary>
  /// <param name="label"> 
  /// The label with which a <see cref="Sprite"/> is associated. 
  /// </param>
  /// <returns>
  /// The <see cref="Sprite"/> associated with the specified 
  /// <paramref name="label"/>.
  /// </returns>
  /// <exception cref="ViewException"> NOT this->HasSprite(label) </exception>
  virtual const Sprite& GetSprite(const std::string& label) const = 0;
  
  /// <summary>
  /// Initialise a new <see cref="ISpriteAnimation"/> with the given 
  /// <paramref name="label"/>, <paramref name="time_per_frame"/> and a set
  /// of sprite labels in <paramref name="sprites"/>.
  /// </summary>
  /// <param name="label"> The label of the new <see cref="ISpriteAnimation" />. </param>
  /// <param name="time_per_frame"> The time per frame. </param>
  /// <param name="sprites"> The set of sprite labels. </param>
  /// <exception cref="ViewException"> 
  /// this->hasSpriteAnimation(label) ||
  /// <paramref name="time_per_frame" /> <= 0.F ||
  /// FOR label IN sprites: NOT this->HasSprite(sprite_label)
  /// </exception>
  virtual void InitSpriteAnimation(const std::string& label,
								                   float time_per_frame,
								                   const std::vector<std::string>& sprites) = 0;

  /// <summary>
  /// Determine whether a <see cref="ISpriteAnimation"/> with the corresponding 
  /// <paramref name="label"/> exists within this <see cref="ISpriteManager"/>.
  /// </summary>
  /// <param name="label"> The label of the <see cref="ISpriteAnimation"/>. </param>
  /// <returns>
  /// <c>true</c> if the specified <see cref="ISpriteAnimation"/> exists within this
  /// <see cref="ISpriteManager"/>; 
  /// otherwise, <c>false</c>.
  /// </returns>
  virtual bool HasSpriteAnimation(const std::string& label) const = 0;
  
  /// <summary>
  /// Get the <see cref="ISpriteAnimation"/> associated with the <paramref name="label"/>.
  /// </summary>
  /// <param name="label">
  /// The label with which a <see cref="ISpriteAnimation"/> is associated.
  /// </param>
  /// <returns>
  /// The <see cref="ISpriteAnimation"/> associated with the specified
  /// <paramref name="label"/>.
  /// </returns>
  /// <exception cref="ViewException"> 
  /// NOT this->HasSpriteAnimation(label) 
  /// </exception>
  virtual ISpriteAnimation* GetSpriteAnimation(const std::string& label) = 0;
};

}
}
