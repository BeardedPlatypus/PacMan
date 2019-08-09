#pragma once

#include "event/IKeyboardEvent.h"
#include "gmock/gmock.h"


class KeyboardEventMock : public pacman::controller::IKeyboardEvent {
public:
	MOCK_METHOD1(Accept, void(const pacman::controller::IEventVisitor&));

  MOCK_CONST_METHOD0(GetType, pacman::controller::KeyboardEventType());
  MOCK_CONST_METHOD0(GetScancode, pacman::controller::keyboard::Scancode());
};
