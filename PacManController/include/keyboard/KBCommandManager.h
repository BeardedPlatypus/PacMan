#pragma once
#include "IKBCommandManager.h"

#include <unordered_map>
#include <functional>


namespace pacman {
namespace controller {
namespace keyboard {
	
/// <summary>
/// <see cref="CommandManager" /> implements the <see cref="ICommandManager" />. 
/// </summary>
/// <seealso cref="ICommandManager" />
class KeyboardCommandManager final : public IKeyboardCommandManager {
public:	
  /// <summary>
  /// Construct a new <see cref="CommandManager"/>.
  /// </summary>
  KeyboardCommandManager();

  void RegisterCommand(std::unique_ptr<ICommand> p_command,
	                     IKeyboardEvent* kb_event) final;

  void DeregisterCommand(IKeyboardEvent* kb_event) final;

  ICommand* GetCommand(IKeyboardEvent* kb_event) const final;

  bool HasEvent(IKeyboardEvent* kb_event) const final;

private:		
	/// <summary>
	/// Get the map associated with p_map.
	/// </summary>
	/// <returns> The map associated with p_map. </returns>
  inline std::unordered_map<IKeyboardEvent*,
                            std::unique_ptr<ICommand>>& GetMap() const {
    return *(this->p_map.get());
   }

  /// <summary>
  /// Pointer to the event command map of this <see cref="CommandManager" /> 
  /// </summary>
  std::unique_ptr<std::unordered_map<IKeyboardEvent*, 
		                             std::unique_ptr<ICommand>>> p_map = 
    std::make_unique<std::unordered_map<IKeyboardEvent*, std::unique_ptr<ICommand>>>();
};

}
}
}

