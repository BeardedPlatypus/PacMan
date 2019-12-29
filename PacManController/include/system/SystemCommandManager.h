#pragma once

#include <unordered_map>

#include "system/ISystemCommandManager.h"


namespace pacman {
namespace controller {
namespace system {
  
/// <summary>
/// <see cref="system::CommandManager" /> implements the <see cref="system::ICommandManager" />.
/// It provides an interface for storing, and retrieving <see cref="ICommand"/>s
/// linked to <see cref="ISystemEvent" />s.
/// </summary>
/// <seealso cref="ICommandManager" />
class SystemCommandManager final : public ISystemCommandManager {  
public:
  /// <summary>
  /// Construct a new <see cref="CommandManager" />.
  /// </summary>
  SystemCommandManager();

  void RegisterCommand(std::unique_ptr<ICommand> p_command,
                       ISystemEvent* kb_event) final;

  void DeregisterCommand(ISystemEvent* kb_event) final;

  ICommand* GetCommand(ISystemEvent* kb_event) const final;

  bool HasEvent(ISystemEvent* kb_event) const final;

private:
	/// <summary>
	/// Get the map associated with p_map.
	/// </summary>
	/// <returns> The map associated with p_map. </returns>
  inline std::unordered_map<ISystemEvent*,
                            std::unique_ptr<ICommand>>& GetMap() const {
    return *(this->p_map.get());
  }

  /// <summary>
  /// Pointer to the event command map of this <see cref="CommandManager" /> 
  /// </summary>
  std::unique_ptr<std::unordered_map<ISystemEvent*, 
		                             std::unique_ptr<ICommand>>> p_map = 
    std::make_unique<std::unordered_map<ISystemEvent*, std::unique_ptr<ICommand>>>();
};

}
}
}
