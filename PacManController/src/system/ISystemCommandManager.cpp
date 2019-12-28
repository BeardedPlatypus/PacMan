#include "stdafx.h"
#include "system/ISystemCommandManager.h"

#include "system/SystemCommandManager.h"


namespace pacman {
namespace controller {
namespace system {

std::unique_ptr<ICommandManager> ICommandManager::Construct() {
  return std::make_unique<CommandManager>();
}

}
}
}
