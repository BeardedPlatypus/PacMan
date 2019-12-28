#pragma once

#include "ISystemEvent.h"

namespace pacman {
namespace controller {
  
/// <summary>
/// Implementation of <see cref="ISystemEvent" />.
/// </summary>
/// <seealso cref="ISystemEvent" />
class SystemEvent : public ISystemEvent {
public:      
  /// <summary>
  /// Construct a new <see cref="SystemEvent"/> with the given type.
  /// </summary>
  /// <param name="type">The type of this <see cref="SystemEvent" />.</param>
  explicit SystemEvent(SystemEventType type);

  inline SystemEventType GetType() const override { return this->type; }

private:  
  /// <summary>
  /// The type of this <see cref="SystemEvent" />.
  /// </summary>
  const SystemEventType type;
};

}
}