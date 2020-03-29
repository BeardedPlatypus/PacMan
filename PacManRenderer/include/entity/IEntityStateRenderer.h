#pragma once

namespace pacman {
namespace renderer {
namespace entity {

/// <summary>
/// <see cref="IEntityStateRenderer"/> defines the methods to render a single state.
/// </summary>
class IEntityStateRenderer {
public:  
  /// <summary>
  /// Initialises this <see cref="IEntityStateRenderer"/>.
  /// </summary>
  virtual void Initialise() = 0;
  
  /// <summary>
  /// Updates this <see cref="IEntityStateRenderer"/> with the provided 
  /// <paramref cref="dtime"/>.
  /// </summary>
  /// <param name="dtime">The time elapsed since the last update.</param>
  virtual void Update(float dtime) = 0;
  
  /// <summary>
  /// Render the state associated with this <see cref="IEntityStateRenderer" />.
  /// </summary>
  /// <param name="scale">The scale with which this <see cref="IEntityStateRenderer" /> renders.</param>
  /// <param name="render_offset_y">The offset to render with on the y-axis.</param>
  virtual void Render(float scale,
                      float render_offset_y) const = 0;
};

}
}
}
