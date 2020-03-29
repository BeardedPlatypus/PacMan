#include "pch.h"
#include "entity/RenderEntity.h"

namespace pacman {
namespace renderer {
namespace entity {

RenderEntity::RenderEntity(std::unique_ptr<render::EntityRenderConfig> p_render_config,
                           std::unique_ptr<std::vector<std::unique_ptr<animation::IAnimationRenderConfig>>> p_animation_configs,
                           view::IViewAPI* p_view_api) :
    _p_render_config(std::move(p_render_config)),
    _p_animation_configs(std::move(p_animation_configs)),
    _p_view_api(p_view_api) { }


void RenderEntity::Initialise() { 
  for (auto& anim_config : *(this->_p_animation_configs)) anim_config->Initialise();
}
void RenderEntity::Update(float dtime) { 
  for (auto& anim_config : *(this->_p_animation_configs)) anim_config->Update(dtime);
}

void RenderEntity::Render(float scale, float render_offset_y) const {
  this->_p_view_api->RenderSpriteAnimation(
    this->_p_render_config->GetLabelProvider()->GetValue(),
    this->_p_render_config->GetPositionProvider()->GetXPosition(scale),
    this->_p_render_config->GetPositionProvider()->GetYPosition(scale, render_offset_y),
    this->_p_render_config->GetScaleProvider()->GetValue() * scale,
    this->_p_render_config->GetRotationProvider()->GetValue(),
    this->_p_render_config->GetFlipHorizontallyProvider()->GetValue(),
    this->_p_render_config->GetFlipVerticallyProvider()->GetValue());
}

}
}
}
