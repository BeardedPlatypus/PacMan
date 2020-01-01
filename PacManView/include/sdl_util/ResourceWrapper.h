#pragma once
#include "sdl_util/IResourceWrapper.h"
#include "sdl_util/SDLDestructor.h"

#include <memory>

namespace pacman {
namespace view {
namespace sdl {

template <typename T>
class ResourceWrapper final : public IResourceWrapper<T> {
public:
  explicit ResourceWrapper(T* p_resource);
  T* GetResource() const final;
private:
  std::unique_ptr<T, SDL_Destructor<T>> _p_resource;
};

template class ResourceWrapper<SDL_Window>;
template class ResourceWrapper<SDL_Renderer>;
template class ResourceWrapper<SDL_Texture>;

}
}
}
