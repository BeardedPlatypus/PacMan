#include "pch.h"
#include "state_machine/Node.h"


namespace pacman {
namespace update {
namespace state_machine {

template<class TValue, class TEvent>
Node<TValue, TEvent>::Node<TValue, TEvent>(TValue value) : 
  value(value), 
  p_node_table(std::make_unique<std::unordered_map<TEvent, INode<TValue, TEvent>*>>()) {}


template<class TValue, class TEvent>
INode<TValue, TEvent>* Node<TValue, TEvent>::GetConnectedNode(TEvent e) const {
  if (this->p_node_table->count(e) == 0) {
    return nullptr;
  }

  return this->p_node_table->at(e);
}


template<class TValue, class TEvent>
void Node<TValue, TEvent>::AddConnection(INode<TValue, TEvent>* p_node, TEvent e) {
  (*(this->p_node_table))[e] = p_node;
}

}
}
}
