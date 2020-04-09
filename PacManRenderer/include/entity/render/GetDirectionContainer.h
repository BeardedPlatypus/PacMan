#pragma once

#include "entity/spatial/Direction.h"
#include <memory>

namespace pacman {
namespace renderer {
namespace entity {
namespace render {
  
/// <summary>
/// <see cref="GetDirectionContainer"/> provides a decoupled GetDirection 
/// </summary>
class GetDirectionContainer final {
public:  
  /// <summary>
  /// Creates a new <see cref="GetDirectionContainer"/> wrapping the provided
  /// <paramref cref="obj"/>.
  /// </summary>
  /// <typeparam name="T">The type of object containing a GetDirection method.</typeparam>
  /// <param name="obj">The object that will be wrapped.</param>
  template <typename T>
  explicit GetDirectionContainer(const T& obj): p_concept(std::make_shared<Model<T>>(std::move(obj))) {}
  
  /// <summary>
  /// Gets the direction.
  /// </summary>
  /// <returns>
  /// The direction.
  /// </returns>
  state::Direction GetDirection() const {
    return this->p_concept->GetDirection();
  }

  /// <summary>
  /// <see cref="Concept"/> provides the GetDirection concept.
  /// </summary>
  struct Concept {
  public:
    virtual ~Concept() = default;
    
    /// <summary>
    /// Gets the <see cref="state::Direction"/>.
    /// </summary>
    /// <returns>
    /// The <see cref="state::Direction"/>.
    /// </returns>
    virtual state::Direction GetDirection() const = 0;
  };

  /// <summary>
  /// <see cref="Model"/> maps the implementation of <typeparamref{T}> to
  /// to the virtual GetDirectionCall of the provided concept, thus achieving
  /// type erasure.
  /// </summary>
  template<typename T>
  struct Model final : Concept {
  public:
    /// <summary>
    /// Creates a new <see cref="Model"/> with the provided <paramref cref="t"/>.
    /// </summary>
    /// <param name="t">The object wrapped.</param>
    explicit Model(const T& t) : object(t) { }
    
    state::Direction GetDirection() const final {
      return object.GetDirection();
    }

  private:
    const T& object;
  };

private:
  std::shared_ptr<const Concept> p_concept;
};

}
}
}
}
