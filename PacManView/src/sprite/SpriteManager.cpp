#include "stdafx.h"
#include "sprite/SpriteManager.h"


namespace pacman {
namespace view {

SpriteManager::SpriteManager(ITextureManager& texture_manager) : 
	texture_manager(texture_manager) { }


void SpriteManager::initSprite(const std::string& label,
							   const std::string& sprite_sheet_path,
							   int x, int y, int w, int h) {
	const ITexture& tex = this->getTexture(sprite_sheet_path);

	this->sprite_map.try_emplace(label, 
								 tex, 
								 x, y, w, h);
}


void SpriteManager::initSprite(const std::string& label,
							   const std::string& sprite_sheet_path) {

	const ITexture& tex = this->getTexture(sprite_sheet_path);

	this->sprite_map.try_emplace(label, tex);
}


const Sprite& SpriteManager::getSprite(const std::string& label) const {
	return this->sprite_map.at(label);
}


void SpriteManager::initSpriteAnimation(const std::string& label, 
										float time_per_frame,
			 						    const std::vector<std::string>& sprite_labels) {
	auto sprites = std::vector<std::reference_wrapper<const Sprite>>();

	for (const std::string& sprite_label : sprite_labels) {
		sprites.push_back(this->getSprite(sprite_label));
	}

	this->sprite_animation_map.try_emplace(label, time_per_frame, sprites);
}


SpriteAnimation& SpriteManager::getSpriteAnimation(const std::string& label) {
	return this->sprite_animation_map.at(label);
}


const ITexture& SpriteManager::getTexture(const std::string& sprite_sheet_path) {
	if (!this->texture_manager.hasTexture(sprite_sheet_path)) {
		this->texture_manager.loadTexture(sprite_sheet_path);
	}

	return this->texture_manager.getTexture(sprite_sheet_path);
}

}
}