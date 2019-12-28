#include "stdafx.h"
#include "texture/TextureManager.h"

#include <SDL2/SDL_image.h>
#include "exceptions/ViewException.h"


namespace pacman {
namespace view {

TextureManager::TextureManager(const IRenderer& renderer) : renderer(renderer) { }


void TextureManager::LoadTexture(const std::string& file_path) {
	if (this->HasTexture(file_path)) return;

	this->texture_map.emplace(file_path,
							  this->renderer.LoadTexture(file_path));
}


bool TextureManager::HasTexture(const std::string& file_path) const {
	return this->texture_map.find(file_path) != this->texture_map.end();
}


const ITexture& TextureManager::GetTexture(const std::string& file_path) const {
	return *(this->texture_map.at(file_path).get());
}


}
}