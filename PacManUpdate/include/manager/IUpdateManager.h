#pragma once
#define DllExport __declspec( dllexport )

#include <memory>

#include <IGameState.h>
#include <manager/IControllerManager.h>


namespace pacman {
namespace update {

class DllExport IUpdateManager {
public:  
  /// <summary>
  /// Construct a new <see cref="IUpdateManager" />.
  /// </summary>
  /// <param name="p_game_state">Pointer to the <see cref="state::IGameState" />.</param>
  /// <param name="p_controller_manager">Pointer to the <see cref="controller::IControllerManager" />.</param>
  /// <returns>
  /// A <see cref="std::unique_ptr" /> containing an instance of a 
  /// <see cref="IUpdateManager" />.
  /// </returns>
  static std::unique_ptr<IUpdateManager> Construct(state::IGameState* p_game_state,
                                                   controller::IControllerManager* p_controller_manager);

  virtual void Initialise() = 0;

  virtual void Update(float dt) = 0;
};

}
}
