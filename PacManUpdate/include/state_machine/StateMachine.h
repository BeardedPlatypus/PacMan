#pragma once

#include "state_machine/IStateMachine.h"
#include <vector>


namespace pacman {
namespace update {
namespace state_machine {

template<class TValue, class TEvent>
class StateMachine : public IStateMachine<TValue, TEvent> {
public:
  StateMachine(std::vector<std::unique_ptr<INode<TValue, TEvent>>>& nodes,
               int active_node);

  TValue GetCurrentValue() const final;

  void Move(TEvent e) final;

private:  
  /// <summary>
  /// The nodes of this <see cref="StateMachine"/>.
  /// </summary>
  std::vector<std::unique_ptr<INode<TValue, TEvent>>> nodes;
  
  /// <summary>
  /// A pointer to the active node.
  /// </summary>
  INode<TValue, TEvent>* p_active_node;
};

template class StateMachine<AxisDirection, PlayerControlEvent>;

}
}
}
