#pragma once

#include "entity/render/IAnimationPositionProvider.h"
#include <gmock/gmock.h>

class AnimationPositionProviderMock : public pacman::renderer::entity::render::IAnimationPositionProvider {
public:
  MOCK_METHOD(float, GetXPosition, (float), (const));
  MOCK_METHOD(float, GetYPosition, (float, float), (const));
};
