#pragma once
#define DllExport __declspec( dllexport )

#include <string>

#include "renderer/IRenderer.h"
#include "texture/ITexture.h"


namespace pacman {
namespace view {

/// <summary>
/// <see cref="ITextureManager" /> is responsible for loading all 
/// <see cref="ITexture" />. It provides the methods to load textures as well 
/// as query whether it has already loaded said textures.
/// 
/// All <see cref="ITexture" /> used within this project should be constructed
/// through this <see cref="ITextureManager" />. This will allow the manager to
/// properly control the lifetime of all <see cref="ITexture" />. 
/// </summary>
class DllExport ITextureManager {
public:  
  /// <summary>
  /// Construct a new <see cref="ITextureManager" /> with the given 
  /// <paramref name="renderer" />.
  /// </summary>
  /// <param name="renderer">The renderer.</param>
  /// <returns> 
  /// A <see cref="std::unique_ptr<ITextureManager>" /> containing a
  /// new <see cref="ITextureManager" />.
  /// </returns>
  static std::unique_ptr<ITextureManager> construct(const IRenderer& renderer);

  virtual ~ITextureManager() {}

  /// <summary>
  /// Loads the <see cref="ITexture" /> at the specified 
  /// <paramref name="file_path" />. If the path has already 
  /// been loaded, nothing will change.
  /// </summary>
  /// <param name="file_path">The file path.</param>
  /// <post-condition> 
  /// (new this)-><see cref="getTexture" />(<paramref name="file_path" /> 
  /// </post-condition>
  virtual void loadTexture(const std::string& file_path) = 0;
	
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
  virtual bool hasTexture(const std::string& file_path) const = 0;
	
  /// <summary>
  /// Get the <see cref="ITexture /> associated with the specified 
  /// <paramref name="file_path" />.
  /// </summary>
  /// <param name="file_path"> The file path. </param>
  /// <returns> 
  /// The <see cref="ITexture" /> associated with the specified 
  /// <paramref name="file_path" />. </returns>
  virtual const ITexture& getTexture(const std::string& file_path) const = 0;
};

}
}
