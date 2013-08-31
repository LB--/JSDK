#include "Common.hpp"

/*Edittime*/

DWORD MMF2Func GetTextCaps(mv *mV, SerializedED *SED)
{
	//
	return 0;
}

BOOL MMF2Func GetTextFont(mv *mV, SerializedED *SED, LPLOGFONT plf, LPSTR, UINT)
{
	//
	return TRUE;
}
BOOL MMF2Func SetTextFont(mv *mV, SerializedED *SED, LPLOGFONT plf, LPCSTR)
{
	//
	return TRUE;
}

COLORREF MMF2Func GetTextClr(mv *mV, SerializedED *SED)
{
	//
	return 0;
}
void MMF2Func SetTextClr(mv *mV, SerializedED *SED, COLORREF Color)
{
	//
}

DWORD MMF2Func GetTextAlignment(mv *mV, SerializedED *SED)
{
	//
	return 0;
}
void MMF2Func SetTextAlignment(mv *mV, SerializedED *SED, DWORD AlignFlags)
{
	//
}

/*Runtime*/

void MMF2Func GetRunObjectFont(RD *rd, LOGFONT *pLf)
{
	//
}
void MMF2Func SetRunObjectFont(RD *rd, LOGFONT *Lf, RECT *Rect)
{
	//
}

COLORREF MMF2Func GetRunObjectTextColor(RD *rd)
{
	//
	return 0;
}
void MMF2Func SetRunObjectTextColor(RD *rd, COLORREF Color)
{
	//
}
