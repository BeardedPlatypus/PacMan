#include <pch.h>
#include "state_machine/IStateMachine.h"
#include "state_machine/StateMachine.h"


namespace pacman {
namespace update {
namespace state_machine {

template <class TValue, class TEvent>
std::unique_ptr<IStateMachine<TValue, TEvent>> IStateMachine<TValue, TEvent>::Construct(std::vector<std::unique_ptr<INode<TValue, TEvent>>>& nodes, int active_node) {
  return std::make_unique<StateMachine<TValue, TEvent>>(nodes, active_node);
}

}
}
}
