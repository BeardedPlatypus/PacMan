#pragma once

#include <SDL2\SDL.h>
#include <string>
#include <memory>
#include <map>

#include "sdl_util/SDLDestructor.h"
#include "renderer/IRenderer.h"
#include "texture/ITexture.h"


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
class TextureManager {
public:	
  /// <summary>
  /// Construct a new <see cref="TextureManager"/> with the specified
  /// <paramref name="p_renderer" />.
  /// </summary>
  /// <param name="p_renderer">The p renderer.</param>
  TextureManager(const IRenderer& p_renderer);
	
  /// <summary>
  /// Loads the <see cref="ITexture" /> at the specified 
  /// <paramref name="file_path" />.
  /// </summary>
  /// <param name="file_path">The file path.</param>
  /// <post-condition> 
  /// (new this)-><see cref="getTexture" />(<paramref name="file_path" /> 
  /// </post-condition>
  void loadTexture(const std::string& file_path);
	
  /// <summary>
  /// Determines whether the specified the <see cref="ITexture /> at the 
  /// specified <paramref name="file_path" /> has already been loaded by this
  /// <see cref="TextureManager" />.
  /// </summary>
  /// <param name="file_path"> The file path. </param>
  /// <returns>
  ///   <c>true</c> if the specified file_path has already been loaded; 
  ///   otherwise, <c>false</c>.
  /// </returns>
  bool hasTexture(const std::string& file_path) const;
	
  /// <summary>
  /// Get the <see cref="ITexture /> associated with the specified 
  /// <paramref name="file_path" />.
  /// </summary>
  /// <param name="file_path"> The file path. </param>
  /// <returns> 
  /// The <see cref="ITexture" /> associated with the specified 
  /// <paramref name="file_path" />. </returns>
  const ITexture& getTexture(const std::string& file_path) const;

private:  
  /// <summary>
  /// The texture map containing the pointers to the loaded 
  /// <see cref="ITexture" /> associated with the path they belong to.
  /// </summary>
  std::map<std::string, std::unique_ptr<ITexture>> texture_map;
  
  /// <summary>
  /// A reference to renderer used to load textures.
  /// </summary>
  const IRenderer& renderer;
};

} // view
} // pacman
