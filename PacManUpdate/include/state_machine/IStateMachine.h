#pragma once
#define DllExport __declspec( dllexport )

#include <memory>
#include <vector>

#include "state_machine/INode.h"


namespace pacman {
namespace update {
namespace state_machine {

/// <summary>
/// <see cref="IStateMachine"/> provides an interface for 
/// managing and interacting with a set of <see cref="INode"/>.
/// </summary>
template <class TValue, class TEvent>
class DllExport IStateMachine {  
public:
  /// <summary>
  /// Construct a new <see cref="IStateMachine" />.
  /// </summary>
  /// <param name="nodes">The set of nodes this <see cref="IStateMachine" /> will own.</param>
  /// <param name="active_node">The index of the active node.</param>
  /// <returns>
  /// A <see cref="std::unique_ptr"/> containing the new instance of 
  /// <see cref="IStateMachine"/>.
  /// </returns>
  static std::unique_ptr<IStateMachine<TValue, TEvent>> Construct(
    std::vector<std::unique_ptr<INode<TValue, TEvent>>>& nodes,
    int active_node);

  virtual ~IStateMachine() {}
  
  /// <summary>
  /// Get the current value of this <see cref="IStateMachine"/>.
  /// </summary>
  /// <returns>The current value.</returns>
  virtual TValue GetCurrentValue() const = 0;
  
  /// <summary>
  /// Move from the current state to the state obtained by <paramref name="e"/>.
  /// </summary>
  /// <param name="e">The event.</param>
  virtual void Move(TEvent e) = 0;
};

template class IStateMachine<AxisDirection, PlayerControlEvent>;
template class IStateMachine<PlayerControlValue, PlayerControlEvent>;

}
}
}
