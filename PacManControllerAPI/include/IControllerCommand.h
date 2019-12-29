#pragma once
#define DllExport __declspec( dllexport )


namespace pacman {
namespace controller {
namespace api {
	
/// <summary>
/// <see cref="IControllerCommand"/> defines the interface of commands which
/// can be registered within the <see cref="IControllerAPI"/>.
/// </summary>
class DllExport IControllerCommand {
public:	
	/// <summary>
	/// Finalise this <see cref="IControllerCommand"/>.
	/// </summary>
	virtual ~IControllerCommand() = default;

	/// <summary>
	/// Execute the logic associated with this <see cref="ICommand"/>.
	/// <summary>
	virtual void Execute() = 0;
};

}
}
}
