#include "stdafx.h"
#include "renderer/IViewCore.h"

#include "renderer/ViewCore.h"

namespace pacman {
namespace view {

std::unique_ptr<IViewCore> IViewCore::Construct() {
	return std::make_unique<ViewCore>();
}

}
}