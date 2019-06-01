#pragma once

#include <SDL2\SDL.h>
#include <string>
#include <memory>
#include <map>

#include "sdl_util/SDLDestructor.h"
#include "renderer/IRenderer.h"
#include "texture/ITexture.h"

namespace pacman {
namespace view {

class TextureManager {
public:
	TextureManager(const IRenderer& p_renderer);

	void loadTexture(const std::string& file_path);
	
	bool hasTexture(const std::string& file_path) const;

	const ITexture& getTexture(const std::string& file_path) const;

private:
	std::map<std::string, std::unique_ptr<ITexture>> texture_map;

	const IRenderer& renderer;
};

} // view
} // pacman
