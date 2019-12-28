#include "pch.h"
#include "conversion/CommandAdapter.h"


namespace pacman {
namespace controller {
namespace api {

CommandAdapter::CommandAdapter(std::unique_ptr<IControllerCommand> p_cmd) : p_cmd(std::move(p_cmd)) {}

}
}
}