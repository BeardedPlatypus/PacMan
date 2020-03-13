#pragma once
#include <IViewAPI.h>


namespace pacman {
namespace renderer {
namespace objects {

/// <summary>
/// <see cref="IObjectRenderer"/> provides the interface to render a specific
/// object with a provided <see cref="view::IViewAPI"/> at a specified location.
/// </summary>
class IObjectRenderer {
public:    
  /// <summary>
  /// Initialises this <see cref="IObjectRenderer"/> such 
  /// that <see cref="RenderObject"/> can be called.
  /// </summary>
  virtual void Initialise() = 0;

  /// <summary>
  /// Render the corresponding object of this <see cref="IObjectRenderer" />.
  /// </summary>
  /// <param name="x">The x tile index to render at.</param>
  /// <param name="y">The y tile index to render at.</param>
  /// <param name="scale">The scale to render with.</param>
  /// <param name="render_offset_y">The render offset y.</param>
  virtual void RenderObject(int x, int y, float scale, float render_offset_y) const = 0;
};

}
}
}
