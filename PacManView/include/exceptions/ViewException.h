#pragma once

#include <stdexcept>

namespace pacman {
namespace view {

/// <summary>
/// The Exception used within the <see cref="PacManView"/> to report any 
/// exceptions.
/// </summary>
/// <seealso cref="std::runtime_error" />
class ViewException : public std::runtime_error {
public:	
	/// <summary>
	/// Construct a new instance of the <see cref="ViewException"/> class.
	/// </summary>
	/// <param name="what_arg">The what argument.</param>
	/// <param name="SDL_error">The SDL error.</param>
	ViewException(const std::string& what_arg,
				        const std::string& SDL_error);
	
	/// <summary> The SDL error of this ViewException. </summary>
	const std::string SDL_error;
};

} // view
} // pacman
