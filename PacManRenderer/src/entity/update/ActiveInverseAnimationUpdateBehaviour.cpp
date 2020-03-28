#include "pch.h"
#include "entity/update/ActiveInverseAnimationUpdateBehaviour.h"


namespace pacman {
namespace renderer {
namespace entity {
namespace update {

ActiveInverseAnimationUpdateBehaviour::ActiveInverseAnimationUpdateBehaviour(
  view::IViewAPI* p_view_api, 
  const std::string& animation_label,
  std::shared_ptr<render::IValueProvider<std::string>> p_active_label_provider) : 
    _p_view_api(p_view_api),
    _animation_label(animation_label),
    _p_active_label_provider(std::move(p_active_label_provider)) { }


void ActiveInverseAnimationUpdateBehaviour::Update(float dtime) {
  bool is_active = this->_p_active_label_provider->GetValue() == this->_animation_label;
  float factor = is_active ? +1.0 : -1.0;

  this->_p_view_api->UpdateAnimation(_animation_label, dtime * factor);
}
    

}
}
}
}
