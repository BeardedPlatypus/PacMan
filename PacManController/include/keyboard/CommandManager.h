#pragma once
#include "ICommandManager.h"

#include <unordered_map>
#include <functional>


namespace pacman {
namespace controller {
namespace keyboard {
	
/// <summary>
/// <see cref="CommandManager" /> implements the <see cref="ICommandManager" />. 
/// </summary>
/// <seealso cref="ICommandManager" />
class CommandManager final : public ICommandManager {
public:	
  /// <summary>
  /// Construct a new <see cref="CommandManager"/>.
  /// </summary>
  CommandManager();

  void RegisterCommand(std::unique_ptr<ICommand> p_command,
	                   IEvent* kb_event) final;

  void DeregisterCommand(IEvent* kb_event) final;

  ICommand* GetCommand(IEvent* kb_event) const final;

  bool HasEvent(IEvent* kb_event) const final;

private:		
	/// <summary>
	/// Get the map associated with p_map.
	/// </summary>
	/// <returns> The map associated with p_map. </returns>
  inline std::unordered_map<IEvent*,
                            std::unique_ptr<ICommand>>& GetMap() const {
    return *(this->p_map.get());
   }

  /// <summary>
  /// Pointer to the event command map of this <see cref="CommandManager" /> 
  /// </summary>
  std::unique_ptr<std::unordered_map<IEvent*, 
		                             std::unique_ptr<ICommand>>> p_map;
};

}
}
}

