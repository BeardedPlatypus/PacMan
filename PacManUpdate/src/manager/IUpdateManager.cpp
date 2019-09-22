#include "pch.h"
#include "manager/IUpdateManager.h"

#include "manager/UpdateManager.h"


namespace pacman {
namespace update {

std::unique_ptr<IUpdateManager> IUpdateManager::Construct(state::IGameState* p_game_state,
                                                          controller::IControllerManager* p_controller_manager) {
    return std::make_unique<UpdateManager>(p_game_state, 
                                           p_controller_manager);
}

}
}