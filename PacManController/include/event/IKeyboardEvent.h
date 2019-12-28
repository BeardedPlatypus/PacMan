#pragma once

#include "IEvent.h"
#include "keyboard/Scancode.h"


namespace pacman {
namespace controller {

/// <summary>
/// The type of <see cref="IKeyboardEvent"/>.
/// </summary>
enum class KeyboardEventType {
  KeyDown,
  KeyUp,
};


/// <summary>
/// <see cref="IKeyboardEvent" /> extends the <see cref="IEvent"/> class with 
/// keyboard specific information.
/// </summary>
/// <seealso cref="IEvent" />
class IKeyboardEvent : public IEvent {
public:
	inline void Accept(IEventVisitor* visitor) override { visitor->Visit(this); }
  
  /// <summary>
  /// Get the <see cref="KeyboardEventType" /> of this 
  /// <see cref="IKeyboardEvent" />.
  /// </summary>
  /// <returns>
  /// The <see cref="KeyboardEventType" /> of this 
  /// <see cref="IKeyboardEvent" />.
  /// </returns>
  virtual KeyboardEventType GetType() const = 0;
  
  /// <summary>
  /// Get the <see cref="keyboard::Scancode" /> of this
  // <see cref="KeyboardEventType" />.
  /// </summary>
  /// <returns> 
  /// The <see cref="keyboard::Scancode" /> of this 
  /// <see cref="IKeyboardEvent" />.
  /// </returns>
  virtual keyboard::Scancode GetScancode() const = 0;
};

}
}
