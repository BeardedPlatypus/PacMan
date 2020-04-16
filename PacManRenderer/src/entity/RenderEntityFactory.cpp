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
#include "entity/player/PacManStateType.h"

#include "entity/animation/PacManSpriteConfigRepository.h"
#include "entity/animation/PacManAnimationConfigRepository.h"
#include "entity/animation/GhostSpriteConfigRepository.h"
#include "entity/animation/GhostAnimationConfigRepository.h"

#include "entity/render/StateBasedValueProvider.h"
#include "entity/render/GetStateContainer.h"

#include "entity/render/GetAxiiContainer.h"
#include "entity/render/GetDirectionContainer.h"
#include "entity/render/IsMovingContainer.h"

namespace pacman {
namespace renderer {
namespace entity {

std::shared_ptr<render::IValueProvider<std::string>> GetPacManActiveLabelProvider(
    std::shared_ptr<render::GetDirectionContainer> p_direction_container) {
  std::unique_ptr<std::unordered_map<state::Direction, std::string, EnumClassHash>> p_mapping = 
    std::make_unique<std::unordered_map<state::Direction, std::string, EnumClassHash>>();

  p_mapping->insert(std::make_pair(state::Direction::Down,  values::pacman_moving_anim));
  p_mapping->insert(std::make_pair(state::Direction::Right, values::pacman_moving_anim));
  p_mapping->insert(std::make_pair(state::Direction::Up,    values::pacman_moving_anim_back));
  p_mapping->insert(std::make_pair(state::Direction::Left,  values::pacman_moving_anim_back));

  return std::make_shared<render::DirectionBasedValueProvider<std::string>>(std::move(p_direction_container),
                                                                            values::pacman_moving_anim, 
                                                                            std::move(p_mapping));
}


std::unique_ptr<std::vector<std::unique_ptr<animation::IAnimationRenderConfig>>> GetPacManAnimConfigs(
    view::IViewAPI* p_view_api,
    std::shared_ptr<render::IValueProvider<std::string>> p_active_label_provider) {
  auto sprite_repository = animation::PacManSpriteConfigRepository();
  auto anim_repository = animation::PacManAnimationConfigRepository();


  std::unique_ptr<std::vector<std::unique_ptr<animation::IAnimationRenderConfig>>> p_anim_configs =
    std::make_unique<std::vector<std::unique_ptr<animation::IAnimationRenderConfig>>>();

  p_anim_configs->push_back(
    anim_repository.ConstructForwardMovingAnimation(p_view_api,
                                                   values::pacman_moving_anim, 
                                                   sprite_repository, 
                                                   p_active_label_provider));

  p_anim_configs->push_back(
    anim_repository.ConstructBackwardMovingAnimation(p_view_api,
                                                     values::pacman_moving_anim_back, 
                                                     sprite_repository, 
                                                     p_active_label_provider));

  return p_anim_configs;
}


std::unique_ptr<render::EntityRenderConfig> GetPacManMovingRenderer(
    std::unique_ptr<render::GetAxiiContainer> p_axii_container,
    std::shared_ptr<render::GetDirectionContainer> p_direction_container,
    std::shared_ptr<render::IValueProvider<std::string>> p_active_label_provider) {
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
    std::make_shared<render::DirectionBasedValueProvider<float>>(std::move(p_direction_container),
                                                                 0.F,
                                                                 std::move(p_mapping_rotation));

  std::shared_ptr<render::IValueProvider<bool>> p_flip_provider =
    std::make_shared<render::StaticValueProvider<bool>>(false);

  return std::make_unique<render::EntityRenderConfig>(p_active_label_provider,
                                                      p_position_provider,
                                                      p_scale_provider,
                                                      p_rotation_provider,
                                                      p_flip_provider,
                                                      p_flip_provider);
}


std::unique_ptr<IRenderEntity> RenderEntityFactory::ConstructPacManRenderEntity(view::IViewAPI* p_view_api,
                                                                                const state::IEntityState<state::IPacManBehaviourState>* p_entity_state) const {
  // Animations
  auto p_direction_container = std::make_shared<render::GetDirectionContainer>(*(p_entity_state->GetSpatialState()));
  auto p_axii_container = std::make_unique<render::GetAxiiContainer>(*(p_entity_state->GetSpatialState()));
  auto p_is_moving_container = std::make_unique<render::IsMovingContainer>(*(p_entity_state->GetSpatialState()));
  auto p_get_state_container = std::make_shared<render::GetStateContainer<state::PacManStateType>>(*(p_entity_state->GetBehaviouralState()));

  std::shared_ptr<render::IValueProvider<std::string>> p_active_label_provider =
    GetPacManActiveLabelProvider(p_direction_container);


  // Entity renderers
  std::unique_ptr<render::EntityRenderConfig> p_moving_render_config =
    GetPacManMovingRenderer(std::move(p_axii_container),
                            p_direction_container,
                            p_active_label_provider);

  std::unique_ptr<std::vector<std::unique_ptr<animation::IAnimationRenderConfig>>> p_anim_configs =
    GetPacManAnimConfigs(p_view_api, p_active_label_provider);

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

  auto p_state_mapping =
    std::make_unique<std::unordered_map<state::PacManStateType, state::PacManStateType, EnumClassHash>>();
  p_state_mapping->insert(std::make_pair(state::PacManStateType::Moving, state::PacManStateType::Moving));
  p_state_mapping->insert(std::make_pair(state::PacManStateType::Dying, state::PacManStateType::Dying));

  std::unique_ptr<render::IValueProvider<state::PacManStateType>> p_state_provider =
    std::make_unique<render::StateBasedValueProvider<state::PacManStateType, state::PacManStateType>>(p_get_state_container, 
                                                                                                      state::PacManStateType::Moving,
                                                                                                      std::move(p_state_mapping));

  std::unique_ptr<IRenderEntity> p_result = std::make_unique<RenderEntity<state::PacManStateType>>(std::move(p_renderers), std::move(p_state_provider));
  return p_result;
}


std::shared_ptr<render::IValueProvider<std::string>> GetGhostActiveLabelProvider(
    std::shared_ptr<render::GetDirectionContainer> p_direction_container,
    const std::string& ghost_name_prefix) {
  std::unique_ptr<std::unordered_map<state::Direction, std::string, EnumClassHash>> p_mapping = 
    std::make_unique<std::unordered_map<state::Direction, std::string, EnumClassHash>>();

  p_mapping->insert(std::make_pair(state::Direction::Down,  ghost_name_prefix + values::ghost_moving_down_anim));
  p_mapping->insert(std::make_pair(state::Direction::Right, ghost_name_prefix + values::ghost_moving_horizontal_anim));
  p_mapping->insert(std::make_pair(state::Direction::Up,    ghost_name_prefix + values::ghost_moving_up_anim));
  p_mapping->insert(std::make_pair(state::Direction::Left,  ghost_name_prefix + values::ghost_moving_horizontal_anim));

  return std::make_shared<render::DirectionBasedValueProvider<std::string>>(std::move(p_direction_container),
                                                                            ghost_name_prefix + values::ghost_moving_horizontal_anim, 
                                                                            std::move(p_mapping));
}


std::unique_ptr<render::EntityRenderConfig> GetGhostMovingRenderer(
    std::unique_ptr<render::GetAxiiContainer> p_axii_container,
    std::shared_ptr<render::GetDirectionContainer> p_direction_container,
    std::shared_ptr<render::IValueProvider<std::string>> p_active_label_provider) {
  std::shared_ptr<render::IAnimationPositionProvider> p_position_provider =
    std::make_shared<render::AnimationPositionProvider>(std::move(p_axii_container));
  std::shared_ptr<render::IValueProvider<float>> p_scale_provider = 
    std::make_shared<render::StaticValueProvider<float>>(0.7F);

  std::shared_ptr<render::IValueProvider<float>> p_rotation_provider =
    std::make_shared<render::StaticValueProvider<float>>(0.F);

  std::unique_ptr<std::unordered_map<state::Direction, bool, EnumClassHash>> p_mapping_flipping_horizontal = 
    std::make_unique<std::unordered_map<state::Direction, bool, EnumClassHash>>();
  p_mapping_flipping_horizontal->insert(std::make_pair(state::Direction::Left, true));

  std::shared_ptr<render::IValueProvider<bool>> p_flip_provider_horizontal =
    std::make_shared<render::DirectionBasedValueProvider<bool>>(std::move(p_direction_container), 
                                                                false,
                                                                std::move(p_mapping_flipping_horizontal));

  std::shared_ptr<render::IValueProvider<bool>> p_flip_provider_vertical =
    std::make_shared<render::StaticValueProvider<bool>>(false);


  return std::make_unique<render::EntityRenderConfig>(p_active_label_provider,
                                                      p_position_provider,
                                                      p_scale_provider,
                                                      p_rotation_provider,
                                                      p_flip_provider_horizontal,
                                                      p_flip_provider_vertical);
}


std::unique_ptr<std::vector<std::unique_ptr<animation::IAnimationRenderConfig>>> GetGhostAnimConfigs(
    view::IViewAPI* p_view_api,
    const std::string& ghost_name_prefix,
    state::GhostEntityType ghost_type) {
  auto sprite_repository = animation::GhostSpriteConfigRepository();
  auto anim_repository = animation::GhostAnimationConfigRepository();


  std::unique_ptr<std::vector<std::unique_ptr<animation::IAnimationRenderConfig>>> p_anim_configs =
    std::make_unique<std::vector<std::unique_ptr<animation::IAnimationRenderConfig>>>();

  p_anim_configs->push_back(
    anim_repository.ConstructMovingHorizontalAnimation(p_view_api,
                                                       ghost_name_prefix + values::ghost_moving_horizontal_anim,
                                                       ghost_type,
                                                       sprite_repository));
  p_anim_configs->push_back(
    anim_repository.ConstructMovingUpAnimation(p_view_api,
                                               ghost_name_prefix + values::ghost_moving_up_anim,
                                               ghost_type,
                                               sprite_repository));
  p_anim_configs->push_back(
    anim_repository.ConstructMovingDownAnimation(p_view_api,
                                                 ghost_name_prefix + values::ghost_moving_down_anim,
                                                 ghost_type,
                                                 sprite_repository));

  return p_anim_configs;
}


std::unique_ptr<IRenderEntity> RenderEntityFactory::ConstructGhostRenderEntity(view::IViewAPI* p_view_api,
                                                                               state::GhostEntityType ghost_type,
                                                                               const state::IEntityState<state::IGhostBehaviourState>* p_entity_state) const {
  std::string ghost_type_prefix = state::GetGhostName(ghost_type) + "_";

  // Animations
  auto p_direction_container = std::make_shared<render::GetDirectionContainer>(*(p_entity_state->GetSpatialState()));
  auto p_axii_container = std::make_unique<render::GetAxiiContainer>(*(p_entity_state->GetSpatialState()));
  auto p_is_moving_container = std::make_unique<render::IsMovingContainer>(*(p_entity_state->GetSpatialState()));
  auto p_get_state_container = std::make_shared<render::GetStateContainer<state::GhostStateType>>(*(p_entity_state->GetBehaviouralState()));

  std::shared_ptr<render::IValueProvider<std::string>> p_active_label_provider =
    GetGhostActiveLabelProvider(p_direction_container, ghost_type_prefix);

  // Entity renderers
  std::unique_ptr<render::EntityRenderConfig> p_moving_render_config =
    GetGhostMovingRenderer(std::move(p_axii_container),
                           p_direction_container,
                           p_active_label_provider);

  std::unique_ptr<std::vector<std::unique_ptr<animation::IAnimationRenderConfig>>> p_anim_configs =
    GetGhostAnimConfigs(p_view_api, ghost_type_prefix, ghost_type);

  std::unique_ptr<render::IValueProvider<bool>> p_moving_should_update_provider = 
    std::make_unique<render::IsMovingBasedValueProvider<bool>>(std::move(p_is_moving_container), true, false);

  std::unique_ptr<EntityStateRenderer> moving_renderer = 
    std::make_unique<EntityStateRenderer>(std::move(p_moving_render_config), 
                                          std::move(p_anim_configs), 
                                          std::move(p_moving_should_update_provider),
                                          p_view_api);

  // Entity
  std::unique_ptr<std::unordered_map<state::GhostStateType, std::unique_ptr<IEntityStateRenderer>, EnumClassHash>> p_renderers =
    std::make_unique<std::unordered_map<state::GhostStateType, std::unique_ptr<IEntityStateRenderer>, EnumClassHash >>();
  p_renderers->insert(std::make_pair(state::GhostStateType::Alive, std::move(moving_renderer)));

  auto p_state_mapping =
    std::make_unique<std::unordered_map<state::GhostStateType, state::GhostStateType, EnumClassHash>>();
  p_state_mapping->insert(std::make_pair(state::GhostStateType::Eaten, state::GhostStateType::Eaten));
  p_state_mapping->insert(std::make_pair(state::GhostStateType::Edible, state::GhostStateType::Edible));
  p_state_mapping->insert(std::make_pair(state::GhostStateType::Alive, state::GhostStateType::Alive));

  std::unique_ptr<render::IValueProvider<state::GhostStateType>> p_state_provider =
    std::make_unique<render::StateBasedValueProvider<state::GhostStateType, state::GhostStateType>>(p_get_state_container, 
                                                                                                    state::GhostStateType::Alive,
                                                                                                    std::move(p_state_mapping));

  std::unique_ptr<IRenderEntity> p_result = std::make_unique<RenderEntity<state::GhostStateType>>(std::move(p_renderers), std::move(p_state_provider));
  return p_result;
}

}
}
}
