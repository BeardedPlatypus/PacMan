#pragma once

#include "event/IKeyboardEvent.h"
#include "event/ISystemEvent.h"
#include "KeyboardEventType.h"
#include "SystemEventType.h"
#include "keyboard/Scancode.h"
#include "Scancode.h"

namespace pacman {
namespace controller {

/// <summary>
/// Convert <paramref name="keyboard_event_type"/> to its internal equivalent.
/// </summary>
/// <param name="keyboard_event_type"> The keyboard event to convert. </param>
/// <returns>
/// The internal equivalent of <paramref name="keyboard_event_type"/>.
/// </returns>
KeyboardEventType ToInternal(api::KeyboardEventType keyboard_event_type);

/// <summary>
/// Convert <paramref name="system_event_type"/> to its internal equivalent.
/// </summary>
/// <param name="system_event_type"> The system event to convert. </param>
/// <returns>
/// The internal equivalent of <paramref name="system_event_type"/>.
/// </returns>
SystemEventType ToInternal(api::SystemEventType system_event_type);

/// <summary>
/// Convert <paramref name="scancode"/> to its internal equivalent.
/// </summary>
/// <param name="scancode"> The scancode to convert. </param>
/// <returns>
/// The internal equivalent of <paramref name="scancode"/>.
/// </returns>
keyboard::Scancode ToInternal(api::Scancode scancode);

}
}
