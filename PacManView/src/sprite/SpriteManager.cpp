#include "stdafx.h"
#include "sprite/SpriteManager.h"

#include <stdexcept>
#include "exceptions/ViewException.h"

namespace pacman {
namespace view {

SpriteManager::SpriteManager(ITextureManager& texture_manager) : 
	texture_manager(texture_manager) { }


void SpriteManager::initSprite(const std::string& label,
							   const std::string& sprite_sheet_path,
							   int x, int y, int w, int h) {
	if (this->hasSprite(label))
		throw ViewException("initSprite", "");
	if (w <= 0 || h <= 0)
		throw ViewException("initSprite", "");

	const ITexture& tex = this->getTexture(sprite_sheet_path);

	this->sprite_map.try_emplace(label, 
								 tex, 
								 x, y, w, h);
}


void SpriteManager::initSprite(const std::string& label,
							   const std::string& sprite_sheet_path) {
	if (this->hasSprite(label))
		throw ViewException("initSprite", "");

	const ITexture& tex = this->getTexture(sprite_sheet_path);

	this->sprite_map.try_emplace(label, tex);
}


bool SpriteManager::hasSprite(const std::string& label) const {
	return this->sprite_map.find(label) != this->sprite_map.end();
}


const Sprite& SpriteManager::getSprite(const std::string& label) const {
	try {
		return this->sprite_map.at(label);
	}
	catch (std::out_of_range) {
		throw ViewException("getSprite", "");
	}
}


void SpriteManager::initSpriteAnimation(const std::string& label, 
										                    float time_per_frame,
			 						                      const std::vector<std::string>& sprite_labels) {
	if (time_per_frame <= 0.F)
		throw ViewException("initSpriteAnimation", "");
	if (this->hasSpriteAnimation(label))
		throw ViewException("initSpriteAnimation", "");

	auto sprites = std::vector<std::reference_wrapper<const Sprite>>();

	for (const std::string& sprite_label : sprite_labels) {
		sprites.push_back(this->getSprite(sprite_label));
	}

	this->sprite_animation_map.try_emplace(label, ISpriteAnimation::Construct(time_per_frame, sprites));
}


bool SpriteManager::hasSpriteAnimation(const std::string& label) const {
	return this->sprite_animation_map.find(label) != this->sprite_animation_map.end();
}


ISpriteAnimation* SpriteManager::getSpriteAnimation(const std::string& label) {
	try {
		return this->sprite_animation_map.at(label).get();
	}
	catch (std::out_of_range) {
		throw ViewException("getSpriteAnimation", "");
	}
}


const ITexture& SpriteManager::getTexture(const std::string& sprite_sheet_path) {
	this->texture_manager.loadTexture(sprite_sheet_path);
	return this->texture_manager.getTexture(sprite_sheet_path);
}

}
}