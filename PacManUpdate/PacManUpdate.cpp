// PacManUpdate.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "PacManUpdate.h"


// This is an example of an exported variable
PACMANUPDATE_API int nPacManUpdate=0;

// This is an example of an exported function.
PACMANUPDATE_API int fnPacManUpdate(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CPacManUpdate::CPacManUpdate()
{
    return;
}
