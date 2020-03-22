#pragma once

#include "entity/Direction.h"
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
  template <typename T>
  GetDirectionContainer(const T& obj): p_concept(std::make_shared<Model<T>>(std::move(obj))) {}

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
  struct Model : Concept {
  public:
    /// <summary>
    /// Creates a new <see cref="Model"/> with the provided <paramref cref="t"/>.
    /// </summary>
    /// <param name="t">The object wrapped.</param>
    Model(const T& t) : object(t) { }

    state::Direction GetDirection() const override {
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
