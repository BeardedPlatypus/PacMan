#pragma once
#include "IRendererAPI.h"

#include <vector>
#include "IRenderLayer.h"

namespace pacman {
namespace renderer {

class RendererAPI : public IRendererAPI {
public:  
  RendererAPI(state::IGameState* p_game_state,
              view::IViewAPI* p_view_api);

  void Initialise();
  void Render() const;

private:  
  /// <summary>
  /// A pointer to the <see cref="state::IGameState"/> this 
  /// <see cref="RendererAPI"/> observes.
  /// </summary>
  state::IGameState* p_game_state;
  
  /// <summary>
  /// A pointer to the <see cref="view::IViewAPI"/> this
  /// <see cref="RendererAPI"/> uses to render.
  /// </summary>
  view::IViewAPI* p_view_api;
  
  /// <summary>
  /// An ordered list of <see cref="IRenderLayer"/>.
  /// </summary>
  std::vector<std::unique_ptr<IRenderLayer>> render_layers = 
    std::vector<std::unique_ptr<IRenderLayer>>();
};

}
}
