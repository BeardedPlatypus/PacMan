#pragma once

#include <vector>
#include <memory>

#include "event/IEvent.h"
#include "event/IEventStore.h"

namespace pacman {
namespace controller {
  
/// <summary>
/// The <see cref="IEventGenerator" /> is responsible for generating 
/// <see cref="IEvent" />s through the PollEvents method. These can then be
/// obtained through the GetEvents method.
/// </summary>
class IEventGenerator {
public:  
  /// <summary>
  /// Construct a new <see cref="IEventGenerator" />.
  /// </summary>
  /// <returns> A new <see cref="IEventGenerator" /></returns>
  static std::unique_ptr<IEventGenerator> construct(IEventStore* p_event_store);

  virtual ~IEventGenerator() {}

  /// <summary>
  /// Poll the set of <see cref="IEvent" />s of the current frame.
  /// </summary>
  virtual void PollEvents() = 0;
  
  /// <summary>
  /// Get the set of <see cref="IEvent" />s of the last poll.
  /// </summary>
  /// <returns> 
  /// An immutable set of <see cref="IEvent" />s of the last poll. 
  /// </returns>
  virtual std::vector<IEvent*> GetEvents() const = 0;
};

}
}
