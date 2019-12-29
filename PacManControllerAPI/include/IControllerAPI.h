#pragma once
#define DllExport __declspec( dllexport )

#include <memory>

#include "SystemEventType.h"
#include "KeyboardEventType.h"
#include "ScanCode.h"

#include "IControllerCommand.h"

namespace pacman {
namespace controller {
namespace api {

/// <summary>
/// <see cref="IControllerAPI" /> defines the interface with which external
/// clients interact with the controller component. It provides the basic
/// functionality to request and register <see cref="IControllerCommand"/>, as
/// well as the functionality to call the Update function.
/// </summary>
class DllExport IControllerAPI {
public:
  /// <summary>
  /// Construct a new <see cref="IControllerAPI"/>.
  /// </summary>
  /// <returns>
  /// A <see cref="std::unique_ptr"/> containing a new instance of a
  /// <see cref="IControllerAPI"/>.
  /// </returns>
  static std::unique_ptr<IControllerAPI> Construct();
  
  /// <summary>
  /// Finalise this <see cref="IControllerAPI"/>.
  /// </summary>
  virtual ~IControllerAPI() = default;

  /// <summary>
  /// Update the controller component.
  /// </summary>
  virtual void Update() = 0;

  /// <summary>
  /// Register the command <paramref name="p_command"/> to the 
  /// system event of type <paramref name="system_event_type"/>.
  /// </summary>
  /// <param name="system_event_type"> Type of the system event. </param>
  /// <param name="p_command"> 
  /// A <see cref="std::unique_ptr"/> to the command to be registered .
  /// </param>
  // <remarks>
  /// If a command is already associated with the specified 
  /// <paramref name="system_event_type"/> it will be overwritten.
  /// </remarks>
  virtual void RegisterSystemCommand(SystemEventType system_event_type,
                                     std::unique_ptr<IControllerCommand> p_command) = 0;

  /// <summary>
  /// Deregisters the command associated with the system event of
  /// type <paramref name="system_event_type"/>.
  /// </summary>
  /// <param name="system_event_type"> Type of system event. </param>
  /// <remarks>
  /// If no event was registered, nothing will change.
  /// </remarks>
  virtual void DeregisterSystemCommand(SystemEventType system_event_type) = 0;

  /// <summary>
  /// Registers the command of <paramref name="p_command"/> to the 
  /// keyboard event of type <paramref name="keyboard_event_type"/>
  /// and the specified <paramref name="scancode"/>.
  /// </summary>
  /// <param name="keyboard_event_type"> Type of the keyboard event. </param>
  /// <param name="scancode"> The scancode. </param>
  /// <param name="p_command"> 
  /// A <see cref="std::unique_ptr"/> to the command to be registered .
  /// </param>
  // <remarks>
  /// If a command is already associated with the specified 
  /// <paramref name="keyboard_event_type"/> and <paramref name="scancode"/>
  /// it will be overwritten.
  /// </remarks>
  virtual void RegisterKeyboardCommand(KeyboardEventType keyboard_event_type,
                                       Scancode scancode,
                                       std::unique_ptr<IControllerCommand> p_command) = 0;

  /// <summary>
  /// Deregisters the command associated with the keyboard event of
  /// type <paramref name="keyboard_event_type"/> and <paramref name="scancode"/>.
  /// </summary>
  /// <param name="keyboard_event_type"> Type of keyboard event. </param>
  /// <param name="scancode"> The scancode. </param>
  /// <remarks>
  /// If no event was registered, nothing will change.
  /// </remarks>
  virtual void DeregisterKeyboardCommand(KeyboardEventType keyboard_event_type,
                                         Scancode scancode) = 0;
};

}
}
}

