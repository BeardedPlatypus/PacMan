#include "pch.h"
#include "IRendererAPI.h"
#include "RendererAPI.h"


namespace pacman {
namespace renderer {

std::unique_ptr<IRendererAPI> IRendererAPI::Construct(
    state::IGameState* p_game_state,
    view::IViewAPI* p_view_api) {
  return std::make_unique<RendererAPI>(p_game_state, p_view_api);
}

}
}
