#include "pch.h"
#include "manager/LayerManagerFactory.h"
#include "manager/LayerManager.h"

#include "entity/PlayerLayer.h"
#include "field/FieldLayer.h"
#include "objects/ObjectLayer.h"
#include "ui/UILayerFactory.h"

#include "entity/EntityLayer.h"
#include "entity/RenderEntityFactory.h"

#include "objects/ObjectRenderers/SmallDotRenderer.h"
#include "objects/ObjectRenderers/BigDotRenderer.h"
#include "objects/ObjectRenderers/BonusFruitRenderer.h"
#include "ui/font/GlyphRenderer.h"
#include "ui/font/StringRenderer.h"

#include "level/ILevelManager.h"

namespace pacman {
namespace renderer {


std::unique_ptr<ObjectLayer> ConstructObjectLayer(float scale,
                                                  view::IViewAPI* p_view_api,
                                                  state::field::IFieldObjectManager* p_object_manager,
                                                  state::level::ILevelManager* p_level_manager) {
  std::unique_ptr<RenderMapping> p_mapping = std::make_unique<RenderMapping>();

  p_mapping->emplace(std::make_pair(state::field::FieldObjectType::SmallDot,
                                    std::make_unique<objects::SmallDotRenderer>(p_view_api)));
  p_mapping->emplace(std::make_pair(state::field::FieldObjectType::BigDot,
                                    std::make_unique<objects::BigDotRenderer>(p_view_api)));
  p_mapping->emplace(std::make_pair(state::field::FieldObjectType::BonusFruit,
                                    std::make_unique<objects::BonusFruitRenderer>(p_view_api, p_level_manager)));

  return std::make_unique<ObjectLayer>(scale, 
                                       p_object_manager, 
                                       std::move(p_mapping),
                                       20.F);
}


std::unique_ptr<EntityLayer> ConstructEntityLayer(float scale,
                                                  view::IViewAPI* p_view_api,
                                                  const state::IGameState* p_game_state) {
  auto factory = entity::RenderEntityFactory();
  
  std::unique_ptr<std::vector<std::unique_ptr<entity::IRenderEntity>>> p_entities =
    std::make_unique<std::vector<std::unique_ptr<entity::IRenderEntity>>>();

  p_entities->push_back(factory.ConstructPacManRenderEntity(p_view_api,
                                                            std::make_unique<entity::render::GetDirectionContainer>(*p_game_state->GetPlayerState()),
                                                            std::make_unique<entity::render::GetDirectionContainer>(*p_game_state->GetPlayerState()),
                                                            std::make_unique<entity::render::GetAxiiContainer>(*p_game_state->GetPlayerState()),
                                                            std::make_unique<entity::render::IsMovingContainer>(*p_game_state->GetPlayerState())));

  return std::make_unique<EntityLayer>(std::move(p_entities), scale, 20.F);
}


std::unique_ptr<ILayerManager> ConstructLayerManager(view::IViewAPI* p_view_api,
                                                     const state::IGameState* p_game_state) {
  auto p_field_layer = std::make_unique<FieldLayer>(4.F,
                                                    p_view_api,
                                                    p_game_state->GetField(),
                                                    20.F);

  auto p_object_layer = ConstructObjectLayer(4.F,
                                             p_view_api,
                                             p_game_state->GetFieldObjectManager(),
                                             p_game_state->GetLevelManager());

  auto p_entity_layer = ConstructEntityLayer(4.F, p_view_api, p_game_state);
  auto p_ui_layer = ConstructUILayer(p_game_state->GetScoreBoard(), 4.F, p_view_api, 0.F);

  std::vector<std::unique_ptr<IRenderLayer>> render_layers = {};
  render_layers.push_back(std::move(p_field_layer));
  render_layers.push_back(std::move(p_object_layer));
  render_layers.push_back(std::move(p_entity_layer));
  render_layers.push_back(std::move(p_ui_layer));

  return std::make_unique<LayerManager>(render_layers);
}

}
}
