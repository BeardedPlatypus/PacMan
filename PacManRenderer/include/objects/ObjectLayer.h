#pragma once

#include <IViewAPI.h>
#include <field/object/IFieldObjectManager.h>

#include <memory>
#include <unordered_map>

#include "IRenderLayer.h"
#include "objects/ObjectRenderers/IObjectRenderer.h"


namespace pacman {
namespace renderer {

using RenderMapping = std::unordered_map<state::field::FieldObjectType, std::unique_ptr<objects::IObjectRenderer>>;


class ObjectLayer final : public IRenderLayer {
public:
  ObjectLayer(float scale,
              view::IViewAPI* p_view_api,
              state::field::IFieldObjectManager* p_object_manager,
              std::unique_ptr<RenderMapping> p_obj_renderers);

  void Initialise() final;

  inline void Update(float dtime) {
    // ObjectLayer is static.
  }

  void Render() const final;

private:
  const float scale;

  void InitialiseSprites();
  bool HasRendererForType(state::field::FieldObjectType type) const;

  view::IViewAPI* p_view_api;
  state::field::IFieldObjectManager* p_object_manager;

  std::unique_ptr<RenderMapping> p_render_mapping;
};

}
}
