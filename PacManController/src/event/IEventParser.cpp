#include "stdafx.h"
#include "event/IEventParser.h"
#include "event/EventParser.h"


namespace pacman {
namespace controller {

template<class T>
std::unique_ptr<IEventParser<T>> IEventParser<T>::construct() {
  return std::make_unique<EventParser<T>>();
}

template class IEventParser<IMouseEvent>;
template class IEventParser<IKeyboardEvent>;
template class IEventParser<ISystemEvent>;

}
}