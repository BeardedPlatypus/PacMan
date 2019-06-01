#include "stdafx.h"
#include "renderer/Renderer.h"

#include <SDL2/SDL_image.h>

#include "texture/Texture.h"
#include "exceptions/ViewException.h"

namespace pacman {
namespace view {

Renderer::Renderer() { }
Renderer::~Renderer() { }


void Renderer::Init(SDL_Window* p_window) {
	SDL_Renderer* p_renderer = 
		SDL_CreateRenderer(p_window, -1, SDL_RENDERER_ACCELERATED | 
						                 SDL_RENDERER_PRESENTVSYNC);

	if (p_renderer == nullptr)
		throw ViewException("SDL_CreateRenderer", SDL_GetError());

	this->p_renderer = 
		std::unique_ptr<SDL_Renderer, SDL_Destructor<SDL_Renderer>>(p_renderer);
}


void Renderer::RenderCopy(SDL_Texture* p_texture,
						  const SDL_Rect* p_texture_clip,
						  const SDL_Rect* p_destination) {
	SDL_RenderCopy(this->p_renderer.get(),
				   p_texture,
				   p_texture_clip,
				   p_destination);
}


void Renderer::RenderPresent() {
	SDL_RenderPresent(this->p_renderer.get());
}


void Renderer::RenderClear() {
	SDL_RenderClear(this->p_renderer.get());
}


std::unique_ptr<ITexture> Renderer::LoadTexture(const std::string& file_path) const {
	SDL_Texture* p_tex = IMG_LoadTexture(this->p_renderer.get(),
										 file_path.c_str());

	if (p_tex == nullptr)
		throw ViewException("IMG_LoadTexture", "");

	return std::make_unique<Texture>(p_tex);
}

}
}