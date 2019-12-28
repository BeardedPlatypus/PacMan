#pragma once

#include "IEvent.h"


namespace pacman {
namespace controller {

/// <summary>
/// <see cref="IMouseEvent" /> extends the <see cref="IEvent" /> class with 
/// mouse specific information.
/// </summary>
/// <seealso cref="IEvent" />
class IMouseEvent : public IEvent {
public:
	void Accept(IEventVisitor* visitor) override { visitor->Visit(this); }
};


}
}
