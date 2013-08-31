#include "Common.hpp"

HINSTANCE DLL (0);
BOOL WINAPI JSDKMain(HINSTANCE Dll, DWORD Reason, LPVOID)
{
	switch(Reason)
	{
	case DLL_PROCESS_ATTACH:
		{
			DLL = Dll;
			break;
		}
	}
	return TRUE;
}

JVM *ext;
int MMF2Func Initialize(mv *mV, int Quiet)
{
	ext = new JVM();
	if(ext->InitStatus() != JNI_OK)
	{
		if(!Quiet)
		{
			MessageBox(	mV->mvHMainWin,
						(TEXT("Failed to start JVM, error code: ") + stdstring() & ext->InitStatus()).c_str(),
						(TEXT("JSDK - ") + ext->ExtName).c_str(),
						MB_OK|MB_ICONERROR);
		}
		return-1;
	}
	return 0;
}
int MMF2Func Free(mv *mV)
{
	delete ext;
	return 0;
}

DWORD MMF2Func GetInfos(int Which)
{
	switch(Which)
	{
	case KGI_VERSION:	return EXT_VERSION2;
	case KGI_PLUGIN:	return EXT_PLUGIN_VERSION1;
	case KGI_PRODUCT:
		{
			//
			if(false)
			{
				return PRODUCT_VERSION_DEV; //MMF2 Developer
			}
			else if(false)
			{
				return PRODUCT_VERSION_HOME; //TGF2 Full
			}
			return PRODUCT_VERSION_STANDARD; //MMF2 Standard
		}
	case KGI_BUILD:
		{
			//
			return 0 > 255 ? 0 : 255;
		}
	case KGI_UNICODE:
		{
			#ifdef UNICODE
			return TRUE;
			#else
			return FALSE;
			#endif
		}
	}
	return 0;
}
short MMF2Func GetRunObjectInfos(mv *mV, kpxRunInfos *Info)
{
	//

	Info->identifier;
	Info->version;

	Info->numOfConditions;
	Info->numOfActions;
	Info->numOfExpressions;

	Info->conditions;
	Info->actions;
	Info->expressions;

	Info->editDataSize;

	Info->windowProcPriority;

	Info->editFlags;
	Info->editPrefs;

	return TRUE;
}
void MMF2Func GetObjInfos(mv *mV, SerializedED *SED, LPSTR ObjName/*255*/, LPSTR ObjAuthor/*255*/, LPSTR ObjCopyright/*255*/, LPSTR ObjComment/*1024*/, LPSTR ObjHttp/*255*/)
{
	//
}
LPCSTR MMF2Func GetHelpFileName()
{
	//
	return TEXT("");
}

LPCSTR *MMF2Func GetDependencies()
{
	//
	return 0;
}

int MMF2Func LoadObject(mv *mV, LPCSTR Filename, SerializedED *SED, int)
{
	//
	return 0;
}
void MMF2Func UnloadObject(mv *mV, SerializedED *SED, int)
{
	//
}

HGLOBAL MMF2Func UpdateEditStructure(mv *mV, SerializedED *OldSED)
{
	//
	return 0;
}
void MMF2Func UpdateFileNames(mv *mV, LPSTR AppName, SerializedED *SED, void (MMF2Func *Update)(LPSTR, LPSTR))
{
	//
}

int MMF2Func EnumElts(mv *mV, SerializedED *SED, ENUMELTPROC enumProc, ENUMELTPROC undoProc, LPARAM lp1, LPARAM lp2)
{
	//
	return 0;
}
