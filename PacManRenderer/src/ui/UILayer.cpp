#include "pch.h"
#include "ui/UILayer.h"


namespace pacman {
namespace renderer {

UILayer::UILayer(float scale, 
                 std::unique_ptr<ui::IStringRenderer> p_string_renderer,
                 float render_offset_y) :
    scale(scale),
    p_string_renderer(std::move(p_string_renderer)),
    render_offset_y(render_offset_y) { }


void UILayer::Initialise() {
  this->p_string_renderer->Initialise();
}


void UILayer::Render() const {
  this->p_string_renderer->RenderString("high score", 736.F / 2.F, 1.F * this->scale, this->scale, ui::Justification::Centre);
}


}
}
