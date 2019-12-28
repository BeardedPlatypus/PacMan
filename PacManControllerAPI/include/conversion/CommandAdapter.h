#pragma once

#include "ICommand.h"
#include "IControllerCommand.h"

#include <memory>

namespace pacman {
namespace controller {
namespace api {

class CommandAdapter final : public ICommand {
public:
  explicit CommandAdapter(std::unique_ptr<IControllerCommand> p_cmd);

  inline void Execute() final { this->p_cmd->Execute(); }

private:
  std::unique_ptr<IControllerCommand> p_cmd;
};

}
}
}
