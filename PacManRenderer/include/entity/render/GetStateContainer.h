#pragma once

#include <memory>


namespace pacman {
namespace renderer {
namespace entity {
namespace render {

/// <summary>
/// <see cref="GetStateContainer"/> provides a decoupled GetState.
/// </summary>
/// <typeparam name="TReturn">The return type of GetState.</typeparam>
template <typename TReturn>
class GetStateContainer final {
public:
  /// <summary>
  /// Creates a new <see cref="GetStateContainer"/> wrapping the provided
  /// <paramref cref="obj"/>.
  /// </summary>
  /// <typeparam name="T">The type of object containing a GetState method.</typeparam>
  /// <param name="obj">The object that will be wrapped.</param>
  template <typename T>
  explicit GetStateContainer(const T& obj) :
      _p_concept(std::make_shared<Model<T>>(std::move(obj))) { }
  
  /// <summary>
  /// Gets the <typeparamref cref="TReturn"/> state.
  /// </summary>
  /// <returns>
  /// The <typeparamref cref="TReturn"/> state.
  /// </returns>
  TReturn GetState() const {
    return this->_p_concept->GetState();
  }
  
  /// <summary>
  /// <see cref="Concept"/> provides the GetState concept.
  /// </summary>
  struct Concept {
  public:
    virtual ~Concept() = default;
    
    /// <summary>
    /// Gets the <typeparamref cref="TReturn"/> defined by the state.
    /// </summary>
    /// <returns>
    /// The <typeparamref cref="TReturn"/> state.
    /// </returns>
    virtual TReturn GetState() const = 0;
  };

  /// <summary>
  /// <see cref="Model"/> maps the implementation of <typeparamref{T}> to
  /// to the virtual GetState call of the provided concept, thus achieving
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
    
    TReturn GetState() const final {
      return _object.GetState();
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
