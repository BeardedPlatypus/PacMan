#pragma once

#include "IEventParser.h"
#include "IMouseEvent.h"
#include "IKeyboardEvent.h"
#include "ISystemEvent.h"


namespace pacman {
namespace controller {

/// <summary>
/// <see cref="EventParser /> can be used to obtain a pointer to the IEvent of
/// type T, if the provided <see cref="IEvent" /> corresponds with type T, or a
/// nullptr otherwise. It does so by implementing the Visitor patter through
/// <see cref=IEventVisitor>.
/// </summary>
/// <seealso cref="IEventVisitor" />
template<class T>
class EventParser final : public IEventParser<T>, public IEventVisitor  {
public:  
  /// <summary>
  /// Construct a new <see cref="EventParser"/>.
  /// </summary>
  EventParser() { }

  void Visit(IMouseEvent*    p_event) override { this->Visit<IMouseEvent>(p_event);    };
  void Visit(IKeyboardEvent* p_event) override { this->Visit<IKeyboardEvent>(p_event); };
  void Visit(ISystemEvent*   p_event) override { this->Visit<ISystemEvent>(p_event);   };
  
  T* operator() (const IEvent* p_event) override; 

private:
  /// <summary>
  /// If U is equal to T, then set the pointer of this 
  /// <see cref="EventParser" /> to <paramref name="p_event" />,
  /// else set the pointer to <c>nullptr</c>.
  /// </summary>
  /// <param name="p_event"> 
  /// A pointer to the visiting <see cref="p_event" />.
  /// </param>
  template<class U>
  inline void Visit(U* p_event) {
    if constexpr (std::is_same<T, U>::value)
      this->SetEvent(p_event);
    else
      this->SetEvent(nullptr);
  }

  /// <summary>
  /// Get a pointer to the <see cref="IEvent" />.
  /// </summary>
  /// <returns>
  /// Pointer to the <see cref="IEvent" /> of this <see cref="EventParser" />.
  /// </returns>
  inline T* GetEvent() const { return this->p_event; }
  
  /// <summary>
  /// Set the pointer to the <see cref="IEvent" />.
  /// </summary>
  /// <param name="p_event">The pointer to the <see cref="IEvent" />. </param>
  /// <post-condition> 
  /// (new this)->GetEvent() == p_event; 
  /// </post-condition>
  inline void SetEvent(T* p_event) { this->p_event = p_event; }
  
  /// <summary> The pointer to the <see cref="IEvent" />. </summary>
  T* p_event;
};

}
}
