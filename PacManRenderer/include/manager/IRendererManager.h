#pragma once
#define DllExport __declspec( dllexport )

#include <memory>

#include <IGameState.h>
#include <IViewAPI.h>

namespace pacman {
namespace renderer {
  
/// <summary>
/// <see cref="IRendererManager'/> provides an interface for external clients to
/// interact with this PacManRenderer. It provides the basic functionality to 
/// render the state of the game, as well as update the graphical representation.
/// </summary>
class DllExport IRendererManager {
public:  
  /// <summary>
  /// Constructs a new <see cref="IRendererManager"/>.
  /// </summary>
  /// <returns>
  /// A <see cref="std::unique_ptr"/> containing an instance of a
  /// <see cref="IRendererManager"/>.
  /// </returns>
  static std::unique_ptr<IRendererManager> Construct(state::IGameState* p_game_state,
                                                     view::IViewAPI* p_view_api);

  virtual void Initialise() = 0;

  virtual void Render() const = 0;
};

}
}
