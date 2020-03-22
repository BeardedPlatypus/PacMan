#pragma once

#include <string>

namespace pacman {
namespace renderer {
namespace entity {
namespace render {

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
