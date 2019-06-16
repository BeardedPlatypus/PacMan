#pragma once

#include "renderer/IRenderer.h"

namespace pacman {
namespace view {

/// <summary>
/// <see cref="IViewCore" /> describes the component with all initialisation
/// required to have a functioning PacManView. 
///
/// It provides a method to obtain a <see cref="IRenderer" /> which can be used
/// to render sprites.
/// </summary>
class IViewCore {
public:	
	/// <summary>
	/// Construct  a new instance of a <see cref="IViewManager>.
	/// </summary>
	/// <returns> A <see cref="std::unique_ptr" /> to a new <see cref="IViewCore />. 
	/// </returns>
	static std::unique_ptr<IViewCore> construct();
	
	/// <summary>
	/// Initialise this <see cref="IViewCore" />.
	/// </summary>
	virtual void initialise() = 0;
	
	/// <summary>
	/// Get the <see cref="IRenderer" /> of this <see cref="IViewCore" />.
	/// </summary>
	/// <returns> The <see cref="IRenderer" /> of this <see cref="IViewCore" />. 
	/// </returns>
	virtual IRenderer& getRenderer() const = 0;
};


}
}
