#include "stdafx.h"
#include "keyboard/KBCommandManager.h"

namespace pacman {
namespace controller {
namespace keyboard {

CommandManager::CommandManager() {}


void CommandManager::RegisterCommand(std::unique_ptr<ICommand> p_command,
                                     IKeyboardEvent* kb_event) {
	this->GetMap()[kb_event] = std::move(p_command);
}


void CommandManager::DeregisterCommand(IKeyboardEvent* kb_event) {
	if (this->HasEvent(kb_event)) {
		this->GetMap().erase(kb_event);
	}
}


ICommand* CommandManager::GetCommand(IKeyboardEvent* kb_event) const {
	return this->GetMap().at(kb_event).get();
}


bool CommandManager::HasEvent(IKeyboardEvent* kb_event) const {
  return this->GetMap().find(kb_event) != this->GetMap().end();
}

}
}
}