#pragma once
#define DllExport __declspec( dllexport )

#include "IEvent.h"


namespace pacman {
namespace controller {

/// <summary>
/// <see cref="IMouseEvent" /> extends the <see cref="IEvent" /> class with 
/// mouse specific information.
/// </summary>
/// <seealso cref="IEvent" />
class DllExport IMouseEvent : public IEvent {
public:
	virtual ~IMouseEvent() {}

	void Accept(IEventVisitor* visitor) override { visitor->Visit(this); }
};

}
}
