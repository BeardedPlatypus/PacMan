#include "stdafx.h"
#include "ui/Button.h"


namespace pacman {
namespace state {

Button::Button(const std::string& id,
			   const std::string& label) : ID(id), 
	                                       Label(label)
{ }

}
}