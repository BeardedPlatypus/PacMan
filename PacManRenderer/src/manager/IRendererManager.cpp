#include "pch.h"
#include "manager/IRendererManager.h"

#include "manager/RendererManager.h"

namespace pacman {
namespace renderer {

std::unique_ptr<IRendererManager> IRendererManager::Construct(
    state::IGameState* p_game_state,
    view::IViewManager* p_view_manager) {
  return std::make_unique<RendererManager>(p_game_state, p_view_manager);
}

}
}
