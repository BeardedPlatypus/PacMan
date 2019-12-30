#pragma once

#include <SDL2/SDL.h>

namespace pacman {
namespace view {
namespace sdl {

template <typename T>
class IResourceWrapper {
public:
  virtual ~IResourceWrapper() = default;

  virtual T* GetResource() const = 0;
};

template class IResourceWrapper<SDL_Window>;
template class IResourceWrapper<SDL_Renderer>;
template class IResourceWrapper<SDL_Texture>;

}
}
}
