#pragma once

#include "sdl_util/IDispatcher.h"

namespace pacman {
namespace view {
namespace sdl {

class Dispatcher final : public IDispatcher {
public:
  Dispatcher();

  int InitSDL(unsigned int flags) final;
  int InitIMG(int flags) final;

  std::unique_ptr<sdl::IResourceWrapper<SDL_Window>> CreateSDLWindow(
    const std::string& title,
    int x, int y,
    int width, int height, 
    unsigned int flags) final;

  void QuitIMG() final;
  void QuitSDL() final;

  std::unique_ptr<sdl::IResourceWrapper<SDL_Renderer>> CreateRenderer(
    SDL_Window* p_window,
    int index,
    unsigned int flags) final;

  void RenderCopyEx(SDL_Renderer* p_renderer,
                    SDL_Texture* p_texture,
                    const SDL_Rect* p_src_rect,
                    const SDL_Rect* p_dst_rect,
                    double angle,
                    const SDL_Point* p_center,
                    SDL_RendererFlip flip) final;

  void RenderPresent(SDL_Renderer* p_renderer) final;
  void RenderClear(SDL_Renderer* p_renderer) final;

  std::unique_ptr<sdl::IResourceWrapper<SDL_Texture>> LoadTexture(
    SDL_Renderer* p_renderer,
    const std::string& file_path) final;

  std::string GetError() final;

  void QueryTexture(SDL_Texture* p_texture,
                    unsigned int* format,
                    int* access,
                    int* w,
                    int* h) final;
};


}
}
}
