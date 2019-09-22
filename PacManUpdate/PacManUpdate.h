// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the PACMANUPDATE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// PACMANUPDATE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef PACMANUPDATE_EXPORTS
#define PACMANUPDATE_API __declspec(dllexport)
#else
#define PACMANUPDATE_API __declspec(dllimport)
#endif

// This class is exported from the dll
class PACMANUPDATE_API CPacManUpdate {
public:
	CPacManUpdate(void);
	// TODO: add your methods here.
};

extern PACMANUPDATE_API int nPacManUpdate;

PACMANUPDATE_API int fnPacManUpdate(void);
