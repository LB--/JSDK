#ifndef __Common_HeaderPlusPlus__
#define __Common_HeaderPlusPlus__
#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>

#include "jni.h"
#pragma comment(lib, "jvm.lib")

#include <string>
typedef std::basic_string<TCHAR> stdstring;
#include <sstream>
typedef std::basic_stringstream<TCHAR> stdstringstream;
typedef std::basic_istringstream<TCHAR> stdistringstream;
typedef std::basic_ostringstream<TCHAR> stdostringstream;
template<typename T> inline stdstring operator&(stdstring str, T t){ stdostringstream ss; return str + (ss << t, ss).str(); }
#include "StringConvert.hpp"
#include <vector>
#include <map>

#define	COXSDK
#include "ccxhdr.h"
#include "Surface.h"
#define MMF2Func __stdcall

#ifndef RUN_ONLY
	#define RunOnly_Start(alternate)
	#define RunOnly_End
#else
	#define RunOnly_Start(alternate) {alternate} /##*
	#define RunOnly_End *##/
#endif

namespace Conv2
{
	inline jstring JStr(JNIEnv *env, TCHAR *str)
	{
		#ifdef UNICODE
		return env->NewString(str, wcslen(str));
		#else
		size_t len = strlen(str);
		wchar_t *wstr = new wchar_t[len+1];
		MultiByteToWideChar(CP_UTF8, MB_PRECOMPOSED, str, -1, wstr, len+1);
		jstring jstr = env->NewString((jchar*)wstr, len);
		delete[] wstr;
		return jstr;
		#endif
	}
	inline stdstring stdStr(const wchar_t *wstr)
	{
		#ifdef UNICODE
		return str;
		#else
		size_t len = wcslen(wstr);
		char *str = new char[len+1];
		WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len+1, "?", 0);
		stdstring s (str);
		delete[] str;
		return s;
		#endif
	}
}

extern HINSTANCE DLL;
#include "JVM.hpp"
extern JVM *ext;

#include "EditData.hpp"
#include "RunData.hpp"

#endif
