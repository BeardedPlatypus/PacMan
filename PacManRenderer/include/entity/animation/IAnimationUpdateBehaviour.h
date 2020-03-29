#pragma once

namespace pacman {
namespace renderer {
namespace entity {
namespace animation {

/// <summary>
/// <see cref="IAnimationUpdateBehaviour"/> provides the method to update
/// the associated animation with.
/// </summary>
class IAnimationUpdateBehaviour {
public:  
  /// <summary>
  /// Updates the associated animation label with the specified time difference.
  /// </summary>
  /// <param name="dtime">The time difference.</param>
  virtual void Update(float dtime) = 0;
};

}
}
}
}
