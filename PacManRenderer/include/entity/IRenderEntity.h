#pragma once

namespace pacman {
namespace renderer {
namespace entity {

/// <summary>
/// <see cref="IRenderEntity"/> defines the methods to render an entity.
/// </summary>
class IRenderEntity {
public:  
  /// <summary>
  /// Initialises this <see cref="IRenderEntity"/>.
  /// </summary>
  virtual void Initialise() = 0;
  
  /// <summary>
  /// Updates this <see cref="IRenderEntity"/> with the provided 
  /// <paramref cref="dtime"/>.
  /// </summary>
  /// <param name="dtime">The time elapsed since the last update.</param>
  virtual void Update(float dtime) = 0;
  
  /// <summary>
  /// Render this <see cref="IRenderEntity" />.
  /// </summary>
  /// <param name="scale">The scale with which to render this <see cref="IRenderEntity" />.</param>
  /// <param name="render_offset_y">The offset to render with on the y-axis.</param>
  virtual void Render(float scale,
                      float render_offset_y) const = 0;
};

}
}
}
