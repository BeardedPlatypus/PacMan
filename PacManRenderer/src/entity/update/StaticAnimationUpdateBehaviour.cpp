#include "pch.h"
#include "entity/update/StaticAnimationUpdateBehaviour.h"


namespace pacman {
namespace renderer {
namespace entity {
namespace update {

StaticAnimationUpdateBehaviour::StaticAnimationUpdateBehaviour(view::IViewAPI* p_view_api, 
                                                               const std::string& animation_label) : 
    _p_view_api(p_view_api),
    _animation_label(animation_label) { }


void StaticAnimationUpdateBehaviour::Update(float dtime) {
  this->_p_view_api->UpdateAnimation(_animation_label, dtime);
}
    

}
}
}
}
