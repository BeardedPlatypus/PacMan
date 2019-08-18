#include "stdafx.h"
#include "field/IField.h"
#include "field/Field.h"


namespace pacman {
namespace state {
namespace field {

std::unique_ptr<IField> IField::Construct(const std::vector<std::vector<TileType>>& tiles) {
  return std::make_unique<Field>(tiles);
}

}
}
}