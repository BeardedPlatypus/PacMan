#include "stdafx.h"
#include "event/KeyboardEvent.h"


namespace pacman {
namespace controller {

KeyboardEvent::KeyboardEvent(KeyboardEventType type,
                             keyboard::Scancode scancode) :
    type(type),
    scancode(scancode) { }

}
}