#pragma once

#include <SDL2/SDL.h>

#include "manager/IViewManager.h"
#include "sdl_util/SDLDestructor.h"

namespace pacman {
namespace view {

/// <summary>
/// <see cref="ViewManager" /> implements <see cref="IViewManager" />
/// </summary>
/// <seealso cref="IViewManager" />
class ViewManager final : public IViewManager {
public:
	/// <summary>
	/// Construct a new <see cref="ViewManager"/> with the given pointers.
	/// </summary>
	/// <param name="p_renderer"> A pointer to the renderer.</param>
	/// <param name="p_texture_manager"> A pointer to the texture manager.</param>
	/// <param name="p_sprite_manager"> A pointer to the sprite manager.</param>
	ViewManager(std::unique_ptr<IViewCore> p_view_core,
				std::unique_ptr<ITextureManager> p_texture_manager,
				std::unique_ptr<ISpriteManager> p_sprite_manager);

	void initialise() final;

	void requestSprite(const std::string& label,
					   const std::string& texture_file_path,
					   const ClipRect clipping_rectangle) final;

	void requestSprite(const std::string& label,
					   const std::string& texture_file_path) final;

	void requestSpriteAnimation(const std::string& label,
								float time_per_frame,
								const std::vector<std::string>& sprite_labels) final;

	void update(float delta_time) final;

	void initialiseRender() final;

	void renderSprite(const std::string& label,
					  float x, float y, float scale) final;

	void renderSpriteAnimation(const std::string& label,
							   float x, float y, float scale) final;

	void finaliseRender() final;

private:		
	/// <summary>
	/// Get the <see cref="IRenderer" /> of this <see cref="ViewManager" />.
	/// </summary>
	/// <returns> 
	/// A reference to the <see cref="IRenderer" /> of this <see cref="ViewManager" />.
	/// </returns>
	inline IRenderer& getRenderer() const { return this->p_view_core->getRenderer(); }

	/// <summary>
	/// Get the <see cref="IViewCore" /> of this <see cref="ViewManager" />.
	/// </summary>
	/// <returns> 
	/// A reference to the <see cref="IViewCore" /> of this <see cref="ViewManager" />.
	/// </returns>
	inline IViewCore& getViewCore() const { return *this->p_view_core; }

	/// <summary> 
	/// A pointer to the <see cref="IRenderer" /> of this <see cref="ViewManager" />.
	/// </summary>
	std::unique_ptr<IViewCore> p_view_core;

	/// <summary>
	/// Get the <see cref="ITextureManager" /> of this <see cref="ViewManager" />.
	/// </summary>
	/// <returns> 
	/// A reference to the <see cref="ITextureManager" /> of this <see cref="ViewManager" />.
	/// </returns>
	inline ITextureManager& getTextureManager() const { return *this->p_texture_manager; }

	/// <summary> 
	/// A pointer to the <see cref="ITextureManager" /> of this <see cref="ViewManager" />. 
	/// </summary>
	std::unique_ptr<ITextureManager> p_texture_manager;

	/// <summary>
	/// Get the <see cref="ISpriteManager" /> of this <see cref="ViewManager" />.
	/// </summary>
	/// <returns> 
	/// A reference to the <see cref="ISpriteManager" /> of this <see cref="ViewManager" />.
	/// </returns>
	inline ISpriteManager& getSpriteManager() const { return *this->p_sprite_manager; }

	/// <summary> 
	/// A pointer to the <see cref="ISpriteManager" /> of this <see cref="ViewManager" />.
	/// </summary>
	std::unique_ptr<ISpriteManager> p_sprite_manager;

	// TODO: improve the documentation / handling of this
	/// <summary>
	/// Get the nextUpdateTime of this <see cref="ViewManager" />.
	/// </summary>
	/// <returns> The nextUpdateTime of this <see cref="ViewManager" />. </returns>
	inline float getNextUpdateTime() const { return this->nextUpdateTime; }

	/// <summary>
	/// Set the nextUpdateTime of this <see cref="ViewManager" />.
	/// </summary>
	/// <param name="time"> The next update time. </param>
	/// <post-condition> (new this)->getNextUpdateTime() == <paramref name="time" />
	inline void setNextUpdateTime(float time) { this->nextUpdateTime = time; }
	
	/// <summary> The next update time. </summary>
	float nextUpdateTime;
};


}
}
