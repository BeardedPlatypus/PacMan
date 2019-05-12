#include "stdafx.h"
#include "TextureManager.h"

#include <SDL2/SDL_image.h>
#include "exceptions/ViewException.h"


namespace pacman {
namespace view {

TextureManager::TextureManager(SDL_Renderer& renderer) :
	texture_map(std::map<std::string, 
				std::unique_ptr<SDL_Texture, SDL_Destructor<SDL_Texture>>>()),
	renderer(renderer)
{ }

void TextureManager::loadTexture(const std::string& file_path) {
	SDL_Texture* p_tex = IMG_LoadTexture(&renderer,
										 file_path.c_str());

	if (p_tex == nullptr)
		throw ViewException("IMG_LoadTexture",
							"");

	if (p_tex == nullptr)
		throw ViewException("IMG_LoadTexture",
							"");

	this->texture_map.emplace(file_path,
					   std::unique_ptr<SDL_Texture, 
					                   SDL_Destructor<SDL_Texture>>(p_tex));
}


bool TextureManager::hasTexture(const std::string& file_path) const {
	return this->texture_map.find(file_path) != this->texture_map.end();
}


SDL_Texture& TextureManager::getTexture(const std::string& file_path) const {
	return *(this->texture_map.at(file_path).get());
}


}
}