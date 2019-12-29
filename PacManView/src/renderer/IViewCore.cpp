#include "stdafx.h"
#include "renderer/IViewCore.h"

#include "renderer/ViewCore.h"

namespace pacman {
namespace view {

std::unique_ptr<IViewCore> IViewCore::Construct(std::unique_ptr<sdl::IDispatcher> p_sdl_dispatcher,
		                                            const IRendererFactory& renderer_factory) {
	return std::make_unique<ViewCore>(std::move(p_sdl_dispatcher),
		                                renderer_factory);
}

}
}