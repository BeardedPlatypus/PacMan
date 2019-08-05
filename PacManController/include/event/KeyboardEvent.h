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
};

}
}
