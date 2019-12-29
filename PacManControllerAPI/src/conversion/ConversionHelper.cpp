#include "pch.h"
#include "conversion/ConversionHelper.h"

namespace pacman {
namespace controller {

KeyboardEventType ToInternal(api::KeyboardEventType keyboard_event_type) {
	switch (keyboard_event_type)
	{
	case api::KeyboardEventType::KeyDown:
		return KeyboardEventType::KeyDown;
	case api::KeyboardEventType::KeyUp:
		return KeyboardEventType::KeyUp;
	default:
		return (KeyboardEventType)-1;
	}
}


SystemEventType ToInternal(api::SystemEventType system_event_type) {
	if (system_event_type == api::SystemEventType::Quit) {
		return SystemEventType::Quit;
	}
	
	return (SystemEventType)-1;
}


keyboard::Scancode ToInternal(api::Scancode scancode) {
	switch (scancode)
	{
	case api::Scancode::W:
		return keyboard::Scancode::W;
	case api::Scancode::A:
		return keyboard::Scancode::A;
	case api::Scancode::S:
		return keyboard::Scancode::S;
	case api::Scancode::D:
		return keyboard::Scancode::D;
	case api::Scancode::Escape:
		return keyboard::Scancode::Escape;
	case api::Scancode::ArrowUp:
		return keyboard::Scancode::ArrowUp;
	case api::Scancode::ArrowLeft:
		return keyboard::Scancode::ArrowLeft;
	case api::Scancode::ArrowDown:
		return keyboard::Scancode::ArrowDown;
	case api::Scancode::ArrowRight:
		return keyboard::Scancode::ArrowRight;
	case api::Scancode::UnmappedCode:
		return keyboard::Scancode::UnmappedCode;
	default:
		return (keyboard::Scancode)-1;
	}
}

}
}

