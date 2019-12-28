#pragma once

#include "IEvent.h"


namespace pacman {
namespace controller {

/// <summary>
/// The type of <see cref="ISystemEvent" />.
/// </summary>
enum class SystemEventType {
  Quit,
};


/// <summary>
/// <see cref="ISystemEvent" /> extends the <see cref="IEvent" /> class with 
/// system specific information.
/// </summary>
/// <seealso cref="IEvent" />
class ISystemEvent : public IEvent {
public:
	void Accept(IEventVisitor* visitor) override { visitor->Visit(this); }
  
  /// <summary>
  /// Get <see cref="SystemEventType" /> of this <see cref="ISystemEvent" />.
  /// </summary>
  /// <returns> 
  /// The <see cref="SystemEventType" /> of this <see cref="ISystemEvent" />. 
  /// </returns>
  virtual SystemEventType GetType() const = 0;
};



}
}
