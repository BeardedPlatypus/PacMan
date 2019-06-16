#include "stdafx.h"
#include "renderer/IViewCore.h"

#include "renderer/ViewCore.h"

namespace pacman {
namespace view {

std::unique_ptr<IViewCore> IViewCore::construct() {
	return std::make_unique<ViewCore>();
}

}
}