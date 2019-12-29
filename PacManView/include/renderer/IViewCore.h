#pragma once

#include "renderer/IRenderer.h"
#include "renderer/IRendererFactory.h"
#include "sdl_util/IDispatcher.h"

namespace pacman {
namespace view {

/// <summary>
/// <see cref="IViewCore"/> describes the component with all initialisation
/// required to have a functioning PacManView. 
///
/// It provides a method to obtain a <see cref="IRenderer"/> which can be used
/// to render sprites.
/// </summary>
class IViewCore {
public:	
	/// <summary>
	/// Construct  a new instance of a <see cref="IViewManager" />.
	/// </summary>
	/// <returns> 
	/// A <see cref="std::unique_ptr"/> to a new <see cref="IViewCore"/>. 
	/// </returns>
	static std::unique_ptr<IViewCore> Construct(std::unique_ptr<sdl::IDispatcher> p_sdl_dispatcher,
		                                          const IRendererFactory& renderer_factory);
	
	/// <summary>
	/// Finalizes this <see cref="IViewCore"/>.
	/// </summary>
	virtual ~IViewCore() = default;
	
 	/// <summary>
  /// Initialise this <see cref="IViewCore"/>.
	/// </summary>
	/// <param name="screen_width"> Width of the screen. </param>
	/// <param name="screen_height"> Height of the screen. </param>
	virtual void Initialise(int screen_width, int screen_height) = 0;
	
	/// <summary>
	/// Get the <see cref="IRenderer"/> of this <see cref="IViewCore"/>.
	/// </summary>
	/// <returns> 
	/// The <see cref="IRenderer"/> of this <see cref="IViewCore"/>. 
	/// </returns>
	virtual IRenderer& GetRenderer() const = 0;
};


}
}
