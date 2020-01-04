#pragma once


namespace pacman {
namespace update {
namespace object {

class IObjectBehaviour {
public:
  virtual ~IObjectBehaviour() = default;

  virtual void Execute(int x, int y) = 0;
};

}
}
}
