#include "stdafx.h"
#include "renderer/Renderer.h"

#include <SDL2/SDL_image.h>

#include "texture/Texture.h"
#include "exceptions/ViewException.h"

namespace pacman {
namespace view {

Renderer::Renderer(sdl::IDispatcher* p_sdl_dispatcher) : _p_sdl_dispatcher(p_sdl_dispatcher) { }


void Renderer::Init(SDL_Window* p_window) {
	auto p_renderer = 
		this->_p_sdl_dispatcher->CreateRenderer(p_window, 
			                                      -1, 
			                                      SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (p_renderer == nullptr)
		throw ViewException("SDL_CreateRenderer", SDL_GetError());

	this->_p_renderer = std::move(p_renderer);
}


void Renderer::RenderCopy(SDL_Texture* p_texture,
                          const SDL_Rect* p_texture_clip,
                          const SDL_Rect* p_destination, 
                          float angle, 
                          bool flip_horizontally, 
                          bool flip_vertically) {
  SDL_RendererFlip flip = SDL_FLIP_NONE;

  if (flip_horizontally && !flip_vertically)
    flip = SDL_FLIP_HORIZONTAL;
  else if (!flip_horizontally && flip_vertically)
    flip = SDL_FLIP_VERTICAL;
  else if (flip_horizontally && flip_vertically)
    flip = (SDL_RendererFlip) (SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);

	this->_p_sdl_dispatcher->RenderCopyEx(this->_p_renderer->GetResource(),
				                                p_texture,
				                                p_texture_clip,
				                                p_destination,
                                        angle, 
                                        NULL, 
                                        flip);
}


void Renderer::RenderPresent() {
	this->_p_sdl_dispatcher->RenderPresent(this->_p_renderer->GetResource());
}


void Renderer::RenderClear() {
	this->_p_sdl_dispatcher->RenderClear(this->_p_renderer->GetResource());
}


std::unique_ptr<ITexture> Renderer::LoadTexture(const std::string& file_path) const {
	auto p_tex = this->_p_sdl_dispatcher->LoadTexture(this->_p_renderer->GetResource(),
										                                file_path);

	if (p_tex == nullptr)
		throw ViewException("IMG_LoadTexture", "");

	return std::make_unique<Texture>(std::move(p_tex),
		                               this->_p_sdl_dispatcher);
}

}
}
