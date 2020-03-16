#pragma once

#include "sdl_util/IDispatcher.h"
#include "gmock/gmock.h"


class DispatcherMock : public pacman::view::sdl::IDispatcher {
public:
  MOCK_METHOD(int, InitSDL, (unsigned int));
  MOCK_METHOD(int, InitIMG, (int));

  using sdl_window_ptr = std::unique_ptr<pacman::view::sdl::IResourceWrapper<SDL_Window>>;
  MOCK_METHOD(sdl_window_ptr,
              CreateSDLWindow,
              (const std::string&, int, int, int, int, unsigned int));

  MOCK_METHOD(void, QuitIMG, ());
  MOCK_METHOD(void, QuitSDL, ());

  using sdl_renderer_ptr = std::unique_ptr<pacman::view::sdl::IResourceWrapper<SDL_Renderer>>;
  MOCK_METHOD(sdl_renderer_ptr, CreateRenderer, (SDL_Window*, int, unsigned int));

  MOCK_METHOD(void, 
              RenderCopyEx, 
              (SDL_Renderer*,
               SDL_Texture*,
               const SDL_Rect*,
               const SDL_Rect*,
               double,
               const SDL_Point*,
               SDL_RendererFlip));

  MOCK_METHOD(void, RenderPresent, (SDL_Renderer*));
  MOCK_METHOD(void, RenderClear, (SDL_Renderer*));
  
  MOCK_METHOD(std::unique_ptr<pacman::view::sdl::IResourceWrapper<SDL_Texture>>, LoadTexture, (SDL_Renderer*, const std::string&));
  
  MOCK_METHOD(void, DestroyWindow, (SDL_Window*));
  MOCK_METHOD(void, DestroyRenderer, (SDL_Renderer*));
  MOCK_METHOD(void, DestroyTexture, (SDL_Texture*));

  MOCK_METHOD(std::string, GetError, ());

  MOCK_METHOD(void, QueryTexture, (SDL_Texture*, unsigned int*, int*, int*, int*));
};
