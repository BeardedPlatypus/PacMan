#pragma once

#include "IEventGenerator.h"
#include "IEventStore.h"


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
  /// <summary>
  /// Construct a new of the <see cref="EventGenerator"/>.
  /// </summary>
  /// <param name="p_event_store"> 
  /// A pointer to the <see cref="IEventStore" />. 
  /// </param>
  EventGenerator(IEventStore* p_event_store);

  void PollEvents() final;

  std::vector<IEvent*> GetEvents() const final;

private:  
  inline const std::vector<IEvent*>& GetEventsVector() const { 
    return this->events_vector; 
  }

  /// <summary>
  /// The vector containing all events of this <see cref="EventGenerator" />.
  /// </summary>
  std::vector<IEvent*> events_vector;
   
  /// <summary>
  /// Get a pointer to the <see cref="IEventStore" /> of this
  /// <see cref="EventGenerator" />
  /// </summary>
  /// <returns> 
  /// A pointer to the <see cref="IventStore" /> of this <see cref="EventGenerator" />. 
  /// </returns>
  inline IEventStore* GetEventStore() const {
    return this->p_event_store;
  }

  /// <summary>
  /// The <see cref="IEventStore" /> of this <see cref="EventGenerator" />.
  /// </summary>
  IEventStore* p_event_store;
};

}
}
