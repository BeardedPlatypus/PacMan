#include "pch.h"
#include "ui/UILayerFactory.h"

#include "ui/font/GlyphRenderer.h"
#include "ui/font/StringRenderer.h"
#include "ui/font/StaticStringRenderData.h"


namespace pacman {
namespace renderer {

std::unique_ptr<UILayer> ConstructUILayer(float scale, 
                                          view::IViewAPI* p_view_api,
                                          float render_offset_y) {
  auto p_glyph_renderer = std::make_unique<ui::GlyphRenderer>(p_view_api);
  auto p_string_renderer = std::make_unique<ui::StringRenderer>(std::move(p_glyph_renderer));

  auto p_render_data =
    std::make_unique<std::vector<std::unique_ptr<ui::IStringRenderData>>>();

  p_render_data->push_back(std::make_unique<ui::StaticStringRenderData>("high score", 
                                                                        736.F * 0.5F, 
                                                                        0.75F * scale, 
                                                                        0.75F, 
                                                                        ui::Justification::Centre));

  p_render_data->push_back(std::make_unique<ui::StaticStringRenderData>("1up", 
                                                                        736.F / 5.F, 
                                                                        0.75F * scale, 
                                                                        0.75F, 
                                                                        ui::Justification::Centre));

  return std::make_unique<UILayer>(scale, 
                                   std::move(p_string_renderer),
                                   std::move(p_render_data),
                                   render_offset_y);
}

}
}
