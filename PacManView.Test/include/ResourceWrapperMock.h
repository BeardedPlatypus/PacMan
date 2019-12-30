#pragma once
#include "sdl_util/IResourceWrapper.h"
#include "gmock/gmock.h"


template<typename T>
class ResourceWrapperMock: public pacman::view::sdl::IResourceWrapper<T> {
public:
  MOCK_METHOD(T*, GetResource, (), (const));
};


template class ResourceWrapperMock<SDL_Window>;
template class ResourceWrapperMock<SDL_Renderer>;
template class ResourceWrapperMock<SDL_Texture>;

