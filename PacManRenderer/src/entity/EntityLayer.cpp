#include "pch.h"
#include "entity/EntityLayer.h"


namespace pacman {
namespace renderer {

EntityLayer::EntityLayer(std::unique_ptr<std::vector<std::unique_ptr<entity::IRenderEntity>>> p_render_entities,
                         float scale,
                         float render_offset_y) : 
    _p_render_entities(std::move(p_render_entities)),
    _scale(scale),
    _render_offset_y(render_offset_y) { }


void EntityLayer::Initialise() {
  for (const std::unique_ptr<entity::IRenderEntity>& p_render_entity : *(this->_p_render_entities))
    p_render_entity->Initialise();
}


void EntityLayer::Update(float dtime) {
  for (const std::unique_ptr<entity::IRenderEntity>& p_render_entity : *(this->_p_render_entities))
    p_render_entity->Update(dtime);
}


void EntityLayer::Render() const {
  for (const std::unique_ptr<entity::IRenderEntity>& p_render_entity : *(this->_p_render_entities))
    p_render_entity->Render(this->_scale, this->_render_offset_y);
}

}
}