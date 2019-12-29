#include "stdafx.h"
#include "sprite/SpriteManager.h"

#include <stdexcept>
#include "exceptions/ViewException.h"


namespace pacman {
namespace view {

SpriteManager::SpriteManager(ITextureManager& texture_manager) : 
    texture_manager(texture_manager) { }


void SpriteManager::InitSprite(const std::string& label,
							                 const std::string& sprite_sheet_path,
							                 int x, int y, int w, int h) {
	if (this->HasSprite(label)) {
		throw ViewException("InitSprite", "");
	}

	if (w <= 0 || h <= 0) {
		throw ViewException("InitSprite", "");
	}

	const ITexture& tex = this->GetTexture(sprite_sheet_path);
	this->sprite_map.try_emplace(label, tex, x, y, w, h);
}


void SpriteManager::InitSprite(const std::string& label,
							   const std::string& sprite_sheet_path) {
	if (this->HasSprite(label)) {
		throw ViewException("InitSprite", "");
	}

	const ITexture& tex = this->GetTexture(sprite_sheet_path);
	this->sprite_map.try_emplace(label, tex);
}


bool SpriteManager::HasSprite(const std::string& label) const {
	return this->sprite_map.find(label) != this->sprite_map.end();
}


const Sprite& SpriteManager::GetSprite(const std::string& label) const {
	try {
		return this->sprite_map.at(label);
	}
	catch (std::out_of_range) {
		throw ViewException("GetSprite", "");
	}
}


void SpriteManager::InitSpriteAnimation(const std::string& label, 
										                    float time_per_frame,
			 						                      const std::vector<std::string>& sprite_labels) {
	if (time_per_frame <= 0.F) {
		throw ViewException("InitSpriteAnimation", "");
	}
	if (this->HasSpriteAnimation(label)) {
		throw ViewException("InitSpriteAnimation", "");
	}

	auto sprites = std::vector<std::reference_wrapper<const Sprite>>();

	for (const std::string& sprite_label : sprite_labels) {
		sprites.push_back(this->GetSprite(sprite_label));
	}

	this->sprite_animation_map.try_emplace(label, ISpriteAnimation::Construct(time_per_frame, sprites));
}


bool SpriteManager::HasSpriteAnimation(const std::string& label) const {
	return this->sprite_animation_map.find(label) != this->sprite_animation_map.end();
}


ISpriteAnimation* SpriteManager::GetSpriteAnimation(const std::string& label) {
	try {
		return this->sprite_animation_map.at(label).get();
	}
	catch (std::out_of_range) {
		throw ViewException("GetSpriteAnimation", "");
	}
}


const ITexture& SpriteManager::GetTexture(const std::string& sprite_sheet_path) {
	this->texture_manager.LoadTexture(sprite_sheet_path);
	return this->texture_manager.GetTexture(sprite_sheet_path);
}

}
}