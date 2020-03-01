#include "pch.h"
#include "ui/UILayer.h"
#include "ui/font/StaticStringRenderData.h"


namespace pacman {
namespace renderer {

UILayer::UILayer(float scale, 
                 std::unique_ptr<ui::IStringRenderer> p_string_renderer,
                 std::unique_ptr<std::vector<std::unique_ptr<ui::IStringRenderData>>> p_render_data,
                 float render_offset_y) :
    scale(scale),
    p_string_renderer(std::move(p_string_renderer)),
    p_render_data(std::move(p_render_data)),
    render_offset_y(render_offset_y) { }


void UILayer::Initialise() {
  this->p_string_renderer->Initialise();
}


void UILayer::Render() const {
  for (size_t i = 0; i < this->p_render_data->size(); i++) {
    this->p_string_renderer->RenderString(*(p_render_data->at(i)), this->scale);
  }
}


}
}
