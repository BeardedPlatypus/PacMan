#pragma once

#include <unordered_map>

#include "entity/render/IValueProvider.h"
#include "entity/render/GetStateContainer.h"

#include "util/EnumClassHash.h"

namespace pacman {
namespace renderer {
namespace entity {
namespace render {

/// <summary>
/// <see cref="StateBasedValueProvider"/> provides a <see cref="TValue"/>
/// given the state provided by some <see cref="GetStateContainer{TState}"/>.
/// </summary>
template <typename TState, typename TValue>
class StateBasedValueProvider final : public IValueProvider<TValue> {
public:    
  /// <summary>
  /// Creates a new <see cref="StateBasedValueProvider"/>.
  /// </summary>
  /// <param name="_p_state_container">A pointer to the observed <see cref="GetStateContainer"/>.</param>
  /// <param name="default_value">The default value.</param>
  /// <param name="p_mapping">The mapping of the state to values.</param>
  StateBasedValueProvider(std::shared_ptr<GetStateContainer<TState>> p_state_container,
                          const TValue& default_value,
                          std::unique_ptr<std::unordered_map<TState, TValue, EnumClassHash>> p_mapping) :
      _p_state_container(std::move(p_state_container)),
      _default_value(default_value),
      _p_mapping(std::move(p_mapping)) { }

  TValue GetValue() const final {
    TState state = this->_p_state_container->GetState();
    auto result = this->_p_mapping->find(state);

    return result != this->_p_mapping->end() ? result->second : this->_default_value;
  }

private:
  std::shared_ptr<GetStateContainer<TState>> _p_state_container;
  TValue _default_value;
  std::unique_ptr<std::unordered_map<TState, TValue, EnumClassHash>> _p_mapping;
};

}
}
}
}
