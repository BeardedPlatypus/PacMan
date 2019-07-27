#pragma once

#include "ICommand.h"
#include "gmock/gmock.h"


class CommandMock : public pacman::controller::ICommand {
public:
	MOCK_METHOD0(Execute, void());
};
