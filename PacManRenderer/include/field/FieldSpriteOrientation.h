#pragma once
#define DllExport __declspec( dllexport )

namespace pacman {
namespace renderer {
  
/// <summary>
/// <see cref="FieldSpriteOrientation" /> describes the orientation
/// of a sprite of a field tile.
/// </summary>
struct DllExport FieldSpriteOrientation {    
  /// <summary>
  /// Initializes a new <see cref="FieldSpriteOrientation"/>.
  /// </summary>
  /// <param name="rotation">The rotation.</param>
  /// <param name="isFlippedX">Whether the corresponding sprite should be flipped on the x-axis.</param>
  /// <param name="isFlippedY">Whether the corresponding sprite should be flipped on the y-axis.</param>
  FieldSpriteOrientation(float rotation,
                         bool isFlippedX=false,
                         bool isFlippedY=false) : 
      Rotation(rotation), 
      IsFlippedX(isFlippedX), 
      IsFlippedY(isFlippedY) {}

  /// <summary>
  /// The rotation in degrees of the corresponding sprite.
  /// </summary>
  const float Rotation;
  
  /// <summary>
  /// Whether the corresponding sprite should be flipped on the x-axis.
  /// </summary>
  const bool IsFlippedX;

  /// <summary>
  /// Whether the corresponding sprite should be flipped on the y-axis.
  /// </summary>
  const bool IsFlippedY;
};

}
}
