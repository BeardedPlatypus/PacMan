#pragma once
#define DllExport __declspec( dllexport )

#include <memory>

#include "entity/IEntityState.h"
#include "GameMode.h"
#include "field/Field.h"
#include "field/object/FieldObjectType.h"
#include "field/object/IFieldObjectManager.h"

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
      /// Get a pointer to state of the player.
      /// </summary>
      /// <returns>A pointer to the state of the player.</returns>
      virtual IEntityState* GetPlayerState() const = 0;
      
      /// <summary>
      /// Set the pointer to the player state.
      /// </summary>
      /// <param name="p_player_state">State of the p player.</param>
      /// <postcondition>
      /// | (new this)->GetPlayerState() == p_player_state.get()
      /// </postcondition>
      virtual void SetPlayerState(std::unique_ptr<IEntityState> p_player_state) = 0;

      virtual void ConstructNewFieldObjects(const std::vector<std::vector<field::FieldObjectType>>& field_objects) = 0;

      virtual field::IFieldObjectManager* GetFieldObjectManager() const = 0;
    };
  }
}

