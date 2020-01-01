#pragma once
#define DllExport __declspec( dllexport )

#include <memory>

#include <IGameState.h>
#include <IViewAPI.h>


namespace pacman {
namespace renderer {
  
/// <summary>
/// <see cref="IRendererAPI'/> defines the interface for external clients to
/// interact with this PacManRenderer. It provides the basic functionality to 
/// render the state of the game, as well as update the graphical representation.
/// </summary>
class DllExport IRendererAPI {
public:  
  /// <summary>
  /// Constructs a new <see cref="IRendererManager"/>.
  /// </summary>
  /// <returns>
  /// A <see cref="std::unique_ptr"/> containing an instance of a
  /// <see cref="IRendererManager"/>.
  /// </returns>
  static std::unique_ptr<IRendererAPI> Construct(const state::IGameState* p_game_state,
                                                 view::IViewAPI* p_view_api);
  
  /// <summary>
  /// Initialise this <see cref="IRendererAPI"/>.
  /// </summary>
  virtual void Initialise() = 0;
  
  /// <summary>
  /// Update the active animations used by this Renderer component.
  /// </summary>
  /// <param name="dtime"> The time passed since the last frame update. </param>
  virtual void Update(float dtime) = 0;
  
  /// <summary>
  /// Render the current frame.
  /// </summary>
  virtual void Render() const = 0;
};

}
}
