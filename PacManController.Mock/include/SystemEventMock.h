#pragma once

#include "event/ISystemEvent.h"
#include "gmock/gmock.h"


class SystemEventMock : public pacman::controller::ISystemEvent {
public:
	MOCK_METHOD(void, Accept, (const pacman::controller::IEventVisitor&));
  MOCK_METHOD(pacman::controller::SystemEventType, GetType, (), (const, override));
};
