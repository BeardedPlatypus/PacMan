#include "pch.h"
#include "state_machine/StateMachine.h"

namespace pacman {
namespace update {
namespace state_machine {

template<class TValue, class TEvent>
StateMachine<TValue, TEvent>::StateMachine(std::vector<std::unique_ptr<INode<TValue, TEvent>>>& nodes_in, int active_node) : 
    nodes(std::vector<std::unique_ptr<INode<TValue, TEvent>>>()) {
  for (size_t i = 0; i < nodes_in.size(); i++) {
    this->nodes.push_back(std::move(nodes_in.at(i)));
  }

  this->p_active_node = this->nodes.at(active_node).get();
}


template<class TValue, class TEvent>
TValue StateMachine<TValue, TEvent>::GetCurrentValue() const {
  return this->p_active_node->GetValue();
}


template<class TValue, class TEvent>
void StateMachine<TValue, TEvent>::Move(TEvent e) {
  this->p_active_node = this->p_active_node->GetConnectedNode(e);
}


}
}
}