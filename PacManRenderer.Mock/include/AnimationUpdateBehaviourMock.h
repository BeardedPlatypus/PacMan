#pragma once

#include "entity/animation/IAnimationUpdateBehaviour.h"
#include <gmock/gmock.h>


class AnimationUpdateBehaviourMock : public pacman::renderer::entity::animation::IAnimationUpdateBehaviour {
public:
  MOCK_METHOD(void, Update, (float));
};
