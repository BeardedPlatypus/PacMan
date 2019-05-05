#pragma once

#include <SDL.h>
#include <string>
#include <memory>
#include <map>

#include "sdl_util/SDLDestructor.h"

namespace pacman {
namespace view {

class TextureManager {
public:
	TextureManager(SDL_Renderer& p_renderer);

	void loadTexture(const std::string& file_path);
	
	bool hasTexture(const std::string& file_path) const;

	SDL_Texture& getTexture(const std::string& file_path) const;

private:
	std::map<std::string, 
		     std::unique_ptr<SDL_Texture, SDL_Destructor<SDL_Texture>>> texture_map;

	SDL_Renderer& renderer;
};

} // view
} // pacman
