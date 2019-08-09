#pragma once
#define DllExport __declspec( dllexport )

#include <memory>
#include <SDL2/SDL.h>

#include "IEvent.h"


namespace pacman {
namespace controller {
  
/// <summary>
/// <see cref="EventGeneratorHelper" /> is responsible for converding
/// SDL_Events to internal <see cref="IEvent" />s.
/// </summary>
class DllExport EventGeneratorHelper {
public:      
  /// <summary>
  /// Determines whether this <see cref="EventGeneratorHelper" /> 
  /// [can convert SDL event] the specified p event.
  /// </summary>
  /// <param name="p_event"> 
  /// The pointer to the <see cref="SDL_Event" /> to convert.
  /// </param>
  /// <returns>
  /// <c>true</c> if this instance [can convert SDL event] the specified p 
  /// event; otherwise, <c>false</c>.
  /// </returns>
  static bool CanConvertSdlEvent(SDL_Event* p_event);

  /// <summary>
  /// Converts the SDL event to a <see cref="std::unique_ptr<IEvent>" />.
  /// </summary>
  /// <param name="p_event"> 
  /// The pointer to the <see cref="SDL_Event" /> to convert.
  /// </param>
  /// <returns> 
  /// A pointer to the corresponding <see cref="IEvent" />. 
  /// </returns>
  static std::unique_ptr<IEvent> ConvertSdlEvent(SDL_Event* p_event);
};

}
}
