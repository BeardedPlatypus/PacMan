#pragma once
#include "IRendererAPI.h"

#include "manager/ILayerManager.h"
#include "IViewAPI.h"
#include "IGameState.h"


namespace pacman {
namespace renderer {

class RendererAPI final : public IRendererAPI {
public:  
  RendererAPI(state::IGameState* p_game_state,
              view::IViewAPI* p_view_api);

  void Initialise() final;
  void Update(float dtime) final;
  void Render() const final;

private:  
  std::unique_ptr<ILayerManager> _p_layer_manager;
};

}
}
