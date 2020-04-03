#pragma once

#include <memory>


namespace pacman {
namespace renderer {
namespace entity {
namespace render {

/// <summary>
/// <see cref="IsMovingContainer"/> provides a decoupled IsMoving.
/// </summary>
class IsMovingContainer final {
public:
  /// <summary>
  /// Creates a new <see cref="IsMovingContainer"/> wrapping the provided
  /// <paramref cref="obj"/>.
  /// </summary>
  /// <typeparam name="T">The type of object containing a IsMoving method.</typeparam>
  /// <param name="obj">The object that will be wrapped.</param>
  template <typename T>
  explicit IsMovingContainer(const T& obj) :
      _p_concept(std::make_shared<Model<T>>(std::move(obj))) { }
  
  /// <summary>
  /// Gets whether the wrapped object is moving.
  /// </summary>
  /// <returns>
  /// Whether the warpped object is moving.
  /// </returns>
  bool IsMoving() const {
    return this->_p_concept->IsMoving();
  }
  
  /// <summary>
  /// <see cref="Concept"/> provides the IsMoving concept.
  /// </summary>
  struct Concept {
  public:
    virtual ~Concept() = default;
    
    /// <summary>
    /// Gets whether the entity is moving.
    /// </summary>
    /// <returns>
    /// Whether the entity is moving.
    /// </returns>
    virtual bool IsMoving() const = 0;
  };

  /// <summary>
  /// <see cref="Model"/> maps the implementation of <typeparamref{T}> to
  /// to the virtual IsMoving call of the provided concept, thus achieving
  /// type erasure.
  /// </summary>
  template <typename T>
  struct Model final : Concept {
  public:
    /// <summary>
    /// Creates a new <see cref="Model"/> with the provided <paramref cref="t"/>.
    /// </summary>
    /// <param name="t">The object wrapped.</param>
    explicit Model(const T& t) : _object(t) { }
    
    bool IsMoving() const final {
      return _object.IsMoving();
    }

  private:
    const T& _object;
  };

private:
  std::shared_ptr<const Concept> _p_concept;
};

}
}
}
}
