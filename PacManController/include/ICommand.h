#pragma once

namespace pacman {
namespace controller {

/// <summary>
/// ICommand interface defines the interface with which Commands
/// for the controller can be defined. It provides a single Execute
/// command which will be executed when the event it was registered 
/// to is triggered.
/// </summary>
class ICommand {
public:
	virtual ~ICommand() = default;

	/// <summary>
	/// Execute the logic associated with this <see cref="ICommand"/>.
	/// <summary>
	virtual void Execute() = 0;
};

}
}
