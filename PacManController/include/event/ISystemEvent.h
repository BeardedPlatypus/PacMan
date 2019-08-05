#pragma once
#define DllExport __declspec( dllexport )

#include "IEvent.h"


namespace pacman {
namespace controller {

/// <summary>
/// <see cref="ISystemEvent" /> extends the <see cref="IEvent" /> class with 
/// system specific information.
/// </summary>
/// <seealso cref="IEvent" />
class DllExport ISystemEvent : public IEvent {
public:
	virtual ~ISystemEvent() {}

	void Accept(IEventVisitor* visitor) override { visitor->Visit(this); }
};

}
}
