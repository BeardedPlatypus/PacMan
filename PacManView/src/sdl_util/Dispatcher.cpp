#include "stdafx.h"
#include "sdl_util/Dispatcher.h"
#include "sdl_util/ResourceWrapper.h"


namespace pacman {
namespace view {
namespace sdl {

Dispatcher::Dispatcher() {}


int Dispatcher::InitSDL(unsigned int flags) {
  return SDL_Init(flags);
}


int Dispatcher::InitIMG(int flags) {
  return IMG_Init(flags);
}


std::unique_ptr<sdl::IResourceWrapper<SDL_Window>> Dispatcher::CreateSDLWindow(
    const std::string& title,
    int x, int y,
    int width, int height, 
    unsigned int flags) {
  auto p_window = SDL_CreateWindow(title.c_str(),
                                   x, y, 
                                   width, height, 
                                   flags);
  return std::make_unique<sdl::ResourceWrapper<SDL_Window>>(p_window);
}


void Dispatcher::QuitIMG() {
  IMG_Quit();
}


void Dispatcher::QuitSDL() {
  SDL_Quit();
}


std::unique_ptr<sdl::IResourceWrapper<SDL_Renderer>> Dispatcher::CreateRenderer(
    SDL_Window* p_window,
    int index,
    unsigned int flags) {
  auto p_renderer = SDL_CreateRenderer(p_window, index, flags);
  return std::make_unique<sdl::ResourceWrapper<SDL_Renderer>>(p_renderer);
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


std::unique_ptr<sdl::IResourceWrapper<SDL_Texture>> Dispatcher::LoadTexture(SDL_Renderer* p_renderer,
                             const std::string& file_path) {
  auto p_tex = IMG_LoadTexture(p_renderer, file_path.c_str());
  return std::make_unique<sdl::ResourceWrapper<SDL_Texture>>(p_tex);
}


std::string Dispatcher::GetError() {
  return SDL_GetError();
}


void Dispatcher::QueryTexture(SDL_Texture* p_texture,
                              unsigned int* format,
                              int* access,
                              int* w,
                              int* h) {
  SDL_QueryTexture(p_texture, format, access, w, h);
}

}
}
}