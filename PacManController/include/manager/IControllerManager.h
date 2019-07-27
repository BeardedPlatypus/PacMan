#pragma once

#define DllExport __declspec( dllexport )

#include <memory>


/// <summary>
/// <see cref="IControllerManager" /> provides an interface for external
/// clients to interact with this PacManController. It provides the basic
/// functionality to request and register <see cref="ICommand" />, as well
/// the functionality to call the Update function.
/// </summary>
class DllExport IControllerManager {
public:	
 	/// <summary>
	/// Construct a new <see cref="IControllerManager" />.
	/// </summary>
	/// <returns>
	/// A <see cref="std::unique_ptr" /> containing a new instance of a
	/// <see cref="IControllerManager" />.
	/// </returns>
	static std::unique_ptr<IControllerManager> construct();
};

