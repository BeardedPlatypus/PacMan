#include "stdafx.h"
#include "event/IEventStore.h"

#include "event/EventStore.h"

namespace pacman {
namespace controller {

std::unique_ptr<IEventStore> IEventStore::Construct() {
  return std::make_unique<EventStore>();
}

}
}
