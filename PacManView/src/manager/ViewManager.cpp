#include "stdafx.h"
#include "manager/ViewManager.h"

#include "exceptions/ViewException.h"

namespace pacman {
namespace view {

ViewManager::ViewManager(std::unique_ptr<IViewCore> p_view_core,
						 std::unique_ptr<ITextureManager> p_texture_manager,
						 std::unique_ptr<ISpriteManager> p_sprite_manager) :
	p_view_core(std::move(p_view_core)),
	p_texture_manager(std::move(p_texture_manager)),
	p_sprite_manager(std::move(p_sprite_manager)) { }


void ViewManager::initialise(int screen_width, int screen_height) {
  this->getViewCore().initialise(screen_width, screen_height);
}


void ViewManager::requestSprite(const std::string& label,
								const std::string& texture_file_path,
								const ClipRect clipping_rectangle) {
	this->getSpriteManager().initSprite(label,
										texture_file_path,
										clipping_rectangle.x,
										clipping_rectangle.y,
										clipping_rectangle.w,
										clipping_rectangle.h);
}


void ViewManager::requestSprite(const std::string& label,
								const std::string& texture_file_path) {
	this->getSpriteManager().initSprite(label,
										texture_file_path);
}

void ViewManager::requestSpriteAnimation(const std::string& label,
										 float time_per_frame,
										 const std::vector<std::string>& sprite_labels) {
	this->getSpriteManager().initSpriteAnimation(label,
												 time_per_frame,
												 sprite_labels);
}


void ViewManager::update(float delta_time) {
	this->setNextUpdateTime(delta_time);
}

void ViewManager::initialiseRender() {
  this->getRenderer().RenderClear();
}

void ViewManager::renderSprite(const std::string& label,
                               float x, 
                               float y,
                               float scale, 
                               float angle,
                               bool flip_horizontally,
                               bool flip_vertically) {
	const Sprite& requested_sprite = this->getSpriteManager().getSprite(label);
	requested_sprite.Render(this->getRenderer(), x, y, scale, angle, flip_horizontally, flip_vertically);
}

void ViewManager::renderSpriteAnimation(const std::string& label,
										                    float x, 
                                        float y, 
                                        float scale,
                                        float angle,
                                        bool flip_horizontally,
                                        bool flip_vertically) {
	ISpriteAnimation* requested_anim = this->getSpriteManager().getSpriteAnimation(label);
	requested_anim->updateTime(this->getNextUpdateTime());

	const Sprite& active_frame = requested_anim->getActiveSprite();
	active_frame.Render(this->getRenderer(), x, y, scale, angle, flip_horizontally, flip_vertically);
}

void ViewManager::finaliseRender() {
  this->getRenderer().RenderPresent();
  this->setNextUpdateTime(0.F);
}

}
}