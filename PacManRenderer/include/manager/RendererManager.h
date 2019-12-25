#pragma once
#include "manager/IRendererManager.h"

#include <vector>
#include "IRenderLayer.h"

namespace pacman {
namespace renderer {

class RendererManager : public IRendererManager {
public:  
  RendererManager(state::IGameState* p_game_state,
                  view::IViewManager* p_view_manager);

  void Initialise();
  void Render() const;

private:  
  /// <summary>
  /// A pointer to the <see cref="state::IGameState" /> this 
  /// <see cref="RendererManager" /> observes.
  /// </summary>
  state::IGameState* p_game_state;
  
  /// <summary>
  /// A pointer to the <see cref="view::IViewManager" /> this
  /// <see cref="RendererManager" /> uses to render.
  /// </summary>
  view::IViewManager* p_view_manager;
  
  /// <summary>
  /// An ordered list of <see cref="IRenderLayer"/>.
  /// </summary>
  std::vector<std::unique_ptr<IRenderLayer>> render_layers = 
    std::vector<std::unique_ptr<IRenderLayer>>();
};

}
}
