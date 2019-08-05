#pragma once

namespace pacman {
namespace controller {

class IMouseEvent;
class IKeyboardEvent;
class ISystemEvent;

/// <summary>
/// <see cref="IEventVisitor" /> defines the visiting part of the Visitor 
/// pattern of the <see cref="IEvent" />. 
///
/// Each new instance of the <see cref="IEvent" /> should have a corresponding
/// Visit function defined within this interface.
/// </summary>
class IEventVisitor {
public:  
	virtual ~IEventVisitor() {}

  /// <summary>
  /// Visit the specified <see cref="MouseEvent" /> pointer.
  /// </summary>
  /// <param name="p_event">
  /// A pointer to a <see cref="MouseEvent />. 
  /// </param>
  virtual void Visit(IMouseEvent* p_event) = 0;

  /// <summary>
  /// Visit the specified <see cref="KeyboardEvent" /> pointer.
  /// </summary>
  /// <param name="p_event"> 
  /// A pointer to a <see cref="KeyboardEvent />.
  /// </param>
	virtual void Visit(IKeyboardEvent* p_event) = 0;

  /// <summary>
  /// Visit the specified <see cref="SystemEvent" /> pointer.
  /// </summary>
  /// <param name="p_event"> 
  /// A pointer to a <see cref="SystemEvent />.
  /// </param>
	virtual void Visit(ISystemEvent* p_event) = 0;
};

}
}
