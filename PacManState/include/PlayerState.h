#pragma once
#define DllExport __declspec( dllexport )


namespace pacman {
namespace state {

/// <summary>
/// A basic PlayerState object describing the location of the player, as well 
/// as its speed.
/// </summary>
class DllExport PlayerState {
public:			
  /// <summary>
  /// Initializes a new instance of the <see cref="PlayerState"/> class.
  /// </summary>
  /// <param name="x"> The x-axis location. </param>
  /// <param name="y"> The y-axis location. </param>
  /// <param name="speed"> The speed. </param>
  PlayerState(float x, float y, float speed);

  /// <summary>
  /// Get the location of this player on the x-axis.
  /// </summary>
  /// <returns> 
  /// The location of this player on the x-axis. 
  /// </returns>
  inline float getLocationX() const;
  
  /// <summary>
  /// Set the location on the x-axis of this PlayerState.
  /// </summary>
  /// <param name="new_x"> The new x-axis location. </param>
  inline void  setLocationX(float new_x);

  /// <summary>
  /// Get the location of this player on the y-axis.
  /// </summary>
  /// <returns> 
  /// The location of this player on the y-axis. 
  /// </returns>
  inline float getLocationY() const;

  /// <summary>
  /// Set the location on the y-axis of this PlayerState.
  /// </summary>
  /// <param name="new_x">The new y-axis location.</param>
  inline void  setLocationY(float new_y);
  
  /// <summary>
  /// Get the speed of this PlayerState.
  /// </summary>
  /// <returns> The speed of this PlayerState. </returns>
  inline float getSpeed() const;
  
  /// <summary>
  /// Set the speed of this PlayerState.
  /// </summary>
  /// <param name="new_speed"> The new speed.</param>
  inline void setSpeed(float new_speed);

private:  
  /// <summary> The location on the x-axis. </summary>
  float location_x;
  /// <summary> The location on the y-axis. </summary>
  float location_y;  
  /// <summary> The speed of this PlayerState. </summary>
  float speed;
};

} // state
} // pacman