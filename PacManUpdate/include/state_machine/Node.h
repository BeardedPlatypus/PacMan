#pragma once
#include "state_machine/INode.h"
#include <unordered_map>

namespace pacman {
namespace update {
namespace state_machine {

/// <summary>
/// <see cref="Node"/> provides a concrete implementation of the 
/// <see cref="INode"/> interface.
/// <summary>
template <class TValue, class TEvent>
class Node : public INode<TValue, TEvent> {
public:  
  /// <summary>
  /// Construct a new <see cref="Node"/>.
  /// </summary>
  /// <param name="value">The value.</param>
  explicit Node(TValue value);

  TValue GetValue() const final { return this->value; }

  INode<TValue, TEvent>* GetConnectedNode(TEvent e) const final;

  void AddConnection(INode<TValue, TEvent>* p_node, TEvent e) final;

private:  
  /// <summary>The value of this <see cref="Node"/>.</summary>
  const TValue value;
  
  /// <summary>The state machine table of this node.</summary>
  std::unique_ptr<std::unordered_map<TEvent, INode<TValue, TEvent>*>> p_node_table;
};

template class Node<AxisDirection, PlayerControlEvent>;
template class Node<PlayerControlValue, PlayerControlEvent>;

}
}
}
