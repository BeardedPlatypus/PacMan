#pragma once
#define DllExport __declspec( dllexport )

#include <string>
#include <memory>
#include <vector>

namespace pacman {
namespace view {

/// <summary>
/// <see cref="ViewAPI"/> provides an interface for external clients to interact with 
/// this PacManView. It provides the basic functionality to request sprites and sprite
/// animations. As well as the functionality to render them. 
/// </summary>
class DllExport IViewAPI {
public:		
	/// <summary>
	/// Construct a new <see cref="IViewAPI"/>.
	/// </summary>
	/// <returns> 
	/// A <see cref="std::unique_ptr"/> containing a new instance of a <see cref="ViewAPI"/>.
	/// </returns>
	static std::unique_ptr<IViewAPI> Construct();

	/// <summary>
	/// Initialise this <see cref="IViewAPI" />, starting up any graphical subsystems 
	/// necessary to start rendering.
	/// </summary>
	/// <param name="screen_width"> Width of the screen. </param>
	/// <param name="screen_height"> Height of the screen. </param>
  /// <exception cref="ViewException"> 
	/// <paramref name="screen_width"/> <= 0 || <paramref name="screen_height"/> <= 0
	/// </exception>
	virtual void Initialise(int screen_width, int screen_height) = 0;
	
	/// <summary> 
	/// Request a new sprite with the given <paramref name="label"/> and 
	/// the subsection specified by <paramref name="x"/>, <paramref name="y"/>,
	/// <paramref name="w"/>, and <paramref name="h"/> of the texture located at 
	/// <paramref name="texture_file_path"/>.
	/// </summary>
	/// <param name="label"> The label of the new sprite. </param>
	/// <param name="texture_file_path"> 
	/// The texture file path the new sprite references. 
	/// </param>
	/// <param name="x"> The x-coordinate of the subsection of the texture referenced. </param>
	/// <param name="y"> The y-coordinate of the subsection of the texture referenced. </param>
	/// <param name="w"> The width of the subsection of the texture referenced. </param>
	/// <param name="h"> The height of the subsection of the texture referenced. </param>
	/// <exception cref="ViewException" > 
	/// Thrown when <paramref name="label"/> already exists or
	///        when <paramref name="texture_file_path" /> does not exist.
	///        when any of the subsection values are invalid.
	/// </exception>
	virtual void RequestSprite(const std::string& label,
		                         const std::string& texture_file_path,
							               int x, 
		                         int y,
		                         int w,
		                         int h) = 0;

	/// <summary> 
	/// Request a new sprite with the given <paramref name="label"/> and 
	/// the whole texture located at <paramref name="texture_file_path"/>.
	/// </summary>
	/// <param name="label"> The label of the new sprite. </param>
	/// <param name="texture_file_path"> 
	/// The texture file path the new sprite references. 
	/// </param>
	/// <exception cref="ViewException"> 
	/// Thrown when <paramref name="label"/> already exists or
	///        when <paramref name="texture_file_path"/> does not exist. 
	/// </exception>
	virtual void RequestSprite(const std::string& label,
							               const std::string& texture_file_path) = 0;
	
	/// <summary>
	/// Request a new sprite animation with the specified <paramref name="label"/>
	/// consisting of the sprite labels specified with <paramref name="sprite_labels"/>
	/// with each frame lasting for <paramref name="time_per_frame"/>.
	/// </summary>
	/// <param name="label"> The label of the new sprite animation. </param>
	/// <param name="time_per_frame"> The time per frame. </param>
	/// <param name="sprite_labels"> The set of sprite labels. </param>
	/// <exception cref="ViewException">
	/// Thrown when <paramref name="label"/> already exists or
	///        when <paramref name="time_per_frame"/> is smaller or equal to zero or
	///        when any of the <paramref name="sprite_labels"/> does not exist. 
	/// </exception>
	virtual void RequestSpriteAnimation(const std::string& label,
										                  float time_per_frame,
										                  const std::vector<std::string>& sprite_labels) = 0;
	
	/// <summary>
	/// Get the current time of the animation.
	/// </summary>
	/// <param name="label">The label.</param>
	/// <returns></returns>
	virtual float GetAnimationTime(const std::string& label) const = 0;
	
	/// <summary>
	/// Update the sprite animation with the specified <paramref name="label"/> with
	/// the given time <paramref name="delta_time"/>.
	/// </summary>
	/// <param name="label"> The label of the sprite animation to update. </param>
	/// <param name="delta_time"> The delta time since the last update. </param>
	virtual void UpdateAnimation(const std::string& label,
		                           float delta_time) = 0;
	
	/// <summary>
	/// Set the animation to time to <paramref name="new_time"/>.
	/// </summary>
	/// <param name="label"> The label of the sprite animation to update. </param>
	/// <param name="new_time"> The new time. </param>
	virtual void SetAnimationToTime(const std::string& label,
		                              float new_time) = 0;
	
	/// <summary>
	/// Resets the time of the animation.
	/// </summary>
	/// <param name="label"> The label of the sprite animation to update. </param>
	virtual void ResetAnimationTime(const std::string& label) = 0;
	
	/// <summary>
	/// Initialise a new render frame.
	/// </summary>
	virtual void InitialiseRender() = 0;
	
	/// <summary>
	/// Render the sprite with the corresponding <paramref name="label"/>.
	/// </summary>
	/// <param name="label"> The label of the sprite. </param>
	/// <param name="x"> The x-location to render to. </param>
	/// <param name="y"> The y-location to render to. </param>
	/// <param name="scale"> The scale with which to render. </param>
	/// <exception cref="ViewException">
	/// Thrown when <paramref name="label"/> does not exist. 
	/// </exception>
	virtual void RenderSprite(const std::string& label,
                            float x, 
                            float y, 
                            float scale,
                            float angle=0.F,
                            bool flip_horizontally=false,
                            bool flip_vertically=false) = 0;

	/// <summary>
	/// Render the sprite animation with the corresponding <paramref name="label"/>.
	/// </summary>
	/// <param name="label"> The label of the sprite animation. </param>
	/// <param name="x"> The x-location to render to. </param>
	/// <param name="y"> The y-location to render to. </param>
	/// <param name="scale"> The scale with which to render. </param>
	/// <exception cref="ViewException">
	/// Thrown when <paramref name="label"/> does not exist. 
	/// </exception>
	virtual void RenderSpriteAnimation(const std::string& label,
                                     float x, 
                                     float y, 
                                     float scale,
                                     float angle=0.F,
                                     bool flip_horizontally=false,
                                     bool flip_vertically=false) = 0;
	
	/// <summary>
	/// Finalise the current render frame by actually rendering all specified
	/// elements.
	/// </summary>
	virtual void FinaliseRender() = 0;
};

}
}

