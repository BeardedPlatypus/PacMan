#pragma once

#include "IViewAPI.h"

#include "sprite/ClipRect.h"
#include "renderer/IViewCore.h"
#include "sprite/ISpriteManager.h"
#include "texture/ITextureManager.h"

namespace pacman {
namespace view {

/// <summary>
/// <see cref="ViewAPI"/> implements <see cref="IViewAPI"/>
/// </summary>
/// <seealso cref="IViewAPI"/>
class ViewAPI final : public IViewAPI {
public:
	/// <summary>
	/// Construct a new <see cref="ViewAPI"/> with the given pointers.
	/// </summary>
	/// <param name="p_renderer"> A pointer to the renderer.</param>
	/// <param name="p_texture_manager"> A pointer to the texture manager.</param>
	/// <param name="p_sprite_manager"> A pointer to the sprite manager.</param>
	ViewAPI(std::unique_ptr<IViewCore> p_view_core,
				  std::unique_ptr<ITextureManager> p_texture_manager,
				  std::unique_ptr<ISpriteManager> p_sprite_manager);

	void Initialise(int screen_width, int screen_height) final;

	void RequestSprite(const std::string& label,
					           const std::string& texture_file_path,
		                 int x, int y, int w, int h) final;

	void RequestSprite(const std::string& label,
					           const std::string& texture_file_path) final;

	void RequestSpriteAnimation(const std::string& label,
								              float time_per_frame,
								              const std::vector<std::string>& sprite_labels) final;

	float GetAnimationTime(const std::string& label) const final;

	void UpdateAnimation(const std::string& label, 
		                   float delta_time) final;

	void SetAnimationToTime(const std::string& label,
		                      float new_time) final;
	
	void ResetAnimationTime(const std::string& label) final;


	void InitialiseRender() final;

	void RenderSprite(const std::string& label,
                    float x, 
                    float y, 
                    float scale,
                    float angle,
                    bool flip_horizontally,
                    bool flip_vertically) final;

  void RenderSpriteAnimation(const std::string& label,
                             float x,
                             float y,
                             float scale,
                             float angle,
                             bool flip_horizontally,
                             bool flip_vertically) final;

	void FinaliseRender() final;

private:		
	/// <summary>
	/// Get the <see cref="IViewCore"/> of this <see cref="ViewAPI"/>.
	/// </summary>
	/// <returns> 
	/// A reference to the <see cref="IViewCore"/> of this <see cref="ViewAPI"/>.
	/// </returns>
	inline IViewCore& GetViewCore() const { return *this->p_view_core; }

	/// <summary> 
	/// A pointer to the <see cref="IRenderer"/> of this <see cref="ViewAPI"/>.
	/// </summary>
	std::unique_ptr<IViewCore> p_view_core;

	/// <summary>
	/// Get the <see cref="IRenderer"/> of this <see cref="ViewAPI"/>.
	/// </summary>
	/// <returns> 
	/// A reference to the <see cref="IRenderer"/> of this <see cref="ViewAPI"/>.
	/// </returns>
	inline IRenderer& GetRenderer() const { return this->GetViewCore().GetRenderer(); }

	/// <summary>
	/// Get the <see cref="ITextureManager"/> of this <see cref="ViewAPI"/>.
	/// </summary>
	/// <returns> 
	/// A reference to the <see cref="ITextureManager"/> of this <see cref="ViewAPI"/>.
	/// </returns>
	inline ITextureManager& GetTextureManager() const { return *this->p_texture_manager; }

	/// <summary> 
	/// A pointer to the <see cref="ITextureManager"/> of this <see cref="ViewAPI"/>. 
	/// </summary>
	std::unique_ptr<ITextureManager> p_texture_manager;

	/// <summary>
	/// Get the <see cref="ISpriteManager"/> of this <see cref="ViewAPI"/>.
	/// </summary>
	/// <returns> 
	/// A reference to the <see cref="ISpriteManager"/> of this <see cref="ViewManager"/>.
	/// </returns>
	inline ISpriteManager& GetSpriteManager() const { return *this->p_sprite_manager; }

	/// <summary> 
	/// A pointer to the <see cref="ISpriteManager"/> of this <see cref="ViewAPI"/>.
	/// </summary>
	std::unique_ptr<ISpriteManager> p_sprite_manager;
};

}
}
