#pragma once

#include <string>

#include "IEventVisitor.h"


namespace pacman {
namespace controller {
	
/// <summary>
/// <see cref="keyboard::IEvent"/> specifies a single keyboard event, which
/// can be used to register <see cref="ICommand"/> to.
/// 
/// The <see cref="IEvent"/> implements the Visitor pattern, which can be 
/// used by implementing a <see cref="IEventVisitor"/>.
/// </summary>
class IEvent {
public:  
  virtual ~IEvent() = default;

  /// <summary>
  /// Accept the <paramref name="visitor"> by passing the implementing instance
  /// back.
  /// </summary>
  /// <param name="visitor"> The visitor. </param>
  virtual void Accept(IEventVisitor* visitor) = 0;
};

}
}
