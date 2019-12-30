#include "pch.h"
#include "manager/LayerManagerFactory.h"
#include "manager/LayerManager.h"

#include "entity/PlayerLayer.h"
#include "field/FieldLayer.h"

namespace pacman {
namespace renderer {

std::unique_ptr<ILayerManager> ConstructLayerManager(view::IViewAPI* p_view_api,
                                                     state::IGameState* p_game_state) {
  auto p_field_layer = std::make_unique<FieldLayer>(4.F,
                                                    p_view_api,
                                                    p_game_state->GetField());

  auto p_player_layer = std::make_unique<PlayerLayer>(4.F,
                                                      p_view_api,
                                                      p_game_state->GetPlayerState());

  std::vector<std::unique_ptr<IRenderLayer>> render_layers = {};
  render_layers.push_back(std::move(p_field_layer));
  render_layers.push_back(std::move(p_player_layer));

  return std::make_unique<LayerManager>(render_layers);
}

}
}