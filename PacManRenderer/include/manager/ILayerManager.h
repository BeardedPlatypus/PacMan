#pragma once


namespace pacman {
namespace renderer {
  
/// <summary>
/// <see cref="ILayerManager"/> defines the manager for 
/// the different layers defined within this pacman application.
/// </summary>
class ILayerManager {
public:
  virtual ~ILayerManager() = default;
  
  /// <summary>
  /// Initialise this <see cref="IlayerManager"/> by constructing
  /// the relevant layers.
  /// </summary>
  virtual void Initialise() = 0;
  
  /// <summary>
  /// Update the specified d time.
  /// </summary>
  /// <param name="d_time"> The time passed since last frame. </param>
  virtual void Update(float d_time) = 0;
  
  /// <summary>
  /// Render the layers contained in this manager.
  /// </summary>
  virtual void Render() const = 0;
};

}
}
