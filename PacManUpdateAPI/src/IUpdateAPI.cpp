#include "pch.h"
#include "IUpdateAPI.h"
#include "UpdateAPI.h"


namespace pacman {
namespace update {

std::unique_ptr<IUpdateAPI> IUpdateAPI::Construct(state::IGameState* p_game_state,
                                                  controller::api::IControllerAPI* p_controller_manager) {
    return std::make_unique<UpdateAPI>(p_game_state, 
                                       p_controller_manager);
}

}
}
