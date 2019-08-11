#include "stdafx.h"
#include "system/SystemCommandManager.h"


namespace pacman {
namespace controller {
namespace system {

CommandManager::CommandManager() : 
	p_map(std::make_unique<std::unordered_map<ISystemEvent*, std::unique_ptr<ICommand>>>()) {
}


void CommandManager::RegisterCommand(std::unique_ptr<ICommand> p_command,
                                     ISystemEvent* system_event) {
	this->GetMap()[system_event] = std::move(p_command);
}


void CommandManager::DeregisterCommand(ISystemEvent* system_event) {
	if (this->HasEvent(system_event)) {
		this->GetMap().erase(system_event);
	}
}


ICommand* CommandManager::GetCommand(ISystemEvent* system_event) const {
	return this->GetMap().at(system_event).get();
}


bool CommandManager::HasEvent(ISystemEvent* system_event) const {
  return this->GetMap().find(system_event) != this->GetMap().end();
}

}
}
}