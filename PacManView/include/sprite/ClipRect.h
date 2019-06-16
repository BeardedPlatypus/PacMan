#pragma once
#define DllExport __declspec( dllexport )


namespace pacman {
namespace view {

/// <summary>
/// A simple constant struct used to denote a Clipping rectangle used within
/// <see cref="Sprite">. It provides a constructor, and 4 fields used 
/// to store the relevant information.
/// </summary>
struct DllExport ClipRect {	
public:
  /// <summary>
  /// Construct a new <see cref="ClipRect"/> with the given parameters.
  /// </summary>
  /// <param name="x"> The x position in pixels. </param>
  /// <param name="y"> The y position in pixels. </param>
  /// <param name="w"> The width in pixels. </param>
  /// <param name="h"> The height in pixels. </param>
  ClipRect(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) { }
	
  /// <summary> The x position in pixels. </summary>
  const int x;
  /// <summary> The y position in pixels. </summary>
  const int y;	
  /// <summary> The width in pixels. </summary>
  const int w;	
  /// <summary> The height in pixels. </summary>
  const int h;
};

}
}
