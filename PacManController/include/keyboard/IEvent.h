#pragma once
#define DllExport __declspec( dllexport )

#include <string>


namespace pacman {
namespace controller {
namespace keyboard {
	
/// <summary>
/// <see cref="keyboard::IEvent" /> specifies a single keyboard event, which
/// can be used to register <see cref="ICommand" /> to.
/// </summary>
class DllExport IEvent {
public:  
  /// <summary>
  /// Get the name of this <see cref="IEvent" />.
  /// </summary>
  /// <returns>
  /// The name of this <see cref="keyboard::IEvent" />.
  /// </returns>
  virtual std::string GetName() const = 0;
  
};

}
}
}

/*
/// <summary>
/// Hash Function Object for the <see cref="IEvent" />.
/// </summary>
struct IEventHash {
    std::size_t operator()(IEvent const& e) const noexcept {
        std::size_t h1 = std::hash<std::string>{}(e.GetName());
		return h1;
    }
};

}
}
}

/// <summary>
/// Equality Operator ==
/// </summary>
/// <param name="other">The other.</param>
/// <returns> 
/// <c>true<c> if this is equal to <paramref name="other" /> else <c>false<c> 
/// </returns>
bool operator==(const pacman::controller::keyboard::IEvent& lhs, const pacman::controller::keyboard::IEvent& rhs) {
  return lhs.GetName() == rhs.GetName();
}

*/



