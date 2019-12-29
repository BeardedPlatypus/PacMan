#pragma once

#include "IKeyboardEvent.h"


namespace pacman {
namespace controller {
  
/// <summary>
/// <see cref="KeyboardEvent" /> extends the <see cref="IEvent" class with 
/// keyboard specific information.
/// </summary>
/// <seealso cref="IEvent" />
class KeyboardEvent final : public IKeyboardEvent {  
public:
  /// <summary>
  /// Construct new <see cref="KeyboardEvent"/> with the specified parameters.
  /// </summary>
  /// <param name="type">The type.</param>
  /// <param name="scancode">The scancode.</param>
  KeyboardEvent(KeyboardEventType type,
                keyboard::Scancode scancode);

  inline KeyboardEventType GetType() const override { return this->type; }

  inline keyboard::Scancode GetScancode() const override { return this->scancode; }

private:  
  /// <summary> The type of this <see cref="KeyboardEvent" />. </summary>
  const KeyboardEventType type;

  /// <summary> The Scancode of this <see cref="KeyboardEvent" />. </summary>
  const keyboard::Scancode scancode;
};

}
}
