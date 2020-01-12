#include "pch.h"
#include "objects/ObjectLayer.h"

#include "objects/ObjectSpriteValues.h"

namespace pacman {
namespace renderer {

ObjectLayer::ObjectLayer(float scale, 
                         view::IViewAPI* p_view_api,
                         state::field::IFieldObjectManager* p_object_manager,
                         std::unique_ptr<RenderMapping> p_obj_renderers) : 
    scale(scale),
    p_view_api(p_view_api),
    p_object_manager(p_object_manager),
    p_render_mapping(std::move(p_obj_renderers)) { }


void ObjectLayer::Initialise() {
  this->InitialiseSprites();
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
      p_render_mapping->at(t)->RenderObject(this->p_view_api,
                                            field_obj.GetX(),
                                            field_obj.GetY(), 
                                            this->scale);
    }
  }
}


void ObjectLayer::InitialiseSprites() {
  this->p_view_api->RequestSprite(values::object_sprite_small_dot,
                                  values::dots_sprite_file,
                                  values::small_dot_offset,
                                  values::small_dot_offset,
                                  values::small_dot_tile_size,
                                  values::small_dot_tile_size);
  this->p_view_api->RequestSprite(values::object_sprite_big_dot,
                                  values::dots_sprite_file,
                                  0, 0,
                                  values::big_dot_tile_size,
                                  values::big_dot_tile_size);
}


}
}