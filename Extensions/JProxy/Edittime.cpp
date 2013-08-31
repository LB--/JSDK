#include "Common.hpp"

int MMF2Func CreateObject(mv *mV, LO *lo, SerializedED *SED)
{
	//
	return 0;
}
BOOL MMF2Func UsesFile(mv *mV, LPSTR Filename)
{
	//
	return FALSE;
}
void MMF2Func CreateFromFile(mv *mV, LPSTR Filename, SerializedED *SED)
{
	//
}
void MMF2Func PutObject(mv *mV, LO *lo, SerializedED *SED, unsigned short othersame)
{
	//
}
void MMF2Func DuplicateObject/*CloneObject*/(mv *mV, OI *oi, SerializedED *SED)
{
	//
}
void MMF2Func RemoveObject(mv *mV, LO *lo, SerializedED *SED, unsigned short othersame)
{
	//
}

BOOL MMF2Func EditObject(mv *mV, OI *oi, LO *lo, SerializedED *SED)
{
	return TRUE;
}

BOOL MMF2Func SetEditSize(mv *mV, SerializedED *SED, int X, int Y)
{
	//
	return TRUE;
}
void MMF2Func GetObjectRect(mv *mV, RECT *rect, LO *lo, SerializedED)
{
	//
	rect->right = rect->left + 32;//w
	rect->bottom = rect->top + 32;//h
}

int MMF2Func MakeIconEx(mv *mV, cSurface *Icon, LPSTR Name, OI *oi, SerializedED *SED)
{
	//
	return 0;
}
void MMF2Func EditorDisplay(mv *mV, OI *oi, LO *lo, SerializedED *SED, RECT *Clipping)
{
	//
}

BOOL MMF2Func IsTransparent(mv *mV, OI *lo, SerializedED *SED, int X, int Y)
{
	//
	return FALSE;
}

void MMF2Func PrepareToWriteObject(mv *mV, SerializedED *SED, OI *oi)
{
	//
}

BOOL MMF2Func GetFilters(mv *mV, SerializedED *SED, DWORD Flags, LPVOID)
{
	//
	return FALSE;
}

void MMF2Func PrepareFlexBuild(mv *mV, SerializedED *SED, LPCWSTR TempFolder)
{
	//
}
