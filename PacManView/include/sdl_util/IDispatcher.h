#pragma once

#include <memory>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "sdl_util/IResourceWrapper.h"

namespace pacman {
namespace view {
namespace sdl {

class IDispatcher {
public:
  static std::unique_ptr<IDispatcher> Construct();

  virtual ~IDispatcher() = default;

  virtual int InitSDL(unsigned int flags) = 0;
  virtual int InitIMG(int flags) = 0;

  virtual std::unique_ptr<sdl::IResourceWrapper<SDL_Window>> CreateSDLWindow(
    const std::string& title,
    int x, 
    int y,
    int width, 
    int height, 
    unsigned int flags) = 0;

  virtual void QuitIMG() = 0;
  virtual void QuitSDL() = 0;

  virtual std::unique_ptr<sdl::IResourceWrapper<SDL_Renderer>> CreateRenderer(
    SDL_Window* p_window,
    int index,
    unsigned int flags) = 0;

  virtual void RenderCopyEx(SDL_Renderer* p_renderer,
                            SDL_Texture* p_texture,
                            const SDL_Rect* p_src_rect,
                            const SDL_Rect* p_dst_rect,
                            double angle,
                            const SDL_Point* p_center,
                            SDL_RendererFlip flip) = 0;

  virtual void RenderPresent(SDL_Renderer* p_renderer) = 0;
  virtual void RenderClear(SDL_Renderer* p_renderer) = 0;

  virtual std::unique_ptr<sdl::IResourceWrapper<SDL_Texture>> LoadTexture(
    SDL_Renderer* p_renderer,
    const std::string& file_path) = 0;

  virtual std::string GetError() = 0;

  virtual void QueryTexture(SDL_Texture* p_texture,
                            unsigned int* format,
                            int* access,
                            int* w,
                            int* h) = 0;
};

}
}
}
