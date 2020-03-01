#pragma once

#include <memory>
#include <string>

#include "ui/font/IStringRenderData.h"
#include "ui/font/Justification.h"


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
  /// Initialises this <see cref="IStringRenderer"/>.
  /// </summary>
  virtual void Initialise() = 0;
  
  /// <summary>
  /// Renders the specified <paramref name="string" /> at the specified location
  /// with the specified <paramref name="scale" />.
  /// </summary>
  /// <param name="string_data">The string data.</param>
  /// <param name="scale">The scale with which to render.</param>
  virtual void RenderString(const IStringRenderData& string_data, float scale) = 0;
};

}
}
}
