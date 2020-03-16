#pragma once

#include "event/IKeyboardEvent.h"
#include "gmock/gmock.h"


class KeyboardEventMock : public pacman::controller::IKeyboardEvent {
public:
	MOCK_METHOD(void, Accept, (const pacman::controller::IEventVisitor&));
  MOCK_METHOD(pacman::controller::KeyboardEventType, GetType, (), (const, override));
  MOCK_METHOD(pacman::controller::keyboard::Scancode, GetScancode, (), (const, override));
};
