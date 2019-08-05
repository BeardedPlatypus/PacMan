#pragma once
#define DllExport __declspec( dllexport )

#include "IEvent.h"

namespace pacman {
namespace controller {

/// <summary>
/// <see cref="IKeyboardEvent" /> extends the <see cref="IEvent" class with 
/// keyboard specific information.
/// </summary>
/// <seealso cref="IEvent" />
class DllExport IKeyboardEvent : public IEvent {
public:
	virtual ~IKeyboardEvent() {}

	void Accept(IEventVisitor* visitor) override { visitor->Visit(this); }
};


}
}
