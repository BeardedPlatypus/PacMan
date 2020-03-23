#pragma once

namespace pacman {
namespace renderer {
namespace entity {
namespace render {

/// <summary>
/// <see cref="IValueProvider{T}"/> provides a generic method to obtain the
/// current <typeparamref cref="T"/>.
/// </summary>
template <typename T>
class IValueProvider {
  virtual ~IValueProvider() = default;
  
  /// <summary>
  /// Gets the value of this value provider.
  /// </summary>
  /// <returns>
  /// The value of this <see cref="IValueProvider"/>.
  /// </returns>
  virtual T GetValue() const = 0;
};

}
}
}
}
