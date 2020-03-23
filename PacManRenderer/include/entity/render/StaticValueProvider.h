#pragma once

#include "entity/render/IValueProvider.h"

namespace pacman {
namespace renderer {
namespace entity {
namespace render {

/// <summary>
/// <see cref="StaticValueProvider"/> provides a value provider that will
/// always return a static value.
/// </summary>
template <typename T>
class StaticValueProvider final : public IValueProvider<T> {
public:  
  /// <summary>
  /// Crates a new <see cref="StaticValueProvider"/>.
  /// </summary>
  /// <param name="value">The value that will be returned.</param>
  explicit StaticValueProvider(T value);

  T GetValue() const final;
private:
  const T _value;
};

}
}
}
}
