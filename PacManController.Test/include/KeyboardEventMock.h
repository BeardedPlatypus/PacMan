#pragma once

#include "keyboard/IEvent.h"
#include "gmock/gmock.h"


class KeyboardEventMock : public pacman::controller::keyboard::IEvent {
public:
	MOCK_CONST_METHOD0(GetName, std::string());
};
