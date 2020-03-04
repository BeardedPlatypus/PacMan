#pragma once

#include <memory>
#include "ui/UILayer.h"
#include "IViewAPI.h"

#include <score/IScoreBoard.h>

namespace pacman {
namespace renderer {

/// <summary>
/// Construct a new <see cref="UILayer"/> with the given scale and render_offset_y.
/// </summary>
/// <param name="scale">The scale to render with.</param>
/// <param name="p_view_api">Pointer to the view api to render with.</param>
/// <param name="render_offset_y">The y-offset to render width.</param>
/// <returns>
/// A new <see cref="UILayer"/>.
/// </returns>
std::unique_ptr<UILayer> ConstructUILayer(const state::score::IScoreBoard* p_score_board,
                                          float scale, 
                                          view::IViewAPI* p_view_api, 
                                          float render_offset_y);

}
}

