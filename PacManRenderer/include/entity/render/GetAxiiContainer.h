#pragma once

#include "entity/IEntityAxis.h"
#include <memory>

namespace pacman {
namespace renderer {
namespace entity {
namespace render {
  
/// <summary>
/// <see cref="GetAxiiContainer"/> provides a decoupled GetXAxis and GetYAxis
/// </summary>
class GetAxiiContainer final {
public:  
  template <typename T>
  explicit GetAxiiContainer(const T& obj): p_concept(std::make_shared<Model<T>>(std::move(obj))) {}

  const state::IEntityAxis* GetXAxis() const {
    return this->p_concept->GetXAxis();
  }

  const state::IEntityAxis* GetYAxis() const {
    return this->p_concept->GetYAxis();
  }

  /// <summary>
  /// <see cref="Concept"/> provides the GetXAxis and GetYAxis concept.
  /// </summary>
  struct Concept {
  public:
    virtual ~Concept() = default;
        
    /// <summary>
    /// Gets the x-axis.
    /// </summary>
    /// <returns>
    /// The x-axis.
    /// </returns>
    virtual state::IEntityAxis* GetXAxis() const = 0;
    
    /// <summary>
    /// Gets the y-axis.
    /// </summary>
    /// <returns>
    /// The y-axis.
    /// </returns>
    virtual state::IEntityAxis* GetYAxis() const = 0;
  };

  /// <summary>
  /// <see cref="Model"/> maps the implementation of <typeparamref{T}> to
  /// to the virtual GetAxis calls of the provided concept, thus achieving
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

    state::IEntityAxis* GetXAxis() const final {
      return object.GetXAxis();
    }

    state::IEntityAxis* GetYAxis() const final {
      return object.GetYAxis();
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
