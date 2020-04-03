#pragma once

#include "entity/render/IValueProvider.h"
#include "entity/render/IsMovingContainer.h"

namespace pacman {
namespace renderer {
namespace entity {
namespace render {

/// <summary>
/// <see cref="IsMovingBasedValueProvider"/> provides the value
/// by querying whether the instance is moving and maps it to the corresponding 
/// true or false value.
/// </summary>
/// <seealso cref="IValueProvider" />
template <typename T>
class IsMovingBasedValueProvider final : public IValueProvider<T> {
public:  

  /// <summary>
  /// Creates new <see cref="IsMovingBasedValueProvider" />.
  /// </summary>
  /// <param name="p_moving_container">A pointer to the observed <see cref="IsMovingContainer" />.</param>
  /// <param name="true_value">The true value.</param>
  /// <param name="false_value">The false value.</param>
  IsMovingBasedValueProvider(std::unique_ptr<IsMovingContainer> p_moving_container,
                             const T& true_value,
                             const T& false_value) :
      _p_moving_container(std::move(p_moving_container)),
      _true_value(true_value),
      _false_value(false_value) { }

  inline T GetValue() const final {
    return this->_p_moving_container->IsMoving() ? 
      this->_true_value : 
      this->_false_value;
  }

private:
  std::unique_ptr<IsMovingContainer> _p_moving_container;
  const T _true_value;
  const T _false_value;
};

}
}
}
}
