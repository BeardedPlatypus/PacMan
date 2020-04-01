#pragma once

#include <memory>


namespace pacman {
namespace renderer {
namespace entity {
namespace render {

template <typename TReturn>
class GetStateContainer final {
public:
  template <typename T>
  explicit GetStateContainer(const T& obj) :
      _p_concept(std::make_shared<Model<T>>(std::move(obj))) { }

  TReturn GetState() const {
    return this->_p_concept->GetState();
  }

  struct Concept {
  public:
    virtual ~Concept() = default;
    
    /// <summary>
    /// Gets the <typeparamref cref="TReturn"/> defined by the state.
    /// </summary>
    /// <returns></returns>
    virtual TReturn GetState() const = 0;
  };

  template <typename T>
  struct Model final : Concept {
  public:
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
