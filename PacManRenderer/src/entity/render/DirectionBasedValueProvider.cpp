#include "pch.h"
#include "entity/render/DirectionBasedValueProvider.h"

namespace pacman {
namespace renderer {
namespace entity {
namespace render {

template <typename T>
DirectionBasedValueProvider<T>::DirectionBasedValueProvider(std::unique_ptr<GetDirectionContainer> p_direction_container,
                                                            const T& default_value,
                                                            std::unique_ptr<std::unordered_map<state::Direction, T, EnumClassHash>> p_mapping) : 
    _p_direction_container(std::move(p_direction_container)),
    _default_value(default_value), 
    _p_mapping(std::move(p_mapping)) { }


template <typename T>
T DirectionBasedValueProvider<T>::GetValue() const {
  state::Direction dir = this->_p_direction_container->GetDirection();
  auto result = this->_p_mapping->find(dir);

  return result != this->_p_mapping->end() ? result->second : this->_default_value;
}


template class DirectionBasedValueProvider<bool>;
template class DirectionBasedValueProvider<float>;
template class DirectionBasedValueProvider<std::string>;

}
}
}
}
