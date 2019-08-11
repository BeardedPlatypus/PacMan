#include "stdafx.h"
#include "event/EventGenerator.h"

#include <SDL2/SDL.h>
#include "event/EventGeneratorHelper.h"


namespace pacman {
namespace controller {

EventGenerator::EventGenerator() : 
    events_vector(std::vector<std::unique_ptr<IEvent>>()) { }


void EventGenerator::PollEvents() {
  this->events_vector.clear();

  SDL_Event sdl_event;
  while (SDL_PollEvent(&sdl_event)) {
    if (EventGeneratorHelper::CanConvertSdlEvent(&sdl_event)) {
      this->events_vector.push_back(EventGeneratorHelper::ConvertSdlEvent(&sdl_event));
    }
  }
}


std::vector<IEvent*> EventGenerator::GetEvents() const {
  const std::vector<std::unique_ptr<IEvent>>& events = this->GetEventsVector();
  std::vector<IEvent*> result = std::vector<IEvent*>(events.size());

  for (size_t i = 0; i < events.size(); ++i) {
    result[i] = events[i].get();
  }

  return result;
}


}
}