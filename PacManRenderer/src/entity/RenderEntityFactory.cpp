#include "pch.h"
#include "entity/RenderEntityFactory.h"

#include "entity/RenderEntity.h"
#include "entity/animation/AnimationRenderConfig.h"
#include "entity/animation/SpriteRenderConfig.h"

#include "entity/EntitySpriteValues.h"

#include "entity/animation/ActiveInverseAnimationUpdateBehaviour.h"
#include "entity/render/DirectionBasedValueProvider.h"

#include "entity/EntityStateRenderer.h"
#include "entity/render/AnimationPositionProvider.h"
#include "entity/render/StaticValueProvider.h"
#include "entity/render/IsMovingBasedValueProvider.h"
#include "entity/PacManStateType.h"


namespace pacman {
namespace renderer {
namespace entity {

std::unique_ptr<IRenderEntity> RenderEntityFactory::ConstructPacManRenderEntity(view::IViewAPI* p_view_api,
                                                                                std::unique_ptr<render::GetDirectionContainer> p_direction_container_anim,
                                                                                std::unique_ptr<render::GetDirectionContainer> p_direction_container_rotation,
                                                                                std::unique_ptr<render::GetAxiiContainer> p_axii_container,
                                                                                std::unique_ptr<render::IsMovingContainer> p_is_moving_container) const {
  // Sprites
  std::vector<animation::SpriteRenderConfig> moving_sprites = {
    animation::SpriteRenderConfig(values::pacman_default,
                                  values::entity_sprite_file,
                                  values::entity_tile_size * 1,
                                  values::entity_tile_size * 0,
                                  values::entity_tile_size * 1,
                                  values::entity_tile_size * 1),
    animation::SpriteRenderConfig(values::pacman_moving_anim_0,
                                  values::entity_sprite_file,
                                  values::entity_tile_size * 0,
                                  values::entity_tile_size * 0,
                                  values::entity_tile_size * 1,
                                  values::entity_tile_size * 1),
    animation::SpriteRenderConfig(values::pacman_moving_anim_1,
                                  values::entity_sprite_file,
                                  values::entity_tile_size * 2,
                                  values::entity_tile_size * 0,
                                  values::entity_tile_size * 1,
                                  values::entity_tile_size * 1),
  };

  // Animations
  std::unique_ptr<std::unordered_map<state::Direction, std::string, EnumClassHash>> p_mapping = 
    std::make_unique<std::unordered_map<state::Direction, std::string, EnumClassHash>>();
  p_mapping->insert(std::make_pair(state::Direction::Down, values::pacman_moving_anim));
  p_mapping->insert(std::make_pair(state::Direction::Right, values::pacman_moving_anim));
  p_mapping->insert(std::make_pair(state::Direction::Up, values::pacman_moving_anim_back));
  p_mapping->insert(std::make_pair(state::Direction::Left, values::pacman_moving_anim_back));

  std::shared_ptr<render::IValueProvider<std::string>> p_active_label_provider =
    std::make_shared<render::DirectionBasedValueProvider<std::string>>(std::move(p_direction_container_anim),
                                                                       values::pacman_moving_anim, 
                                                                       std::move(p_mapping));

  std::unique_ptr<std::vector<std::unique_ptr<animation::IAnimationRenderConfig>>> p_anim_configs =
    std::make_unique<std::vector<std::unique_ptr<animation::IAnimationRenderConfig>>>();

  std::vector<std::string> labels_forward = {
    values::pacman_moving_anim_0,
    values::pacman_default,
    values::pacman_moving_anim_1,
    values::pacman_default,
  };


  std::unique_ptr<animation::IAnimationUpdateBehaviour> p_update_behaviour_forward =
    std::make_unique<animation::ActiveInverseAnimationUpdateBehaviour>(p_view_api, 
                                                                       values::pacman_moving_anim,
                                                                       p_active_label_provider);
  p_anim_configs->push_back(std::make_unique<animation::AnimationRenderConfig>(p_view_api, 
                                                                               values::pacman_moving_anim, 
                                                                               0.125F, 
                                                                               labels_forward, 
                                                                               moving_sprites,
                                                                               std::move(p_update_behaviour_forward)));

  std::vector<std::string> labels_backward = {
    values::pacman_default,
    values::pacman_moving_anim_1,
    values::pacman_default,
    values::pacman_moving_anim_0,
  };

  std::unique_ptr<animation::IAnimationUpdateBehaviour> p_update_behaviour_backward =
    std::make_unique<animation::ActiveInverseAnimationUpdateBehaviour>(p_view_api, 
                                                                       values::pacman_moving_anim_back,
                                                                       p_active_label_provider);
  p_anim_configs->push_back(std::make_unique<animation::AnimationRenderConfig>(p_view_api, 
                                                                               values::pacman_moving_anim_back,
                                                                               0.125F, 
                                                                               labels_backward, 
                                                                               moving_sprites,
                                                                               std::move(p_update_behaviour_backward)));

  // Render config
  std::shared_ptr<render::IAnimationPositionProvider> p_position_provider =
    std::make_shared<render::AnimationPositionProvider>(std::move(p_axii_container));
  std::shared_ptr<render::IValueProvider<float>> p_scale_provider = 
    std::make_shared<render::StaticValueProvider<float>>(0.75F);

  std::unique_ptr<std::unordered_map<state::Direction, float, EnumClassHash>> p_mapping_rotation = 
    std::make_unique<std::unordered_map<state::Direction, float, EnumClassHash>>();
  p_mapping_rotation->insert(std::make_pair(state::Direction::Down, 90.F));
  p_mapping_rotation->insert(std::make_pair(state::Direction::Right, 0.F));
  p_mapping_rotation->insert(std::make_pair(state::Direction::Up, 270.F));
  p_mapping_rotation->insert(std::make_pair(state::Direction::Left, 180.F));

  std::shared_ptr<render::IValueProvider<float>> p_rotation_provider=
    std::make_shared<render::DirectionBasedValueProvider<float>>(std::move(p_direction_container_rotation),
                                                                 0.F,
                                                                 std::move(p_mapping_rotation));

  std::shared_ptr<render::IValueProvider<bool>> p_flip_provider =
    std::make_shared<render::StaticValueProvider<bool>>(false);


  std::unique_ptr<render::EntityRenderConfig> p_moving_render_config =
    std::make_unique<render::EntityRenderConfig>(p_active_label_provider,
                                                 p_position_provider,
                                                 p_scale_provider,
                                                 p_rotation_provider,
                                                 p_flip_provider,
                                                 p_flip_provider);

  // Entity renderers
  std::unique_ptr<render::IValueProvider<bool>> p_moving_should_update_provider = 
    std::make_unique<render::IsMovingBasedValueProvider<bool>>(std::move(p_is_moving_container), true, false);

  std::unique_ptr<EntityStateRenderer> moving_renderer = 
    std::make_unique<EntityStateRenderer>(std::move(p_moving_render_config), 
                                          std::move(p_anim_configs), 
                                          std::move(p_moving_should_update_provider),
                                          p_view_api);

  // Entity
  std::unique_ptr<std::unordered_map<state::PacManStateType, std::unique_ptr<IEntityStateRenderer>, EnumClassHash>> p_renderers =
    std::make_unique<std::unordered_map<state::PacManStateType, std::unique_ptr<IEntityStateRenderer>, EnumClassHash >>();
  p_renderers->insert(std::make_pair(state::PacManStateType::Moving, std::move(moving_renderer)));

  std::unique_ptr<render::IValueProvider<state::PacManStateType>> p_state_provider =
    std::make_unique<render::StaticValueProvider<state::PacManStateType>>(state::PacManStateType::Moving);

  std::unique_ptr<IRenderEntity> p_result = std::make_unique<RenderEntity<state::PacManStateType>>(std::move(p_renderers), std::move(p_state_provider));
  return p_result;
}

}
}
}
