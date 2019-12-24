#include "stdafx.h"
#include "event/EventGenerator.h"

#include <SDL2/SDL.h>
#include "event/EventGeneratorHelper.h"


namespace pacman {
namespace controller {

EventGenerator::EventGenerator(IEventStore* p_event_store) : 
    p_event_store(p_event_store) { }


void EventGenerator::PollEvents() {
  this->events_vector.clear();

  SDL_Event sdl_event;
  while (SDL_PollEvent(&sdl_event)) {
    if (EventGeneratorHelper::CanConvertSdlEvent(&sdl_event)) {
      this->events_vector.push_back(EventGeneratorHelper::ConvertSdlEvent(&sdl_event, this->GetEventStore()));
    }
  }
}


std::vector<IEvent*> EventGenerator::GetEvents() const {
  return this->GetEventsVector();
}


}
}