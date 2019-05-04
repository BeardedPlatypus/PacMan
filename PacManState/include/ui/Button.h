#pragma once

#include <string>


namespace pacman {
namespace state {

/// <summary>
/// state::Button describes a single Button within the pacman ui.
/// </summary>
class Button {
public:	
	/// <summary>
	/// Construct a new instance of the <see cref="Button" /> class.
	/// </summary>
	/// <param name="id"> The identifier. </param>
	/// <param name="label"> The label. </param>
	Button(const std::string& id,
		   const std::string& label);
	
	/// <summary>
	/// The identifier of this Button.
	/// </summary>
	const std::string ID;
	
	/// <summary>
	/// The label of this Button.
	/// </summary>
	const std::string Label;
};

} // state
} // pacman
