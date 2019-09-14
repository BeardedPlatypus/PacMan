#include "pch.h"
#include "manager/RendererManager.h"

#include "field/FieldLayer.h"


namespace pacman {
namespace renderer {

RendererManager::RendererManager(state::IGameState* p_game_state,
                                 view::IViewManager* p_view_manager) :
    p_game_state(p_game_state),
    p_view_manager(p_view_manager),
    render_layers(std::vector<std::unique_ptr<IRenderLayer>>()) {}


void RendererManager::Initialise() {
  auto p_field_layer = std::make_unique<FieldLayer>(2.F,
                                                    this->p_view_manager,
                                                    this->p_game_state->GetField());
  this->render_layers.push_back(std::move(p_field_layer));

  for (size_t i = 0; i < this->render_layers.size(); i++) {
    render_layers[i]->Initialise();
  }
}


void RendererManager::Render() const {
  for (size_t i = 0; i < this->render_layers.size(); i++) {
    render_layers[i]->Render();
  }
}


}
}
