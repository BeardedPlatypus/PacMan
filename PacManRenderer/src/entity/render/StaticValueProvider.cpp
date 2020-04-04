#include "pch.h"
#include "entity/render/StaticValueProvider.h"

#include <string>
#include <entity/PacManStateType.h>

namespace pacman {
namespace renderer {
namespace entity {
namespace render {

template <typename T>
StaticValueProvider<T>::StaticValueProvider(T value) : 
    _value(value) { }


template <typename T>
inline T StaticValueProvider<T>::GetValue() const { 
  return this->_value; 
}


template class StaticValueProvider<bool>;
template class StaticValueProvider<float>;
template class StaticValueProvider<std::string>;
template class StaticValueProvider<state::PacManStateType>;

}
}
}
}
