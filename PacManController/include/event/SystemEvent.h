#pragma once
#define DllExport __declspec( dllexport )

#include "IEvent.h"


namespace pacman {
namespace controller {

/// <summary>
/// <see cref="SystemEvent" /> extends the <see cref="IEvent" /> class with 
/// system specific information.
/// </summary>
/// <seealso cref="IEvent" />
class DllExport ISystemEvent : public IEvent {
public:
	void Accept(const IEventVisitor& visitor) override { visitor.Visit(this); }
};

}
}
