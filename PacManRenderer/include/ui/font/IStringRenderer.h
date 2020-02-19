#pragma once

#include <memory>
#include <string>


namespace pacman {
namespace renderer {
namespace ui {

/// <summary>
/// <see cref="IStringRenderer"/> defines the interface with which strings can
/// be rendered.
/// </summary>
class IStringRenderer {
public:
  ~IStringRenderer() = default;
  
  /// <summary>
  /// Renders the specified <paramref name="string"/> at the specified location
  /// with the specified <paramref name="scale"/>.
  /// </summary>
  /// <param name="string">The string.</param>
  /// <param name="x">The x.</param>
  /// <param name="y">The y.</param>
  /// <param name="scale">The scale.</param>
  virtual void RenderString(std::string string, float x, float y, float scale) = 0;
};

}
}
}
