#pragma once


namespace pacman {
namespace renderer {
  
/// <summary>
/// <see cref="IRenderComponent" /> provides the methods required
/// to be implemented for a component to be rendered.
/// </summary>
class IRenderLayer {
public:
  virtual ~IRenderLayer() = default;
  
  /// <summary>
  /// Initialise this <see cref="IRenderComponent" />.
  /// </summary>
  virtual void Initialise() = 0;

  /// <summary>
  /// Render this <see cref="IRenderComponent" />.
  /// </summary>
  virtual void Render() const = 0;
};

}
}
