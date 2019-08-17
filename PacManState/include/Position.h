#pragma once
#define DllExport __declspec( dllexport )


namespace pacman {
namespace state {

/// <summary>
/// The <see cref="Position" /> struct describes a position within the 2D
/// world, through the x and y properties.
/// </summary>
struct DllExport Position {  
  /// <summary>
  /// Construct a new <see cref="Position"/>.
  /// </summary>
  /// <param name="x"> The world x-position. </param>
  /// <param name="y"> The world y-position. </param>
  Position(float x, float y) : x(x), y(y) { }
  
  /// <summary> The world x-position. </summary>
  const float x;
  /// <summary> The world y-position. </summary>
  const float y;
};

}
}
