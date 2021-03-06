#pragma once
#define DllExport __declspec( dllexport )

#include <memory>

#include "entity/IEntityManager.h"
#include "GameMode.h"
#include "field/Field.h"
#include "field/object/FieldObjectType.h"
#include "field/object/IFieldObjectManager.h"
#include "score/IScoreBoard.h"
#include "level/ILevelManager.h"

namespace pacman {
  namespace state {
    /// <summary>
    /// The <see cref="IGameState" /> defines the state of the game.
    /// It acts as a collection of sub units with which other components
    /// can interact.
    /// </summary>
    class DllExport IGameState {
    public:            
      /// <summary>
      /// Construct a new <see cref="std::unique_ptr"/> containing an instance
      /// of a <see cref="IGameState" />.
      /// </summary>
      /// <returns>
      /// A <see cref="std::unique_ptr" /> containing an instance of a <see cref="IGameState" />.
      /// </returns>
      static std::unique_ptr<IGameState> Construct();

      ~IGameState() {}

      /// <summary>
      /// Get the game mode of this <see cref="IGameState" />.
      /// </summary>
      /// <returns> The game mode of this <see cref="IGameState" />. </returns>
      virtual GameMode GetGameMode() const = 0;

      /// <summary>
      /// Set the game mode of this <see cref="IGameState" />.
      /// </summary>
      /// <post-condition>	
      /// (new this)->GetGameMode() == <paramref name="game_mode" />
      /// </post-condition>	
      virtual void SetGameMode(GameMode game_mode) = 0;
      
      /// <summary>
      /// Get the field of this <see cref="IGameState" />.
      /// </summary>
      /// <returns>
      /// A pointer to the <see cref="IField" /> of this <see cref="IGameState"/>
      /// </returns>
      virtual field::IField* GetField() const = 0;
      
      /// <summary>
      /// Construct a new <see cref="field::IField"/> with the provided <paramref name="tiles" />.
      /// </summary>
      /// <param name="tiles">The tiles of the new field.</param>
      virtual void ConstructNewField(const std::vector<std::vector<field::TileType>>& tiles) = 0;
      
      /// <summary>
      /// Get a pointer to the <see cref="IEntityManager"/>.
      /// </summary>
      /// <returns>A pointer to the <see cref="IEntityManager"/>.</returns>
      virtual IEntityManager* GetEntityManager() const = 0;
      
      /// <summary>
      /// Set the pointer to the entity manager.
      /// </summary>
      /// <param name="p_entity_manager">Unique pointer to the entity manager.</param>
      /// <postcondition>
      /// | (new this)->GetEntityManager() == p_entity_manager.get()
      /// </postcondition>
      virtual void SetEntityManager(std::unique_ptr<IEntityManager> p_entity_manager) = 0;
      
      /// <summary>
      /// Construct a new set of field objects as provided in the <paramref name="field_objects"/>.
      /// </summary>
      /// <param name="field_objects">The field objects.</param>
      virtual void ConstructNewFieldObjects(const std::vector<std::vector<field::FieldObjectType>>& field_objects) = 0;
      
      /// <summary>
      /// Gets the <see cref="field::IFieldObjectManager"/> of this 
      /// <see cref="IGameState"/>.
      /// </summary>
      /// <returns>
      /// A pointer to the <See cref="IFieldObjectManager"/> of this <see cref="IGameState"/>.
      /// </returns>
      virtual field::IFieldObjectManager* GetFieldObjectManager() const = 0;
      
      /// <summary>
      /// Gets the <see cref="score::IScoreBoard"/>.
      /// </summary>
      /// <returns>
      /// A pointer to the <see cref="score::IScoreBoard"/>.
      /// </returns>
      virtual score::IScoreBoard* GetScoreBoard() const = 0;
      
      /// <summary>
      /// Set the pointer to the score board.
      /// </summary>
      /// <param name="p_score_board"> Unique pointer to the new score board. </param>
      /// <postcondition>
      /// | (new this)->GetScoreBoard() == p_score_board.get()
      /// </postcondition>
      virtual void SetScoreBoard(std::unique_ptr<score::IScoreBoard> p_score_board) = 0;
      
      /// <summary>
      /// Gets the <see cref="level::ILevelManager"/>.
      /// </summary>
      /// <returns>
      /// A pointer to the <see cref="level::ILevelManager"/>.
      /// </returns>
      virtual level::ILevelManager* GetLevelManager() const = 0;      

      /// <summary>
      /// Sets the level manager.
      /// </summary>
      /// <param name="p_level_manager">Unique pointer to the level manager.</param>
      /// <postcondition>
      /// | (new this)->GetLevelManager() == p_level_manager.get()
      /// </postcondition>
      virtual void SetLevelManager(std::unique_ptr<level::ILevelManager> p_level_manager) = 0;
    };
  }
}

