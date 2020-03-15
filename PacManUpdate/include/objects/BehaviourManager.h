#pragma once

#include "field/object/IFieldObjectManager.h"
#include "objects/behaviours/IObjectBehaviour.h"
#include "entity/IUpdatablePlayerEntity.h"
#include "score/IScoreBoard.h"
#include "level/ILevelManager.h"

#include <memory>
#include <typeindex>
#include <unordered_map>
#include <vector>


namespace pacman {
namespace update {
namespace object {
	
/// <summary>
/// <see cref="BehaviourManager"/> provides the implementation to manage
/// the different behaviours that are associated with the
/// <see cref="state::field::FieldObjectType"/>s
/// </summary>
class BehaviourManager {
public:	
  /// <summary>
  /// Creates a new <see cref="BehaviourManager"/>.
  /// </summary>
  BehaviourManager();
	
  /// <summary>
   /// Initialises this <see cref="BehaviourManager" /> with the provided
  /// <paramref name="p_field" /> and <paramref name="p_field_object_manager" />.
  /// </summary>
  /// <param name="p_field">Pointer to the <see cref="state::field::IField" />.</param>
  /// <param name="p_field_object_manager">Pointer to the <see cref="state::field::IFieldObjectManager" />.</param>
  /// <param name="p_score_board">Pointer to the <see cref="state::score::IScoreBoard"/>.</param>
  /// <param name="p_level_manager">Pointer to the <see cref="state::level::ILevelManager"/>.</param>
  void Initialise(const state::field::IField* p_field,
                  state::field::IFieldObjectManager* p_field_object_manager,
                  state::score::IScoreBoard* p_score_board,
                  state::level::ILevelManager* p_level_manager);
	
  /// <summary>
  /// Executes the behaviour for the provided <paramref name="p_entity"/>
  /// at its current location.
  /// </summary>
  /// <param name="p_entity">The entity to be changed.</param>
  void ExecuteBehaviourFor(IUpdatablePlayerEntity* p_entity);

private:
  void InitialiseBehaviours();
  void InitialisePortalBehaviour();
  void InitialiseBehaviourMapping();
  void InitialiseObjectBehaviour();

  const state::field::IField* _p_field;
  state::field::IFieldObjectManager* _p_field_object_manager;
  state::score::IScoreBoard* _p_score_board;
  state::level::ILevelManager* _p_level_manager;

  std::unordered_map<std::type_index, std::unique_ptr<IObjectBehaviour>> _object_behaviours = 
    std::unordered_map<std::type_index, std::unique_ptr<IObjectBehaviour>>();

  std::unordered_map<state::field::FieldObjectType,
                     std::vector<IObjectBehaviour*>> _behaviour_mapping =
    std::unordered_map<state::field::FieldObjectType,
                       std::vector<IObjectBehaviour*>>();
};

}
}
}
