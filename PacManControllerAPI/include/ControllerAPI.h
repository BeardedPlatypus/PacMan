#pragma once

#include "IControllerAPI.h"

#include <event/IEventGenerator.h>
#include <event/IEventParser.h>
#include <keyboard/IKBCommandManager.h>
#include <system/ISystemCommandManager.h>
#include <event/IEventStore.h>


namespace pacman {
namespace controller {
namespace api {

/// <summary>
/// <see cref="ControllerAPI"/> implements the interface for external
/// clients to interact with this PacManControllerAPI. It provides the basic
/// functionality to request and register <see cref="ICommand"/>, as well
/// the functionality to call the Update function.
/// </summary>
/// <seealso cref="IControllerAPI"/>
class ControllerAPI final : public IControllerAPI {
public:
  /// <summary>
  /// Construct a new <see cref="ControllerAPI"/> with the given parameters.
  /// </summary>
  /// <param name="p_event_generator"> 
  /// A pointer to the <see cref="IEventGenerator"/>.
  /// </param>
  /// <param name="p_keyboard_command_manager">
  /// A pointer to the <see cref="keyboard::ICommandManager"/>.
  /// <param name="p_system_command_manager">
  /// A pointer to the <see cref="system::ICommandManager"/>.
  /// </param>
  /// <param name="p_keyboard_event_parser">
  /// A pointer to the <see cref="IEventParser<IKeyboardEvent>"/>.
  /// </param>
  /// <param name="p_keyboard_event_parser">
  /// A pointer to the <see cref="IEventParser<IKeyboardEvent>"/>.
  /// </param>
  /// <param name="p_keyboard_event_parser">
  /// A pointer to the <see cref="IEventParser<ISystemEvent>"/>.
  /// </param>
  ControllerAPI(std::unique_ptr<IEventGenerator> p_event_generator,
                std::unique_ptr<keyboard::ICommandManager> p_keyboard_command_manager,
                std::unique_ptr<system::ICommandManager> p_system_command_manager,
                std::unique_ptr<IEventParser<IKeyboardEvent>> p_keyboard_event_parser,
                std::unique_ptr<IEventParser<ISystemEvent>> p_system_event_parser,
                std::unique_ptr<IEventStore> p_event_store);

  void Update() final;

  void RegisterSystemCommand(SystemEventType system_event_type,
                             std::unique_ptr<IControllerCommand> p_command) final;

  void DeregisterSystemCommand(SystemEventType system_event_type) final;

  void RegisterKeyboardCommand(KeyboardEventType keyboard_event_type,
                               Scancode scancode,
                               std::unique_ptr<IControllerCommand> p_command) final;

  void DeregisterKeyboardCommand(KeyboardEventType keyboard_event_type,
                                 Scancode scancode) final;

private:
  /// <summary>
  /// Get a pointer to the <see cref="IEventGenerator"/> of this 
  /// <see cref="ControllerManager"/>.
  /// </summary>
  /// <returns> 
  /// A pointer to the <see cref="IEventGenerator"/> of this 
  /// <see cref="ControllerManager" />
  /// </returns>
  inline IEventGenerator* GetEventGenerator() {
    return this->p_event_generator.get();
  }

  /// <summary>
  /// The <see cref="IEventGenerator"/> of this <see cref="ControllerManager"/>.
  /// </summary>
  std::unique_ptr<IEventGenerator> p_event_generator;

  /// <summary>
  /// Get a pointer to the <see cref="keyboard::ICommandManager"/> of this 
  /// <see cref="ControllerManager" />.
  /// </summary>
  /// <returns> 
  /// A pointer to the <see cref="keyboard::ICommandManager"/> of this 
  /// <see cref="ControllerManager"/>
  /// </returns>
  inline keyboard::ICommandManager* GetKeyboardCommandManager() {
    return this->p_keyboard_command_manager.get();
  }

  /// <summary>
  /// The <see cref="keyboard::ICommandManager"/> of this <see cref="ControllerManager"/>.
  /// </summary>
  std::unique_ptr<keyboard::ICommandManager> p_keyboard_command_manager;

  /// <summary>
  /// Get a pointer to the <see cref="IEventParser<IKeyboardEvent>"/> of this 
  /// <see cref="ControllerManager"/>.
  /// </summary>
  /// <returns> 
  /// A pointer to the <see cref="IEventParser<IKeyboardEvent"/> of this 
  /// <see cref="ControllerManager"/>
  /// </returns>
  inline IEventParser<IKeyboardEvent>* GetKeyboardEventParser() {
    return this->p_keyboard_event_parser.get();
  }

  /// <summary>
  /// The <see cref="IEventParser<IKeyboardEvent>"/> of this <see cref="ControllerManager"/>.
  /// </summary>
  std::unique_ptr<IEventParser<IKeyboardEvent>> p_keyboard_event_parser;

  /// <summary>
  /// Get a pointer to the <see cref="system::ICommandManager"/> of this 
  /// <see cref="ControllerManager"/>.
  /// </summary>
  // <returns> 
  // A pointer to the <see cref="system::ICommandManager"/> of this 
  // <see cref="ControllerManager"/>
  // </returns>
  inline system::ICommandManager* GetSystemCommandManager() {
    return this->p_system_command_manager.get();
  }

  /// <summary>
  /// The <see cref="system::ICommandManager"/> of this <see cref="ControllerManager"/>.
  /// </summary>
  std::unique_ptr<system::ICommandManager> p_system_command_manager;

  /// <summary>
  /// Get a pointer to the <see cref="IEventParser<ISystemEvent>"/> of this 
  /// <see cref="ControllerManager"/>.
  /// </summary>
  /// <returns> 
  /// A pointer to the <see cref="IEventGenerator"/> of this 
  /// <see cref="ControllerManager"/>.
  /// </returns>
  inline IEventParser<ISystemEvent>* GetSystemEventParser() {
    return this->p_system_event_parser.get();
  }

  /// <summary>
  /// The <see cref="IEventParser<ISystemEvent>"/> of this <see cref="ControllerManager"/>.
  /// </summary>
  std::unique_ptr<IEventParser<ISystemEvent>> p_system_event_parser;

  /// <summary>
  /// Gets a pointer to the <see cref="IEventStore"/> of this <see cref="ControllerManager"/>.
  /// </summary>
  /// <returns>
  /// A pointer to the <see cref="IEventStore"/> of this 
  /// <see cref="ControllerManager"/>.
  /// </returns>
  inline IEventStore* GetEventStore() {
    return this->p_event_store.get();
  }

  /// <summary>
  /// The <see cref="IEventStore"/> of this <see cref="ControllerManager"/>.
  /// </summary>
  std::unique_ptr<IEventStore> p_event_store;
};

}
}
}

