#include "pch.h"
#include "RendererAPI.h"

#include "field/FieldLayer.h"
#include "entity/PlayerLayer.h"


namespace pacman {
namespace renderer {

RendererAPI::RendererAPI(state::IGameState* p_game_state,
                         view::IViewAPI* p_view_api) :
    p_game_state(p_game_state),
    p_view_api(p_view_api) {
}


void RendererAPI::Initialise() {
  auto p_field_layer = std::make_unique<FieldLayer>(4.F,
                                                    this->p_view_api,
                                                    this->p_game_state->GetField());
  this->render_layers.push_back(std::move(p_field_layer));

  auto p_player_layer = std::make_unique<PlayerLayer>(4.F,
                                                      this->p_view_api,
                                                      this->p_game_state->GetPlayerState());
  this->render_layers.push_back(std::move(p_player_layer));

  for (size_t i = 0; i < this->render_layers.size(); i++) {
    render_layers[i]->Initialise();
  }
}


void RendererAPI::Render() const {
  for (size_t i = 0; i < this->render_layers.size(); i++) {
    render_layers[i]->Render();
  }
}


}
}
