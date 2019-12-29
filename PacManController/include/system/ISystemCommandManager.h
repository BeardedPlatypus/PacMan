#pragma once

#include <memory>

#include "ICommand.h"
#include "event/ISystemEvent.h"


namespace pacman {
namespace controller {
namespace system {

/// <summary>
/// <see cref="keyboard::ICommandManager /> provides an interface to register, 
/// deregister, and query <see cref="ICommand" />s.
/// 
/// <see cref="system::ICommandManager /> is responsible for managing the 
/// the commands associated with it. 
/// Upon deletion of the <see cref="system::ICommandManager /> all associated
/// <see cref="ICommand" /> will be freed as well.
/// </summary>
class ISystemCommandManager {
public:
  /// <summary>
  /// Construct a new <see cref="system::ICommandManager" />.
  /// </summary>
  /// <returns>
  /// A <see cref="std::unique_ptr" /> containing a new 
  /// <see cref="ICommandManager" />.
  /// </returns>
  static std::unique_ptr<ISystemCommandManager> Construct();

  virtual ~ISystemCommandManager() = default;

  /// <summary>
  /// Register the specified <paramref name="p_command"> to the specified 
  /// <paramref name="kb_event" />.
  /// </summary>
  /// <param name="p_command"> 
  /// A pointer to the command to be registered.
  /// </param>
  /// <param name="kb_event"> 
  /// The event to register the <paramref name="p_command" /> to.
  /// </param>
  /// <pre-condition> 
  /// | p_command != null_ptr 
  /// </ pre-condition>
  /// <post-condition> 
  /// | (new this).HasEvent( <paramref name="kb_event" />) AND
  /// | (new this).GetCommand(<paramref name="kb_event" />) == <paramref name="p_command" />.Get() 
  /// </ post-condition />
  // <remarks>
  // Note that this <see cref="ICommandManager" /> will take ownership of
  // <paramref name="p_command" />, and it will be deleted upon deletion
  // of this <see cref="ICommandManager" />
  // </remarks>
  virtual void RegisterCommand(std::unique_ptr<ICommand> p_command,
                               ISystemEvent* kb_event) = 0;

  /// <summary>
  /// Deregister the <see cref="ICommand" /> associated with the specified
  /// <paramref name="kb_event" />.
  /// </summary>
  /// <param name="kb_event"> The kb event. </param>
  /// <invariant>
  /// IF NOT this.HasEvent(<paramref name="kb_event" />) THEN (new this) == this
  /// </ invariant>
  /// <post-condition> 
  /// | (new this).HasEvent(kb_event)
  /// </ post-condition>
  virtual void DeregisterCommand(ISystemEvent* kb_event) = 0;

  /// <summary>
  /// Get the <see cref="ICommand" /> associated with <paramref name="kb_event" />.
  /// </summary>
  /// <param name="kb_event">
  /// The kb event to retrieve the <see cref="ICommand" /> of.
  /// </param>
  /// <returns>
  /// The pointer to the <see cref="ICommand" /> associated with 
  /// <paramref name="kb_event" />.
  /// </returns>
  // <pre-condition>
  // | this.HasEvent(<paramref name="kb_event" />)
  // <pre-condition>
  virtual ICommand* GetCommand(ISystemEvent* kb_event) const = 0;

  /// <summary>
  /// Determine whether this <see cref="ICommandManager" /> has an 
  // <see cref="ICommand" /> associated with the specified 
  /// <paramref name="kb_event />.
  /// </summary>
  /// <param name="kb_event"> The kb_event. </param>
  /// <returns>
  /// <c>true</c> if the specified there is a command associated with
  /// <paramref name="kb_event" />; 
  /// otherwise, <c>false</c>.
  /// </returns>
  virtual bool HasEvent(ISystemEvent* kb_event) const = 0;
};

}
}
}

