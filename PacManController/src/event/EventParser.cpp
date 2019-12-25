#include "stdafx.h"
#include "event/EventParser.h"


namespace pacman {
namespace controller {

template<class T>
T* EventParser<T>::operator() (const IEvent* p_event) {
  this->SetEvent(nullptr);

  // Accept kicks off the visitor pattern, which will set the internal p_return value
  p_event->Accept(this); 

  T* p_return = this->GetEvent();
  this->SetEvent(nullptr);

  return p_return;
}

template class EventParser<IMouseEvent>;
template class EventParser<IKeyboardEvent>;
template class EventParser<ISystemEvent>;

}
}

