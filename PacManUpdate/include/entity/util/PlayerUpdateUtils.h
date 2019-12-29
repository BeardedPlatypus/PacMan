#pragma once

#include <field/IField.h>
#include "entity/UpdatablePlayerEntity.h"


namespace pacman {
namespace update {
namespace util {

  /// <summary>
  /// Check whether the <paramref name="p_player_entity"/> is active.
  /// </summary>
  /// <param name="p_player_entity">
  /// A pointer to the <see cref="IUpdatablePlayerEntity"/> to be checked.
  /// </param>
  /// <returns>
  /// <c>true</c> if <paramref name="p_player_entity"/> is active; 
  /// <c>false</c> otherwise.
  /// </returns>
  bool IsActive(const IUpdatablePlayerEntity* p_player_entity);

  /// <summary>
  /// Indicate whether the direction of the current active axis of this
  /// <see cref="IUpdatablePlayerEntity"/> should be updated.
  /// </summary>
  /// <param name="p_player_entity">
  /// A pointer to the <see cref="IUpdatablePlayerEntity"/> to be checked.
  /// </param>
  /// <returns>
  /// <c>true</c> if <paramref name="p_player_entity"/>'s active axis direction
  /// should be updated; <c>false</c> otherwise.
  /// </returns>
  bool ShouldUpdateDirectionActiveAxis(const IUpdatablePlayerEntity* p_player_entity);

  /// <summary>
  /// Update the direction of the active axis of the specified
  /// <see cref="p_player_entity"/> to it's next direction on the active axis.
  /// </summary>
  /// <param name="p_player_entity">
  /// A pointer to the <see cref="IUpdatablePlayerEntity"/> to be updated.
  /// </param>
  void UpdateDirectionActiveAxis(const IUpdatablePlayerEntity* p_player_entity);

  /// <summary>
  /// Get the value corresponding with the specified direction.
  /// </summary>
  /// <param name="direction">The direction.</param>
  /// <returns>
  /// | AxisDirection::Positive -> +1
  /// | AxisDirection::Negative -> -1
  /// | otherwise               ->  0
  /// </returns>
  int GetDirectionValue(AxisDirection direction);

  /// <summary>
  /// Check whether the <paramref name="p_player_entity"/> has a direction
  /// in the inactive axis specified.
  /// </summary>
  /// <param name="p_player_entity">
  /// A pointer to the <see cref="IUpdatablePlayerEntity"/> to be checked.
  /// </param>
  /// <returns>
  /// <c>true</c> if <paramref name="p_player_entity"/> has a direction
  /// specified on the inactive axis; <c>false</c> otherwise.
  /// </returns>
  bool HasOtherDirection(const IUpdatablePlayerEntity* p_player_entity);

  /// <summary>
  /// Get the distance to the next tile center this 
  /// <paramref name="p_player_entity"/> will encounter on its active axis.
  /// </summary>
  /// <param name="p_player_entity">
  /// A pointer to the <see cref="IUpdatablePlayerEntity"/>.
  /// </param>
  /// <returns>
  /// The distance to the next tile center this 
  /// <paramref name="p_player_entity"/> will encounter.
  /// <returns>
  float GetDistanceToNextCenter(const IUpdatablePlayerEntity* p_player_entity);

  /// <summary>
  /// Get the distance to the previous tile center this 
  /// <paramref name="p_player_entity"/> has encountered on its active axis.
  /// </summary>
  /// <param name="p_player_entity">
  /// A pointer to the <see cref="IUpdatablePlayerEntity"/>.
  /// </param>
  /// <returns>
  /// The distance to the previous tile center this 
  /// <paramref name="p_player_entity"/> has encountered.
  /// <returns>
  float GetDistanceToPreviousCenter(const IUpdatablePlayerEntity* p_player_entity);

  /// <summary>
  /// Check whether an entity can move to position 
  /// (<paramref name="x"/>, <paramref name="y"/>) on <paramref name="p_field"/>.
  /// </summary>
  /// <param name="p_field">
  /// A pointer to a <see cref="state::field::IField"/>.
  /// </param>
  /// <param name="x">The x location to check.</param>
  /// <param name="y">The y location to check.</param>
  bool CanMoveToPosition(const state::field::IField* p_field, int x, int y);

  /// <summary>
  /// Check whether <paramref name="p_player_entity"/> can move in the 
  /// direction of its inactive axis at the next tile center.
  /// </summary>
  /// <param name="p_player_entity">
  /// A pointer to the <see cref="IUpdatablePlayerEntity"/>.
  /// </param>
  /// <param name="p_field">
  /// A pointer to a <see cref="state::field::IField"/>.
  /// </param>
  /// <returns>
  /// <c>true</c> if <paramref name="p_player_entity"/> can move in to the
  /// next direction of its inactive axis at the next tile center;
  /// <c>false</c> otherwise.
  /// </returns>
  bool CanMoveInNextDirectionAtNextTileCenter(const IUpdatablePlayerEntity* p_player_entity,
                                              const state::field::IField* p_field);

  /// <summary>
  /// Check whether <paramref name="p_player_entity"/> can move in the 
  /// direction of its inactive axis at the previous tile center.
  /// </summary>
  /// <param name="p_player_entity">
  /// A pointer to the <see cref="IUpdatablePlayerEntity"/>.
  /// </param>
  /// <param name="p_field">
  /// A pointer to a <see cref="state::field::IField"/>.
  /// </param>
  /// <returns>
  /// <c>true</c> if <paramref name="p_player_entity"/> can move in to the
  /// next direction of its inactive axis at the previous tile center;
  /// <c>false</c> otherwise.
  /// </returns>
  bool CanMoveInNextDirectionAtPreviousTileCenter(const IUpdatablePlayerEntity* p_player_entity,
                                                  const state::field::IField* p_field);

  /// <summary>
  /// Move the <paramref name="p_player_entity"/> along its active axis by
  /// the specified <paramref name="distance"/>.
  /// </summary>
  /// <param name="p_player_entity">
  /// A pointer to the <see cref="IUpdatablePlayerEntity"/> to be moved.
  /// </param>
  /// <param name="distance">
  /// The distance to move the <paramref name="p_player_entity"/>.
  /// </param>
  /// <param name="moveInOppositeDirection"/>
  /// If true, then the <paramref name="p_player_entity"/> will be moved in its
  /// opposite direction.
  /// </param>
  void MoveOnActiveAxis(const IUpdatablePlayerEntity* p_player_entity,
                        float distance,
                        bool moveInOppositeDirection=false);

  /// <summary>
  /// Get the maximum distance left to move given the current position of
  /// <paramref name="p_player_entity"/>, the <paramref name="p_field"/> and
  /// the <paramref name="max_distance_to_move"/>.
  /// </summary>
  /// <param name="p_player_entity">
  /// A pointer to the <see cref="IUpdatablePlayerEntity"/>.
  /// </param>
  /// <param name="p_field">
  /// A pointer to the <see cref="state::field::IField"/>.
  /// </param>
  /// <param name="max_distance_to_move">
  /// The maximum distance which can be moved.
  /// </param>
  /// <returns>
  /// If no restrictions apply, then <paramref name="max_distance_to_move"/>.
  /// If the movement is limited, then the maximum distance with 
  /// <paramref name="max_distance_to_move"/> as an upperbound.
  /// </returns>
  float GetConfinedDistanceToMove(const IUpdatablePlayerEntity* p_player_entity,
                                  const state::field::IField* p_field,
                                  float max_distance_to_move);

  /// <summary>
  /// Move the <paramref name="p_player_entity"/> the maximum valid distance 
  /// smaller or equal than <paramref name="max_distance_to_move"/> on its
  /// active axis, given <paramref name="p_field"/>.
  /// </summary>
  /// <param name="p_player_entity">
  /// A pointer to the <see cref="IUpdatablePlayerEntity"/>.
  /// </param>
  /// <param name="p_field">
  /// A pointer to the <see cref="state::field::IField"/>.
  /// </param>
  /// <param name="max_distance_to_move">
  /// The maximum distance which can be moved.
  /// </param>
  void ConditiallyMoveDistance(const IUpdatablePlayerEntity* p_player_entity, 
                               const state::field::IField* p_field,
                               float max_distance_to_move);

  /// <summary>
  /// Update the direction of <paramref name="p_player_entity"/>.
  /// </summary>
  /// <param name="p_player_entity">
  /// A pointer to the <see cref="IUpdatablePlayerEntity"/> to be updated.
  /// </param>
  void UpdateDirection(IUpdatablePlayerEntity* p_player_entity);
}
}
}
