#include "Common.hpp"

BOOL MMF2Func GetProperties(mv *mV, SerializedED *SED, BOOL MasterItem)
{
	//
	return TRUE;
}
LPARAM MMF2Func GetPropCreateParam(mv *mV, SerializedED *SED, unsigned int PropID)
{
	return NULL;
}
void MMF2Func ReleasePropCreateParam(mv *mV, SerializedED *SED, unsigned int PropID, LPARAM lParam)
{
	//
}
void MMF2Func ReleaseProperties(mv *mV, SerializedED *SED, BOOL MasterItem)
{
	//
}

BOOL MMF2Func IsPropEnabled(mv *mV, SerializedED *SED, unsigned int PropID)
{
	//
	return TRUE;
}

LPVOID MMF2Func GetPropValue(mv *mV, SerializedED *SED, unsigned int PropID)
{
	//
	return NULL;
}
BOOL MMF2Func GetPropCheck(mv *mV, SerializedED *SED, unsigned int PropID)
{
	//
	return FALSE;
}
void MMF2Func SetPropValue(mv *mV, SerializedED *SED, unsigned int PropID, LPVOID lParam)
{
	//
}
void MMF2Func SetPropCheck(mv *mV, SerializedED *SED, unsigned int PropID, BOOL Checked)
{
	//
}
BOOL MMF2Func EditProp(mv *mV, SerializedED *SED, unsigned int PropID)
{
	//
	return TRUE;
}
