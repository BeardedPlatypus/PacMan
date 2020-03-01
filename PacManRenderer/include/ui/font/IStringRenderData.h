#pragma once

#include <string>
#include <ui/font/Justification.h>


namespace pacman {
namespace renderer {
namespace ui {

/// <summary>
/// <see cref="IStringRenderData"/> defines the interface with which to
/// a string can be rendered.
/// </summary>
class IStringRenderData {
public:
  ~IStringRenderData() = default;
  
  /// <summary>
  /// Gets the string to render.
  /// </summary>
  /// <returns>The string to render.</returns>
  virtual const std::string GetString() const = 0;
  
  /// <summary>
  /// Gets the x location to render at.
  /// </summary>
  /// <returns>The x location to render at.</returns>
  virtual float GetX() const = 0;

  /// <summary>
  /// Gets the y location to render at.
  /// </summary>
  /// <returns>The y location to render at.</returns>
  virtual float GetY() const = 0;
  
  /// <summary>
  /// Gets the font scale.
  /// </summary>
  /// <returns>The font scale.</returns>
  virtual float GetFontScale() const = 0;
  
  /// <summary>
  /// Gets the font justification.
  /// </summary>
  /// <returns>The font justification.</returns>
  virtual Justification GetJustification() const = 0;
};

}
}
}
