#include "stdafx.h"
#include "event/IEventGenerator.h"

#include "event/EventGenerator.h"

namespace pacman {
namespace controller {

std::unique_ptr<IEventGenerator> IEventGenerator::construct(IEventStore* p_event_store) {
  return std::make_unique<EventGenerator>(p_event_store);
}

}
}