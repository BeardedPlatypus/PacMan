#include "stdafx.h"
#include "sdl_util/ResourceWrapper.h"


namespace pacman {
namespace view {
namespace sdl {

template<typename T>
ResourceWrapper<T>::ResourceWrapper(T* p_resource) : 
    _p_resource(std::unique_ptr<T, SDL_Destructor<T>>(p_resource)) { 
}


template<typename T>
T* ResourceWrapper<T>::GetResource() const {
  return this->_p_resource.get();
}

}
}
}