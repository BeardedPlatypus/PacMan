#pragma once
#define DllExport __declspec( dllexport )

#include <memory>

#include "GameMode.h"
#include "field/Field.h"


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
      /// Move the <see cref="IField" /> to this <see cref="IGameState" />.
      /// </summary>
      /// <param name="p_field">The p field.</param>
      /// <post-condition>
      /// (new this)->GetField() == <paramref name="p_field" />.get()
      /// </post-condition>
      virtual void SetField(std::unique_ptr<field::IField> p_field) = 0;
    };

  }
}

