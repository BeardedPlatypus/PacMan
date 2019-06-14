#include "stdafx.h"
#include "texture/TextureManager.h"

#include <SDL2/SDL_image.h>
#include "exceptions/ViewException.h"


namespace pacman {
namespace view {

TextureManager::TextureManager(const IRenderer& renderer) :
	texture_map(std::map<std::string, std::unique_ptr<ITexture>>()),
	renderer(renderer)
{ }


void TextureManager::loadTexture(const std::string& file_path) {
	if (this->hasTexture(file_path)) return;

	this->texture_map.emplace(file_path,
							  this->renderer.LoadTexture(file_path));
}


bool TextureManager::hasTexture(const std::string& file_path) const {
	return this->texture_map.find(file_path) != this->texture_map.end();
}


const ITexture& TextureManager::getTexture(const std::string& file_path) const {
	return *(this->texture_map.at(file_path).get());
}


}
}