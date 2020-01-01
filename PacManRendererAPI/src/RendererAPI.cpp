#include "pch.h"
#include "RendererAPI.h"

#include "manager/LayerManagerFactory.h"

namespace pacman {
namespace renderer {

  RendererAPI::RendererAPI(const state::IGameState* p_game_state,
                           view::IViewAPI* p_view_api) :
    _p_layer_manager(ConstructLayerManager(p_view_api, p_game_state)) {
}


void RendererAPI::Initialise() {
  this->_p_layer_manager->Initialise();
}


void RendererAPI::Update(float dtime) {
  this->_p_layer_manager->Update(dtime);
}


void RendererAPI::Render() const {
  this->_p_layer_manager->Render();
}


}
}
