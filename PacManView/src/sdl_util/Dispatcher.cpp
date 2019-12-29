#include "stdafx.h"
#include "sdl_util/Dispatcher.h"


namespace pacman {
namespace view {
namespace sdl {

Dispatcher::Dispatcher() {}


int Dispatcher::InitSDL(Uint32 flags) {
  return SDL_Init(flags);
}


int Dispatcher::InitIMG(int flags) {
  return IMG_Init(flags);
}


SDL_Window* Dispatcher::CreateWindow(const std::string& title,
                                     int x, int y,
                                     int width, int height, 
                                     Uint32 flags) {
  return SDL_CreateWindow(title.c_str(),
                          x, y, 
                          width, height, 
                          flags);
}


void Dispatcher::CreateRenderer(SDL_Window* p_window,
                                int index,
                                Uint32 flags) {
  SDL_CreateRenderer(p_window, index, flags);
}

void Dispatcher::RenderCopyEx(SDL_Renderer* p_renderer,
                              SDL_Texture* p_texture,
                              const SDL_Rect* p_src_rect,
                              const SDL_Rect* p_dst_rect,
                              double angle,
                              const SDL_Point* p_center,
                              SDL_RendererFlip flip) {
	SDL_RenderCopyEx(p_renderer,
				           p_texture,
				           p_src_rect,
				           p_dst_rect,
                   angle, 
                   p_center, 
                   flip);
}


void Dispatcher::RenderPresent(SDL_Renderer* p_renderer) {
	SDL_RenderPresent(p_renderer);
}


void Dispatcher::RenderClear(SDL_Renderer* p_renderer) {
  SDL_RenderClear(p_renderer);
}


void Dispatcher::LoadTexture(SDL_Renderer* p_renderer,
                             const std::string& file_path) {
  IMG_LoadTexture(p_renderer, file_path.c_str());
}


void Dispatcher::DestroyWindow(SDL_Window* p_window) {
  SDL_DestroyWindow(p_window);
}


void Dispatcher::DestroyRenderer(SDL_Renderer* p_renderer) {
  SDL_DestroyRenderer(p_renderer);
}


void Dispatcher::DestroyTexture(SDL_Texture* p_texture) {
  SDL_DestroyTexture(p_texture);
}


std::string Dispatcher::GetError() {
  return SDL_GetError();
}

}
}
}