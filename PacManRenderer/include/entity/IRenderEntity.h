#pragma once

namespace pacman {
namespace renderer {
namespace entity {

/// <summary>
/// <see cref="IRenderEntity"/> defines the methods to render entities.
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
  /// Renders this <see cref="IRenderEntity"/>.
  /// </summary>
  virtual void Render() const = 0;
};

}
}
}
