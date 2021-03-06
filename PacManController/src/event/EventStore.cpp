#include "stdafx.h"
#include "event/EventStore.h"

#include <stdexcept>
#include "event/KeyboardEvent.h"
#include "event/SystemEvent.h"


namespace pacman {
namespace controller {

EventStore::EventStore() { }

IKeyboardEvent* EventStore::GetKeyboardEvent(KeyboardEventType event_type,
                                             keyboard::Scancode scancode) {
  auto key = KeyboardEventKey(event_type, scancode);

  try {
    return this->GetKeyboardEventMap()->at(key).get();
  }
  catch (const std::out_of_range) {
    this->GetKeyboardEventMap()->emplace(key, std::make_unique<KeyboardEvent>(event_type, scancode));
    return this->GetKeyboardEventMap()->at(key).get();
  }
}


ISystemEvent* EventStore::GetSystemEvent(SystemEventType event_type) {
  try {
    return this->GetSystemEventMap()->at(event_type).get();
  }
  catch (const std::out_of_range) {
    this->GetSystemEventMap()->emplace(event_type, std::make_unique<SystemEvent>(event_type));
    return this->GetSystemEventMap()->at(event_type).get();
  }
}

}
}
