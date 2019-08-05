#pragma once

#include "event/IKeyboardEvent.h"
#include "gmock/gmock.h"


class KeyboardEventMock : public pacman::controller::IKeyboardEvent {
public:
	MOCK_METHOD1(Accept, void(const pacman::controller::IEventVisitor&));
};
