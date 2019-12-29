#include "stdafx.h"
#include "system/SystemCommandManager.h"


namespace pacman {
namespace controller {
namespace system {

SystemCommandManager::SystemCommandManager() {}


void SystemCommandManager::RegisterCommand(std::unique_ptr<ICommand> p_command,
                                           ISystemEvent* system_event) {
	this->GetMap()[system_event] = std::move(p_command);
}


void SystemCommandManager::DeregisterCommand(ISystemEvent* system_event) {
	if (this->HasEvent(system_event)) {
		this->GetMap().erase(system_event);
	}
}


ICommand* SystemCommandManager::GetCommand(ISystemEvent* system_event) const {
	return this->GetMap().at(system_event).get();
}


bool SystemCommandManager::HasEvent(ISystemEvent* system_event) const {
  return this->GetMap().find(system_event) != this->GetMap().end();
}

}
}
}