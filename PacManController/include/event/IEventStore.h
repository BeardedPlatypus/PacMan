#pragma once

#include <memory>

#include "event/IKeyboardEvent.h"
#include "event/ISystemEvent.h"


namespace pacman {
namespace controller {

/// <summary>
/// <see cref="IEventStore" /> is responsible for constructing, and 
/// managing events.
/// </summary>
class IEventStore {
public:
  /// <summary>
  /// Construct a new <see cref="IEventStore" />.
  /// </summary>
  /// <returns> A new <see cref="IEventStore" />. </returns>
  static std::unique_ptr<IEventStore> Construct();

  virtual ~IEventStore() = default;

  /// <summary>
  /// Get the pointer to <see cref="IKeyboardEvent" /> corresponding with
  /// the <paramref name="event_type" /> and <paramref name="scan_code" />.
  /// </summary>
  /// <param name="event_type"> The type of keyboard event.</param>
  /// <param name="scan_code"> The scancode. </param>
  /// <returns> 
  /// A pointer to the corresponding <see cref="IkeyboardEvent" />. 
  /// </returns>
  virtual IKeyboardEvent* GetKeyboardEvent(KeyboardEventType event_type,
                                           keyboard::Scancode scancode) = 0;

  /// <summary>
  /// Get the pointer to <see cref="ISystemEvent" /> corresponding with
  /// the <paramref name="event_type" />.
  /// </summary>
  /// <param name="event_type"> The type of system event.</param>
  /// <returns> 
  /// A pointer to the corresponding <see cref="ISystemEvent" />. 
  /// </returns>
  virtual ISystemEvent* GetSystemEvent(SystemEventType event_type) = 0;
};

}
}