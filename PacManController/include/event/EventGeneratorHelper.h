#pragma once

#include <memory>
#include <SDL2/SDL.h>

#include "IEvent.h"
#include "event/IEventStore.h"


namespace pacman {
namespace controller {
  
/// <summary>
/// <see cref="EventGeneratorHelper"/> is responsible for converding
/// SDL_Events to internal <see cref="IEvent"/>s.
/// </summary>
class EventGeneratorHelper {
public:      
  /// <summary>
  /// Determines whether this <see cref="EventGeneratorHelper"/> 
  /// [can convert SDL event] the specified p event.
  /// </summary>
  /// <param name="p_event"> 
  /// The pointer to the <see cref="SDL_Event"/> to convert.
  /// </param>
  /// <returns>
  /// <c>true</c> if this instance [can convert SDL event] the specified p 
  /// event; otherwise, <c>false</c>.
  /// </returns>
  static bool CanConvertSdlEvent(const SDL_Event* p_event);

  /// <summary>
  /// Converts the SDL event to a <see cref="IEvent"/> through the
  /// <paramref name="p_event_store"/>.
  /// </summary>
  /// <param name="p_event"> 
  /// The pointer to the <see cref="SDL_Event"/> to convert.
  /// </param>
  /// <param name="p_event_store">
  /// The pointer to the <see cref="IEventStore"/> used to generate the 
  /// <see cref="IEvent"/>.
  /// </param>
  /// <returns> 
  /// A pointer to the corresponding <see cref="IEvent" />. 
  /// </returns>
  static IEvent* ConvertSdlEvent(const SDL_Event* p_event, IEventStore* p_event_store);
};

}
}
