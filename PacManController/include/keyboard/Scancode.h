#pragma once


namespace pacman {
namespace controller {
namespace keyboard {
	
/// <summary>
/// The <see cref="Scancode" /> enumaration describes the supported keyboard
/// scancodes within this Controller.
/// These Scancodes are used to subscribe to the different keyboard events.
/// </summary>
enum class Scancode {
	W,
	A,
	S,
	D,
	Escape,
	ArrowUp,
	ArrowLeft,
	ArrowDown,
	ArrowRight,
};

}
}
}
