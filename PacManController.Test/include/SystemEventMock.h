#pragma once

#include "event/ISystemEvent.h"
#include "gmock/gmock.h"


class SystemEventMock : public pacman::controller::ISystemEvent {
public:
	MOCK_METHOD1(Accept, void(const pacman::controller::IEventVisitor&));

  MOCK_CONST_METHOD0(GetType, pacman::controller::SystemEventType());
};
