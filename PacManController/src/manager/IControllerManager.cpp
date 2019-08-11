#include "stdafx.h"
#include "manager/IControllerManager.h"

#include "manager/ControllerManager.h"


namespace pacman {
namespace controller {

std::unique_ptr<IControllerManager> IControllerManager::Construct(std::unique_ptr<IEventGenerator> p_event_generator,
                                                                  std::unique_ptr<keyboard::ICommandManager> p_keyboard_command_manager,
                                                                  std::unique_ptr<system::ICommandManager> p_system_command_manager,
                                                                  std::unique_ptr<IEventParser<IKeyboardEvent>> p_keyboard_event_parser,
                                                                  std::unique_ptr<IEventParser<ISystemEvent>> p_system_event_parser,
                                                                  std::unique_ptr<IEventStore> p_event_store) {
  return std::make_unique<ControllerManager>(std::move(p_event_generator), 
                                             std::move(p_keyboard_command_manager),
                                             std::move(p_system_command_manager),
                                             std::move(p_keyboard_event_parser),
                                             std::move(p_system_event_parser),
                                             std::move(p_event_store));
}


std::unique_ptr<IControllerManager> IControllerManager::Construct() {
  std::unique_ptr<keyboard::ICommandManager> p_keyboard_command_manager = keyboard::ICommandManager::construct();
  std::unique_ptr<system::ICommandManager> p_system_command_manager   = system::ICommandManager::construct();

  std::unique_ptr<IEventParser<IKeyboardEvent>> p_keyboard_event_parser = IEventParser<IKeyboardEvent>::construct();
  std::unique_ptr<IEventParser<ISystemEvent>> p_system_event_parser   = IEventParser<ISystemEvent>::construct();

  std::unique_ptr<IEventStore> p_event_store = IEventStore::Construct();
  std::unique_ptr<IEventGenerator> p_event_generator = IEventGenerator::construct(p_event_store.get());

  return IControllerManager::Construct(std::move(p_event_generator),
                                       std::move(p_keyboard_command_manager),
                                       std::move(p_system_command_manager),
                                       std::move(p_keyboard_event_parser),
                                       std::move(p_system_event_parser),
                                       std::move(p_event_store));
}

}
}