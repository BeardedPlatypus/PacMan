#include "stdafx.h"
#include "keyboard/IKBCommandManager.h"

#include "keyboard/KBCommandManager.h"


namespace pacman {
namespace controller {
namespace keyboard {

std::unique_ptr<ICommandManager> ICommandManager::Construct() {
  return std::make_unique<CommandManager>();
}

}
}
}