#include "pch.h"
#include "objects/ObjectLayer.h"

#include "objects/ObjectSpriteValues.h"
#include <algorithm>

namespace pacman {
namespace renderer {

ObjectLayer::ObjectLayer(float scale, 
                         state::field::IFieldObjectManager* p_object_manager,
                         std::unique_ptr<RenderMapping> p_obj_renderers,
                         float render_offset_y) : 
    scale(scale),
    p_object_manager(p_object_manager),
    p_render_mapping(std::move(p_obj_renderers)),
    render_offset_y(render_offset_y) { }



void ObjectLayer::Initialise() {
  for (const auto& renderer_pair : *(this->p_render_mapping)) {
    renderer_pair.second->Initialise();
  }
}


bool ObjectLayer::HasRendererForType(state::field::FieldObjectType type) const {
  return p_render_mapping->find(type) != p_render_mapping->end();

}


void ObjectLayer::Render() const {
  const std::vector<state::field::FieldObject>& field_objs =
    this->p_object_manager->GetAllFieldObjects();

  for (const state::field::FieldObject& field_obj : field_objs) {
    state::field::FieldObjectType t = field_obj.GetType();
    if (this->HasRendererForType(t)) {
      p_render_mapping->at(t)->RenderObject(field_obj.GetX(),
                                            field_obj.GetY(), 
                                            this->scale,
                                            this->render_offset_y);
    }
  }
}

}
}
