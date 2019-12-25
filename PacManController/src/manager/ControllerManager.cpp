#include "stdafx.h"
#include "manager/ControllerManager.h"


namespace pacman {
namespace controller {

ControllerManager::ControllerManager(std::unique_ptr<IEventGenerator> p_event_generator,
                                     std::unique_ptr<keyboard::ICommandManager> p_keyboard_command_manager,
                                     std::unique_ptr<system::ICommandManager> p_system_command_manager,
                                     std::unique_ptr<IEventParser<IKeyboardEvent>> p_keyboard_event_parser,
                                     std::unique_ptr<IEventParser<ISystemEvent>> p_system_event_parser,
                                     std::unique_ptr<IEventStore> p_event_store) :
    p_event_generator(std::move(p_event_generator)),
    p_keyboard_command_manager(std::move(p_keyboard_command_manager)),
    p_keyboard_event_parser(std::move(p_keyboard_event_parser)),
    p_system_command_manager(std::move(p_system_command_manager)),
    p_system_event_parser(std::move(p_system_event_parser)),
    p_event_store(std::move(p_event_store)) { }


void ControllerManager::Update() {
  this->GetEventGenerator()->PollEvents();
  std::vector<IEvent*> events = this->GetEventGenerator()->GetEvents();

  for (IEvent* p_event : events) {
    IKeyboardEvent* p_kb_event = (*(this->GetKeyboardEventParser()))(p_event);
    if (p_kb_event != nullptr && this->GetKeyboardCommandManager()->HasEvent(p_kb_event)) {
      this->GetKeyboardCommandManager()->GetCommand(p_kb_event)->Execute();
      continue;
    }
    
    ISystemEvent* p_system_event = (*(this->GetSystemEventParser()))(p_event);
    if (p_system_event != nullptr && this->GetSystemCommandManager()->HasEvent(p_system_event)) {
      this->GetSystemCommandManager()->GetCommand(p_system_event)->Execute();
      continue;
    }
  }
}


void ControllerManager::RegisterSystemCommand(SystemEventType system_event_type,
                                              std::unique_ptr<ICommand> p_command) {
  ISystemEvent* p_event = this->GetEventStore()->GetSystemEvent(system_event_type);
  this->GetSystemCommandManager()->RegisterCommand(std::move(p_command), p_event);
}


void ControllerManager::DeregisterSystemCommand(SystemEventType system_event_type) {
  ISystemEvent* p_event = this->GetEventStore()->GetSystemEvent(system_event_type);
  this->GetSystemCommandManager()->DeregisterCommand(p_event);
}


void ControllerManager::RegisterKeyboardCommand(KeyboardEventType keyboard_event_type,
                                                keyboard::Scancode scancode,
                                                std::unique_ptr<ICommand> p_command) {
  IKeyboardEvent* p_event = this->GetEventStore()->GetKeyboardEvent(keyboard_event_type,
                                                                    scancode);
  this->GetKeyboardCommandManager()->RegisterCommand(std::move(p_command), p_event);
}


void ControllerManager::DeregisterKeyboardCommand(KeyboardEventType keyboard_event_type,
                                                  keyboard::Scancode scancode) {
  IKeyboardEvent* p_event = this->GetEventStore()->GetKeyboardEvent(keyboard_event_type,
                                                                    scancode);
  this->GetKeyboardCommandManager()->DeregisterCommand(p_event);
}

}
}