#pragma once

#include <unordered_map>

#include "entity/render/IValueProvider.h"
#include "entity/render/GetDirectionContainer.h"

#include "util/EnumClassHash.h"

namespace pacman {
namespace renderer {
namespace entity {
namespace render {

/// <summary>
/// <see cref="DirectionBasedValueProvider"/> provides the current value 
/// by querying the current direction and using the provided mapping to 
/// determine the corresponding value. If no label can be found in the provided 
/// mapping the default label will be obtained.
/// </summary>
/// <seealso cref="IValueProvider" />
template <typename T>
class DirectionBasedValueProvider final : public IValueProvider<T> {
public:  
  /// <summary>
  /// Creates new <see cref="DirectionBasedValueProvider"/>.
  /// </summary>
  /// <param name="_p_direction_container">A pointer to the observed <see cref="GetDirectionContainer"/>.</param>
  /// <param name="default_value">The default value.</param>
  /// <param name="p_mapping">The mapping of direction to values.</param>
  DirectionBasedValueProvider(std::shared_ptr<GetDirectionContainer> p_direction_container,
                              const T& default_value,
                              std::unique_ptr<std::unordered_map<state::Direction, T, EnumClassHash>> p_mapping);

  T GetValue() const final;

private:
  std::shared_ptr<GetDirectionContainer> _p_direction_container;
  T _default_value;
  std::unique_ptr<std::unordered_map<state::Direction, T, EnumClassHash>> _p_mapping;
};

}
}
}
}
