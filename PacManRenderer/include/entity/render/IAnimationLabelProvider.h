#pragma once

#include <string>

namespace pacman {
namespace renderer {
namespace entity {
namespace render {

/// <summary>
/// <see cref="IAnimationLabelProvider"/> defines the GetActiveAnimationLabel, 
/// which determines which animation is currently being rendered.
/// </summary>
class IAnimationLabelProvider {
public:
  virtual ~IAnimationLabelProvider() = default;
  
  /// <summary>
  /// Gets the active animation label.
  /// </summary>
  /// <returns>
  /// The active animation label.
  /// </returns>
  virtual const std::string& GetActiveAnimationLabel() const = 0;
};

}
}
}
}
