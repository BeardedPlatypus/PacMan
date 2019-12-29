#pragma once

#include "sdl_util/IDispatcher.h"
#include "gmock/gmock.h"


class DispatcherMock : public pacman::view::sdl::IDispatcher {
public:
  MOCK_METHOD(int, InitSDL, (unsigned int));
  MOCK_METHOD(int, InitIMG, (int));

  MOCK_METHOD(SDL_Window*,
              CreateSDLWindow,
              (const std::string&, int, int, int, int, unsigned int));

  MOCK_METHOD(void, QuitIMG, ());
  MOCK_METHOD(void, QuitSDL, ());

  MOCK_METHOD(void, CreateRenderer, (SDL_Window*, int, unsigned int));

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
  
  MOCK_METHOD(void, LoadTexture, (SDL_Renderer*, const std::string&));
  
  MOCK_METHOD(void, DestroyWindow, (SDL_Window*));
  MOCK_METHOD(void, DestroyRenderer, (SDL_Renderer*));
  MOCK_METHOD(void, DestroyTexture, (SDL_Texture*));

  MOCK_METHOD(std::string, GetError, ());
};
