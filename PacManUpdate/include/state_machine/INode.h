#pragma once
#define DllExport __declspec( dllexport )

#include <memory>
#include "entity/AxisDirection.h"
#include "state_machine/events/PlayerControlEvent.h"
#include "state_machine/values/PlayerControlValue.h"


namespace pacman {
namespace update {
namespace state_machine {

/// <summary>
/// <see cref="INode"/> provides the interface which defines a state machine 
/// node. It provides the functionality to get the value, get connected nodes
/// and add new connection.
/// </summary>
template <class TValue, class TEvent>
class DllExport INode {
public:
  /// <summary>
  /// Construct a new <see cref="INode"/>
  /// </summary>
  /// <param name="value">The value.</param>
  /// <returns>
  /// A <see cref="std::unique_ptr"/> containing the newly created instance.
  /// </returns>
  static std::unique_ptr<INode<TValue, TEvent>> Construct(TValue value);

  virtual ~INode() {}

  /// <summary>
  /// Get the value of this <see cref="INode"/>.
  /// </summary>
  /// <returns>
  /// The value of this <See cref="INode"/>.
  /// </returns>
  virtual TValue GetValue() const = 0;

  /// <summary>
  /// Get the node linked with the specified event <paramref name="e"/>.
  /// </summary>
  /// <returns>
  /// If a state is linked with event <paramref name="e"/> exists, then this
  /// node; otherwise <c>null</c>.
  /// </returns>
  virtual INode<TValue, TEvent>* GetConnectedNode(TEvent e) const = 0;

  /// <summary>
  /// Add a path from this node to <paramref name="p_node"/> when event 
  /// <paramref name="e"/> is provided.
  /// </summary>
  virtual void AddConnection(INode<TValue, TEvent>* p_node, TEvent e) = 0;
};

template class INode<PlayerControlValue, PlayerControlEvent>;
template class INode<AxisDirection, PlayerControlEvent>;

}
}
}
