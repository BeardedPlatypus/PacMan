#include "pch.h"
#include "entity/render/DirectionBasedAnimationLabelProvider.h"


namespace pacman {
namespace renderer {
namespace entity {
namespace render {

DirectionBasedAnimationLabelProvider::DirectionBasedAnimationLabelProvider(std::unique_ptr<GetDirectionContainer> p_direction_container,
                                                                           const std::string& default_label,
                                                                           std::unique_ptr<std::unordered_map<state::Direction, std::string, EnumClassHash>> p_mapping) : 
    _p_direction_container(std::move(p_direction_container)),
    _default_label(default_label), 
    _p_mapping(std::move(p_mapping)) { }


const std::string& DirectionBasedAnimationLabelProvider::GetActiveAnimationLabel() const {
  state::Direction dir = this->_p_direction_container->GetDirection();
  auto result = this->_p_mapping->find(dir);

  return result != this->_p_mapping->end() ? result->second : this->_default_label;
}

}
}
}
}
