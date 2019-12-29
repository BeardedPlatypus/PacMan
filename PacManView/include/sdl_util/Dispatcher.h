#pragma once

#include "sdl_util/IDispatcher.h"

namespace pacman {
namespace view {
namespace sdl {

class Dispatcher final : public IDispatcher {
public:
  Dispatcher();

  int InitSDL(Uint32 flags) final;
  int InitIMG(int flags) final;
  SDL_Window* CreateWindow(const std::string& title,
                           int x, int y,
                           int width, int height, 
                           Uint32 flags) final;

  void CreateRenderer(SDL_Window* p_window,
                      int index,
                      Uint32 flags) final;

  void RenderCopyEx(SDL_Renderer* p_renderer,
                    SDL_Texture* p_texture,
                    const SDL_Rect* p_src_rect,
                    const SDL_Rect* p_dst_rect,
                    double angle,
                    const SDL_Point* p_center,
                    SDL_RendererFlip flip) final;

  void RenderPresent(SDL_Renderer* p_renderer) final;
  void RenderClear(SDL_Renderer* p_renderer) final;

  void LoadTexture(SDL_Renderer* p_renderer,
                   const std::string& file_path) final;

  void DestroyWindow(SDL_Window* p_window) final;
  void DestroyRenderer(SDL_Renderer* p_renderer) final;
  void DestroyTexture(SDL_Texture* p_texture) final;

  std::string GetError() final;
};


}
}
}
