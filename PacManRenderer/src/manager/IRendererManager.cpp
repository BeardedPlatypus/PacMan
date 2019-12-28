#include "pch.h"
#include "manager/IRendererManager.h"

#include "manager/RendererManager.h"

namespace pacman {
namespace renderer {

std::unique_ptr<IRendererManager> IRendererManager::Construct(
    state::IGameState* p_game_state,
    view::IViewAPI* p_view_api) {
  return std::make_unique<RendererManager>(p_game_state, p_view_api);
}

}
}
