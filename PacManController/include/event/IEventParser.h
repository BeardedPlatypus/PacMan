#pragma once

#include <memory>


namespace pacman {
namespace controller {

class IEvent;

/// <summary>
/// The <see cref="IEventParser" /> is responsible for parsing pointers
/// to events to pointers of their subclass.
/// </summary>
template<class T>
class IEventParser {  
public:
  /// <summary>
  /// Construct a <see cref="IEventParser" />.
  /// </summary>
  /// <returns>A <see cref="IeventParser" /></returns>
  static std::unique_ptr<IEventParser> Construct();

  virtual ~IEventParser() = default;

  /// <summary>
  /// Obtain a pointer of T, where T is a subclass of <see cref="IEvent" />,
  /// if <paramref name="p_event" /> is of the same type as T then a pointer to
  /// this subclass is returned, else a <c>nullptr</c> will be returned.
  /// </summary>
  /// <param name="p_event"> Pointer to the <see cref="IEvent" /> to be parsed. </param>
  /// <returns> 
  /// A pointer of type T if IEvent is of type T, else a <c>nullptr</c>
  /// </returns>
  virtual T* operator() (IEvent* p_event) = 0;
};

}
}
