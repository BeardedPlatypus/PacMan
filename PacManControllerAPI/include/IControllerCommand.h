#pragma once
#define DllExport __declspec( dllexport )


namespace pacman {
namespace controller {
namespace api {

class DllExport IControllerCommand {
public:
	virtual ~IControllerCommand() = default;

	/// <summary>
	/// Execute the logic associated with this <see cref="ICommand"/>.
	/// <summary>
	virtual void Execute() = 0;
};

}
}
}
