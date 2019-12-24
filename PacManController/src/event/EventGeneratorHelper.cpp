#include "stdafx.h"
#include "event/EventGeneratorHelper.h"

#include "event/KeyboardEvent.h"
#include "event/SystemEvent.h"

#include "keyboard/ScancodeConverter.h"

namespace pacman {
namespace controller {

bool EventGeneratorHelper::CanConvertSdlEvent(const SDL_Event* p_event) {
  // Keyboard events
  if (p_event->type == SDL_KEYDOWN ||
      p_event->type == SDL_KEYUP) {
    auto converter = keyboard::ScancodeConverter();

    keyboard::Scancode code = converter.Convert(p_event->key.keysym.scancode);
    return code != keyboard::Scancode::UnmappedCode;
  }

  // System events
  if (p_event->type == SDL_QUIT) {
    return true;
  }

  return false;
}


IEvent* EventGeneratorHelper::ConvertSdlEvent(const SDL_Event* p_event,
                                              IEventStore* p_event_store) {
  auto converter = keyboard::ScancodeConverter();
  keyboard::Scancode code = converter.Convert(p_event->key.keysym.scancode);

  switch (p_event->type)
  {
  case SDL_KEYDOWN :
    return p_event_store->GetKeyboardEvent(KeyboardEventType::KeyDown, code);
  case SDL_KEYUP:
    return p_event_store->GetKeyboardEvent(KeyboardEventType::KeyUp, code);
  case SDL_QUIT:
    return p_event_store->GetSystemEvent(SystemEventType::Quit);
  default:
    return nullptr;
  }
}

}
}
