#include "pch.h"
#include "entity/render/StaticAnimationRotationProvider.h"

namespace pacman {
namespace renderer {
namespace entity {
namespace render {

StaticAnimationRotationProvider::StaticAnimationRotationProvider(float rotation_value) : 
    _rotation_value(rotation_value) { }


inline float StaticAnimationRotationProvider::GetRotation() const { 
  return this->_rotation_value; 
}

}
}
}
}
