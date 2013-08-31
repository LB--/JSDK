#include "Common.hpp"

unsigned short MMF2Func GetRunObjectDataSize(RunHeader *rh, SerializedED *SED)
{
	//
	return sizeof(RD);
}

short MMF2Func CreateRunObject(RD *rd, SerializedED *SED, createObjectInfo *COI)
{
	//
	return 0;
}
short MMF2Func DestroyRunObject(RD *rd, long fast)
{
	//
	return 0;
}

short MMF2Func HandleRunObject(RD *rd)
{
	//
	return REFLAG_ONESHOT;
}
short MMF2Func DisplayRunObject(RD *rd)
{
	//
	return 0;
}

cSurface *MMF2Func GetRunObjectSurface(RD *rd)
{
	//
	return NULL;
}
LPSMASK MMF2Func GetRunObjectCollisionMask(RD *rd, LPARAM lParam)
{
	//
	return NULL;
}

short MMF2Func SaveBackground(RD *rd)
{
	//
	return 0;
}
short MMF2Func RestoreBackground(RD *rd)
{
	//
	return 0;
}
short MMF2Func KillBackground(RD *rd)
{
	//
	return 0;
}

short MMF2Func PauseRunObject(RD *rd)
{
	//
	return 0;
}
short MMF2Func ContinueRunObject(RD *rd)
{
	//
	return 0;
}

BOOL MMF2Func SaveRunObject(RD *rd, HANDLE File)
{
	//
	return TRUE;
}
BOOL MMF2Func LoadRunObject(RD *rd, HANDLE File)
{
	//
	return TRUE;
}

void MMF2Func StartApp(mv *mV, CRunApp *App)
{
	//
}
void MMF2Func EndApp(mv *mV, CRunApp *App)
{
	//
}

void MMF2Func StartFrame(mv *mV, CRunApp *App, int FrameIndex)
{
	//
}
void MMF2Func EndFrame(mv *mV, CRunApp *App, int FrameIndex)
{
	//
}

LRESULT CALLBACK WindowProc(RunHeader *rh, HWND Window, UINT Message, WPARAM wParam, LPARAM lParam)
{
	//
	return 0;
}
