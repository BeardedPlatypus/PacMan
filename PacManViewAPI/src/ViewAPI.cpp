#include "pch.h"
#include "ViewAPI.h"


namespace pacman {
namespace view {

ViewAPI::ViewAPI(std::unique_ptr<IViewCore> p_view_core,
						     std::unique_ptr<ITextureManager> p_texture_manager,
						     std::unique_ptr<ISpriteManager> p_sprite_manager) :
    p_view_core(std::move(p_view_core)),
	  p_texture_manager(std::move(p_texture_manager)),
	  p_sprite_manager(std::move(p_sprite_manager)) { }


void ViewAPI::Initialise(int screen_width, int screen_height) {
  this->GetViewCore().Initialise(screen_width, screen_height);
}


void ViewAPI::RequestSprite(const std::string& label,
								            const std::string& texture_file_path,
								            int x, int y, int w, int h) {
	this->GetSpriteManager().InitSprite(label,
										                  texture_file_path,
										                  x, y, w, h);
}


void ViewAPI::RequestSprite(const std::string& label,
								            const std::string& texture_file_path) {
	this->GetSpriteManager().InitSprite(label, texture_file_path);
}

void ViewAPI::RequestSpriteAnimation(const std::string& label,
										                 float time_per_frame,
										                 const std::vector<std::string>& sprite_labels) {
	this->GetSpriteManager().InitSpriteAnimation(label,
												                       time_per_frame,
												                       sprite_labels);
}


void ViewAPI::InitialiseRender() {
  this->GetRenderer().RenderClear();
}


void ViewAPI::RenderSprite(const std::string& label,
                           float x, 
                           float y,
                           float scale, 
                           float angle,
                           bool flip_horizontally,
                           bool flip_vertically) {
	const Sprite& requested_sprite = this->GetSpriteManager().GetSprite(label);
	requested_sprite.Render(this->GetRenderer(), 
		                      x, y, scale, angle, flip_horizontally, flip_vertically);
}


void ViewAPI::RenderSpriteAnimation(const std::string& label,
										                float x, 
                                    float y, 
                                    float scale,
                                    float angle,
                                    bool flip_horizontally,
                                    bool flip_vertically) {
	ISpriteAnimation* requested_anim = this->GetSpriteManager().GetSpriteAnimation(label);
	const Sprite& active_frame = requested_anim->GetActiveSprite();
	active_frame.Render(this->GetRenderer(), 
		                  x, y, scale, angle, flip_horizontally, flip_vertically);
}


void ViewAPI::FinaliseRender() {
  this->GetRenderer().RenderPresent();
}


void ViewAPI::UpdateAnimation(const std::string& label,
	                            float delta_time) {
	this->GetSpriteManager().GetSpriteAnimation(label)->UpdateTime(delta_time);
}


void ViewAPI::SetAnimationToTime(const std::string& label,
	                               float new_time) {
	this->GetSpriteManager().GetSpriteAnimation(label)->SetExactTime(new_time);
}

	
void ViewAPI::ResetAnimationTime(const std::string& label) {
	this->GetSpriteManager().GetSpriteAnimation(label)->ResetTime();
}


}
}
