#include "pch.h"
#include "IControllerAPI.h"

#include "ControllerAPI.h"


namespace pacman {
namespace controller {
namespace api {

std::unique_ptr<IControllerAPI> IControllerAPI::Construct() {
  std::unique_ptr<keyboard::ICommandManager> p_keyboard_command_manager = 
    keyboard::ICommandManager::Construct();
  std::unique_ptr<system::ICommandManager> p_system_command_manager = 
    system::ICommandManager::Construct();

  std::unique_ptr<IEventParser<IKeyboardEvent>> p_keyboard_event_parser = 
    IEventParser<IKeyboardEvent>::Construct();
  std::unique_ptr<IEventParser<ISystemEvent>> p_system_event_parser = 
    IEventParser<ISystemEvent>::Construct();

  std::unique_ptr<IEventStore> p_event_store = 
    IEventStore::Construct();
  std::unique_ptr<IEventGenerator> p_event_generator = 
    IEventGenerator::Construct(p_event_store.get());

  return std::make_unique<ControllerAPI>(std::move(p_event_generator),
                                         std::move(p_keyboard_command_manager),
                                         std::move(p_system_command_manager),
                                         std::move(p_keyboard_event_parser),
                                         std::move(p_system_event_parser),
                                         std::move(p_event_store));
}

}
}
}
