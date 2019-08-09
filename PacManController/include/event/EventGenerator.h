#pragma once

#include "IEventGenerator.h"


namespace pacman {
namespace controller {
  
/// <summary>
/// The <see cref="EventGenerator" /> implements the <see cref="IEventGenerator" />
/// interface. It is responsible for generating <see cref="IEvents" />. These
/// events can then be obtained through the GetEvents method.
/// </summary>
/// <seealso cref="IEventGenerator" />
class EventGenerator final : public IEventGenerator {
public:
  EventGenerator();

  void PollEvents() final;

  std::vector<IEvent*> GetEvents() const final;

private:  
  inline const std::vector<std::unique_ptr<IEvent>>& GetEventsVector() const { 
    return this->events_vector; 
  }

  /// <summary>
  /// The vector containing all events of this <see cref="EventGenerator" />.
  /// </summary>
  std::vector<std::unique_ptr<IEvent>> events_vector;
};

}
}
