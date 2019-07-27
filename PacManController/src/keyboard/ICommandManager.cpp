#include "stdafx.h"
#include "keyboard/ICommandManager.h"

#include "keyboard/CommandManager.h"


namespace pacman {
namespace controller {
namespace keyboard {

std::unique_ptr<ICommandManager> ICommandManager::construct() {
  return std::make_unique<CommandManager>();
}

}
}
}