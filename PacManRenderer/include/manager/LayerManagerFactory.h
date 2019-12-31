#pragma once

#include <memory>
#include "manager/ILayerManager.h"

#include "IViewAPI.h"
#include "IGameState.h"


namespace pacman {
namespace renderer {

std::unique_ptr<ILayerManager> ConstructLayerManager(view::IViewAPI* p_view_api,
                                                     const state::IGameState* p_game_state);

}
}
