#pragma once

#include <memory>

#include "ICommand.h"
#include "IControllerCommand.h"


namespace pacman {
namespace controller {
namespace api {

/// <summary>
/// <see cref="CommandAdapter"/> acts as a wrapper to ensure the external
/// <see cref="IControllerCommand"/> can be used as an internal 
/// <see cref="ICommand"/>.
/// </summary>
/// <seealso cref="ICommand"/>
class CommandAdapter final : public ICommand {
public:  
  /// <summary>
  /// Create a new <see cref="CommandAdapter"/>.
  /// </summary>
  /// <param name="p_cmd">The p command.</param>
  explicit CommandAdapter(std::unique_ptr<IControllerCommand> p_cmd);

  inline void Execute() final { this->p_cmd->Execute(); }

private:  
  /// <summary>
  /// A pointer to the command this <see cref="CommandAdapter"/> wraps.
  /// </summary>
  std::unique_ptr<IControllerCommand> p_cmd;
};

}
}
}
