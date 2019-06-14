#pragma once

#include <SDL2\SDL.h>
#include <memory>
#include <map>

#include "sdl_util/SDLDestructor.h"
#include "texture/ITextureManager.h"

namespace pacman {
namespace view {

/// <summary>
/// TextureManager is responsible for loading all <see cref="ITexture" /> from
/// the file system. It provides the methods to load textures as well as query
/// the <see cref="TextureManager /> has already loaded said textures.
/// 
/// All <see cref="ITexture" /> used within this project should be constructed
/// through this <see cref="TextureManager" />. This will allow the manager to
/// properly control the lifetime of all <see cref="ITexture" />. 
/// 
/// All textures are destroyed upon destroying this manager.
/// </summary>
class TextureManager final : public ITextureManager {
public:	
  /// <summary>
  /// Construct a new <see cref="TextureManager"/> with the specified
  /// <paramref name="p_renderer" />.
  /// </summary>
  /// <param name="p_renderer">The p renderer.</param>
  TextureManager(const IRenderer& p_renderer);
	
  void loadTexture(const std::string& file_path) final;
	
  bool hasTexture(const std::string& file_path) const final;
	
  const ITexture& getTexture(const std::string& file_path) const final;

private:  
  /// <summary>
  /// The texture map containing the pointers to the loaded 
  /// <see cref="ITexture" /> associated with the path they belong to.
  /// </summary>
  std::map<std::string, std::unique_ptr<ITexture>> texture_map;
  
  /// <summary>
  /// A reference to renderer of this <see cref="TextureManager" />.
  /// </summary>
  const IRenderer& renderer;
};

} // view
} // pacman
