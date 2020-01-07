#pragma once
#define DllExport __declspec( dllexport )


namespace pacman {
namespace state {
namespace field {

/// <summary>
/// <see cref="FieldObjectType"/> describes the different types of field
/// objects with which entities can interact.
/// </summary>
enum class DllExport FieldObjectType {
  Undefined = 0,
  Portal = 1,
};


/// <summary>
/// Check whether the specified <paramref name="t"/> is defined.
/// </summary>
/// <param name="t"> The type to check. </param>
/// <returns>
/// <c>true</c> if <paramref name="t"/> is defined; otherwise <c>false</c>.
bool IsDefined(FieldObjectType t);

}
}
}
