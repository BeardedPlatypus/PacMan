#pragma once

#include <map>
#include <string>

#include "texture/ITextureManager.h"
#include "sprite/Sprite.h"
#include "sprite/SpriteAnimation.h"

namespace pacman {
namespace view {

// TODO add dll export for test
class SpriteManager {
public:
	SpriteManager(ITextureManager& texture_manager);

	void initSprite(const std::string& label,
					const std::string& sprite_sheet_path, 
					int x, int y, int w, int h);

	void initSprite(const std::string& label,
					const std::string& sprite_sheet_path);

	const Sprite& getSprite(const std::string& label) const;

	SpriteAnimation* constructSpriteAnimation(float time_per_frame,
				 							  const std::vector<std::string>& sprites) const;

private:
	std::map<std::string, Sprite> sprite_map;
	std::map<std::string, SpriteAnimation> sprite_animation_map;

	const ITexture& getTexture(const std::string& texture_path);

	ITextureManager& texture_manager;
};

}
}
