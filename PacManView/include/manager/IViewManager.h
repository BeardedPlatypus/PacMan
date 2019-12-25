#pragma once
#define DllExport __declspec( dllexport )

#include <string>
#include <memory>
#include <vector>

#include "sprite/ClipRect.h"
#include "renderer/IViewCore.h"
#include "sprite/ISpriteManager.h"
#include "texture/ITextureManager.h"


namespace pacman {
namespace view {

/// <summary>
/// <see cref="IViewManager" /> provides an interface for external clients to
/// interact with this PacManView. It provides the basic functionality to 
/// request <see cref="Sprite" />s and <see cref="SpriteAnimation" />s. As well
/// as the functionality to render them. 
/// </summary>
class DllExport IViewManager {
public:		
	/// <summary>
	/// Construct a new <see cref="IViewManager" />.
	/// </summary>
	/// <returns> 
	/// A <see cref="std::unique_ptr" /> containing a new instance of a
	/// <see cref="IViewManager" />.
	/// </returns>
	static std::unique_ptr<IViewManager> construct();

	/// <summary>
	/// Construct a new <see cref="IViewManager" /> with the given parameters.
	/// </summary>
	/// <param name="p_renderer">
	/// Pointer to the <see cref="IRenderer" />.
	/// </param>
	/// <param name="p_texture_manager"> 
	/// Pointer to the <see cref="ITextureManager" />.
	/// </param>
	/// <param name="p_sprite_manager">
	/// Pointer to the <see cref="ISpriteManager" />. 
	/// </param>
	/// <returns> 
	/// A <see cref="std::unique_ptr" /> containing a new instance of a
	/// <see cref="IViewManager" />.
	/// </returns>
	static std::unique_ptr<IViewManager> construct(std::unique_ptr<IViewCore> p_view_core,
												   std::unique_ptr<ITextureManager> p_texture_manager,
												   std::unique_ptr<ISpriteManager> p_sprite_manager);

	/// <summary>
	/// Initialise this <see cref="IViewManager" />, starting up any graphical
	/// subsystems necessary to start rendering.
	/// </summary>
	/// <param name="screen_width"> Width of the screen. </param>
	/// <param name="screen_height"> Height of the screen. </param>
    /// <exception cref="ViewException"> 
	/// <paramref name="screen_width" /> <= 0 || <paramref name="screen_height" /> <= 0
	/// </exception>
	virtual void initialise(int screen_width, int screen_height) = 0;
	
	/// <summary> 
	/// Request a new <see cref="Sprite" /> with the given 
	/// <paramref name="label" />, <paramref name="texture_file_path" /> and
	/// <paramref name="cliiping_rectangle" />.
	/// </summary>
	/// <param name="label"> The label of the new <see cref="Sprite" />. </param>
	/// <param name="texture_file_path"> The texture file path the new <see cref="Sprite" /> references. </param>
	/// <param name="clipping_rectangle"> The clipping rectangle. </param>
	/// <exception cref="ViewException" > 
	/// Thrown when <paramref name="label" /> already exists. 
	/// </exception>
	/// <exception cref="ViewException" > 
	/// Thrown when <paramref name="texture_file_path" /> does not exist.
	/// </exception>
	/// <exception cref="ViewException" > 
	/// Thrown when <paramref name="clipping_rectangle" /> is invalid.
	/// </exception>
	virtual void requestSprite(const std::string& label,
							   const std::string& texture_file_path,
							   const ClipRect& clipping_rectangle) = 0;

	/// <summary> 
	/// Request a new <see cref="Sprite" /> with the given 
	/// <paramref name="label" />, <paramref name="texture_file_path" /> covering the whole texture.
	/// </summary>
	/// <param name="label"> The label of the new <see cref="Sprite" />. </param>
	/// <param name="texture_file_path"> The texture file path the new <see cref="Sprite" /> references. </param>
	/// <exception cref="ViewException" > 
	/// Thrown when <paramref name="label" /> already exists. 
	/// </exception>
	/// <exception cref="ViewException" > 
	/// Thrown when <paramref name="texture_file_path" /> does not exist. 
	/// </exception>
	virtual void requestSprite(const std::string& label,
							   const std::string& texture_file_path) = 0;
	
	/// <summary>
	/// Request a new <see cref="SpriteAnimation" /> with the specified 
	/// <paramref name="label" /> consisting of the <see cref="Sprite" />
	/// labels specified with <paramref name="sprite_labels" /> with each
	/// frame lasting for <paramref name="time_per_frame" />.
	/// </summary>
	/// <param name="label"> The label of this new <see cref="SpriteAnimation" />. </param>
	/// <param name="time_per_frame"> The time per frame. </param>
	/// <param name="sprite_labels"> The set of <see cref="Sprite" /> labels. </param>
	/// <exception cref="ViewException" >
	/// Thrown when <paramref name="label" /> already exists. 
	/// </exception>
	/// <exception cref="ViewException" >
	/// Thrown when <paramref name="time_per_frame" /> is smaller or equal to zero. 
	/// </exception>
	/// <exception cref="ViewException" > 
	/// Thrown when any of the <paramref name="sprite_labels" /> does not exist. 
	/// </exception>

	virtual void requestSpriteAnimation(const std::string& label,
										float time_per_frame,
										const std::vector<std::string>& sprite_labels) = 0;
	
	/// <summary>
	/// Update this IViewManager with the specified <paramref name="delta_time" />.
	/// </summary>
	/// <param name="delta_time"> The delta time since the last update. </param>
	/// <remarks>
	/// This value is used to update any <see cref="SpriteAnimation" />s that
	/// rendered this frame.
	/// </remarks>
	virtual void update(float delta_time) = 0;
	
	/// <summary>
	/// Initialise a new render frame.
	/// </summary>
	virtual void initialiseRender() = 0;
	
	/// <summary>
	/// Render the <see cref="Sprite" /> with the corresponding <paramref name="label" />.
	/// </summary>
	/// <param name="label"> The label of the <see cref="Sprite" />. </param>
	/// <param name="x"> The x-location to render the specified <see cref="Sprite" /> to. </param>
	/// <param name="y"> The y-location to render the specified <see cref="Sprite" /> to. </param>
	/// <param name="scale"> The scale with which the <see cref="Sprite" /> should be rendered. </param>
	/// <exception cref="ViewException" >
	/// Thrown when <paramref name="label" /> does not exist. 
	/// </exception>
	virtual void renderSprite(const std::string& label,
                            float x, 
                            float y, 
                            float scale,
                            float angle=0.F,
                            bool flip_horizontally=false,
                            bool flip_vertically=false) = 0;

	/// <summary>
	/// Render the <see cref="SpriteAnimation" /> with the corresponding <paramref name="label" />.
	/// </summary>
	/// <param name="label"> The label of the <see cref="SpriteAnimation" />. </param>
	/// <param name="x"> The x-location to render the specified <see cref="SpriteAnimation" /> to. </param>
	/// <param name="y"> The y-location to render the specified <see cref="SpriteAnimation" /> to. </param>
	/// <param name="scale"> The scale with which the <see cref="SpriteAnimation" /> should be rendered. </param>
	/// <exception cref="ViewException" >
	/// Thrown when <paramref name="label" /> does not exist. 
	/// </exception>
	virtual void renderSpriteAnimation(const std::string& label,
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
	virtual void finaliseRender() = 0;
};


}
}
