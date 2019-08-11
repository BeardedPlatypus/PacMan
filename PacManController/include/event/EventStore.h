#pragma once

#include <unordered_map>
#include "event/IEventStore.h"
#include <functional>

namespace pacman {
namespace controller {

struct KeyboardEventKey {
  KeyboardEventKey(KeyboardEventType event_type, keyboard::Scancode scancode) : event_type(event_type), scancode(scancode) {}
  KeyboardEventType event_type;
  keyboard::Scancode scancode;

  bool operator==(const KeyboardEventKey& other) const {
    return this->event_type == other.event_type && this->scancode == other.scancode;
  }
};


class KeyboardEventKeyHash {
public:
  typedef pacman::controller::KeyboardEventKey argument_type;
  typedef std::size_t result_type;
  result_type operator()(argument_type const& s) const noexcept
  {
    result_type const h1(std::hash<pacman::controller::KeyboardEventType>{}(s.event_type));
    result_type const h2(std::hash<pacman::controller::keyboard::Scancode>{}(s.scancode));
    return h1 ^ (h2 << 1);
  }
};



/// <summary>
/// <see cref="EventStore" /> implements <see cref="IEventStore" /> and 
/// provides the methods to obtain the Events used within this controller.
/// </summary>
/// <seealso cref="IEventStore" />
class EventStore final : public IEventStore {
public:
  /// <summary>
  /// Construct a new <see cref="EventStore"/>.
  /// </summary>
  EventStore();

  IKeyboardEvent* GetKeyboardEvent(KeyboardEventType event_type,
                                   keyboard::Scancode scancode) final;

  ISystemEvent* GetSystemEvent(SystemEventType event_type) final;

private:
  /// <summary>
  /// Gets the map containing all <see cref="IKeyboardEvent" />.
  /// </summary>
  /// <returns> The map containing all <see cref="IKeyboardEvent" />. </returns>
  inline std::unordered_map<KeyboardEventKey,
                            std::unique_ptr<IKeyboardEvent>,
                            KeyboardEventKeyHash>* GetKeyboardEventMap() const {
    return this->p_keyboard_event_map.get();
  }

  /// <summary>
  /// Pointer to the <see cref="std::unordered_map" /> containing all <see cref="IKeyboardEvent" />.
  /// </summary>
  std::unique_ptr<std::unordered_map<KeyboardEventKey,
                                     std::unique_ptr<IKeyboardEvent>, 
                                     KeyboardEventKeyHash>> p_keyboard_event_map;

  /// <summary>
  /// Gets the map containing all <see cref="ISystemEvent" />.
  /// </summary>
  /// <returns> The map containing all <see cref="ISystemEvent" />. </returns>
  inline std::unordered_map<SystemEventType, std::unique_ptr<ISystemEvent>>* GetSystemEventMap() const {
    return this->p_system_event_map.get();
  }

  /// <summary>
  /// Pointer to the <see cref="std::unordered_map" /> containing all <see cref="ISystemEvent" />.
  /// </summary>
  std::unique_ptr<std::unordered_map<SystemEventType, std::unique_ptr<ISystemEvent>>> p_system_event_map;
};


}
}
