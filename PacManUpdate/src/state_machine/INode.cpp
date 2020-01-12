#include <pch.h>
#include "state_machine/INode.h"
#include "state_machine/Node.h"


namespace pacman {
namespace update {
namespace state_machine {

template <class TValue, class TEvent>
std::unique_ptr<INode<TValue, TEvent>> INode<TValue, TEvent>::Construct(TValue value) {
  return std::make_unique<Node<TValue, TEvent>>(value);
}

}
}
}
