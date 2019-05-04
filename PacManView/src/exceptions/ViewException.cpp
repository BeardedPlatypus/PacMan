#include "stdafx.h"
#include "exceptions/ViewException.h"

namespace pacman {
namespace view {

ViewException::ViewException(const std::string& what_arg,
							 const std::string& SDL_error) :
	std::runtime_error(what_arg),
	SDL_error(SDL_error) { }


} // view
} // pacman

