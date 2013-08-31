#include "Common.hpp"

jobject JNICALL JVM::MMF2_Funcs_App(JNIEnv *env, jobject obj)
{
	return InstantiatePtr(env, ext->JCRunApp, GrabPtr<mv>(env, obj)->mvRunApp);
}
jobject JNICALL JVM::MMF2_Funcs_AppFrame(JNIEnv *env, jobject obj)
{
	return InstantiatePtr(env, ext->JCRunFrame, GrabPtr<mv>(env, obj)->mvRunFrame);
}
jint JNICALL JVM::MMF2_Funcs_Prefs(JNIEnv *env, jobject obj)
{
	return jint(GrabPtr<mv>(env, obj)->mvPrefs);
}
jstring JNICALL JVM::MMF2_Funcs_AppPath(JNIEnv *env, jobject obj)
{
	return Conv2::JStr(env, GrabPtr<mv>(env, obj)->mvMainAppFileName);
}
jint JNICALL JVM::MMF2_Funcs_MMF2Version(JNIEnv *env, jobject obj)
{
	return jint(GrabPtr<mv>(env, obj)->mvGetVersion());
}
void JNICALL JVM::MMF2_Funcs_OpenHelp(JNIEnv *env, jobject obj, jstring HelpFile, jint HelpContextID, jstring HelpURL)
{
	const jchar *helpfile = env->GetStringChars(HelpFile, 0);
	const jchar *helpurl = env->GetStringChars(HelpURL, 0);
	GrabPtr<mv>(env, obj)->mvHelpW((LPCWSTR)helpfile, HelpContextID, (LPARAM)helpurl);
	env->ReleaseStringChars(HelpFile, helpfile);
	env->ReleaseStringChars(HelpURL, helpurl);
}
void JNICALL JVM::MMF2_Funcs_TriggerCondition(JNIEnv *env, jobject obj, jobject RunExt, jint ID)
{
	callRunTimeFunction(GrabPtr<RD>(env, obj), RFUNCTION_GENERATEEVENT, ID, 0);
}
void JNICALL JVM::MMF2_Funcs_Rehandle(JNIEnv *env, jobject obj)
{
	callRunTimeFunction(GrabPtr<RD>(env, obj), RFUNCTION_REHANDLE, 0, 0);
}
void JNICALL JVM::MMF2_Funcs_Redraw(JNIEnv *env, jobject obj)
{
	callRunTimeFunction(GrabPtr<RD>(env, obj), RFUNCTION_REDRAW, 0, 0);
}
void JNICALL JVM::MMF2_Funcs_Position(JNIEnv *env, jobject obj, jint x, jint y)
{
	callRunTimeFunction(GrabPtr<RD>(env, obj), RFUNCTION_SETPOSITION, x, y);
}

jint JNICALL JVM::MMF2_Runtime_NLoops(JNIEnv *env, jobject obj)
{
	return GrabPtr<RunHeader>(env, obj)->rhLoopCount;
}
jint JNICALL JVM::MMF2_Runtime_Timer(JNIEnv *env, jobject obj)
{
	return GrabPtr<RunHeader>(env, obj)->rhTimer;
}
jshort JNICALL JVM::MMF2_Runtime_Info_ObjectNumber(JNIEnv *env, jobject obj)
{
	return GrabPtr<headerObject>(env, obj)->hoNumber;
}
jobject JNICALL JVM::MMF2_Runtime_Info_GetRuntime(JNIEnv *env, jobject obj)
{
	return InstantiatePtr(env, ext->JRunHeader, GrabPtr<headerObject>(env, obj)->hoAdRunHeader);
}
jint JNICALL JVM::MMF2_Runtime_Info_X(JNIEnv *env, jobject obj)
{
	return GrabPtr<headerObject>(env, obj)->hoX;
}
jint JNICALL JVM::MMF2_Runtime_Info_Y(JNIEnv *env, jobject obj)
{
	return GrabPtr<headerObject>(env, obj)->hoY;
}
jint JNICALL JVM::MMF2_Runtime_Info_XHS(JNIEnv *env, jobject obj)
{
	return GrabPtr<headerObject>(env, obj)->hoImgXSpot;
}
jint JNICALL JVM::MMF2_Runtime_Info_YHS(JNIEnv *env, jobject obj)
{
	return GrabPtr<headerObject>(env, obj)->hoImgYSpot;
}
jint JNICALL JVM::MMF2_Runtime_Info_Width(JNIEnv *env, jobject obj)
{
	return GrabPtr<headerObject>(env, obj)->hoImgWidth;
}
jint JNICALL JVM::MMF2_Runtime_Info_Height(JNIEnv *env, jobject obj)
{
	return GrabPtr<headerObject>(env, obj)->hoImgHeight;
}
jint JNICALL JVM::MMF2_Runtime_Info_Flags(JNIEnv *env, jobject obj)
{
	return GrabPtr<headerObject>(env, obj)->hoOEFlags;
}

jint JNICALL JVM::MMF2_Application_NFlags(JNIEnv *env, jobject obj)
{
	return GrabPtr<CRunApp>(env, obj)->m_hdr.gaNewFlags;
}
jint JNICALL JVM::MMF2_Application_OFlags(JNIEnv *env, jobject obj)
{
	return GrabPtr<CRunApp>(env, obj)->m_hdr.gaFlags;
}
jint JNICALL JVM::MMF2_Application_NFrames(JNIEnv *env, jobject obj)
{
	return GrabPtr<CRunApp>(env, obj)->m_hdr.gaNbFrames;
}
jint JNICALL JVM::MMF2_Application_Framerate(JNIEnv *env, jobject obj)
{
	return GrabPtr<CRunApp>(env, obj)->m_hdr.gaFrameRate;
}
jstring JNICALL JVM::MMF2_Application_AppName(JNIEnv *env, jobject obj)
{
	return Conv2::JStr(env, GrabPtr<CRunApp>(env, obj)->m_name);
}
jstring JNICALL JVM::MMF2_Application_AppFileName(JNIEnv *env, jobject obj)
{
	return Conv2::JStr(env, GrabPtr<CRunApp>(env, obj)->m_appFileName);
}
jstring JNICALL JVM::MMF2_Application_Copyright(JNIEnv *env, jobject obj)
{
	return Conv2::JStr(env, GrabPtr<CRunApp>(env, obj)->m_copyright);
}
jstring JNICALL JVM::MMF2_Application_AboutText(JNIEnv *env, jobject obj)
{
	return Conv2::JStr(env, GrabPtr<CRunApp>(env, obj)->m_aboutText);
}
jstring JNICALL JVM::MMF2_Application_HelpFile(JNIEnv *env, jobject obj)
{
	return Conv2::JStr(env, GrabPtr<CRunApp>(env, obj)->m_doc);
}
jint JNICALL JVM::MMF2_Application_NExtensions(JNIEnv *env, jobject obj)
{
	return GrabPtr<CRunApp>(env, obj)->m_nbKpx;
}
jint JNICALL JVM::MMF2_Application_NMovements(JNIEnv *env, jobject obj)
{
	return GrabPtr<CRunApp>(env, obj)->m_nbMvx;
}
jint JNICALL JVM::MMF2_Application_NObjects(JNIEnv *env, jobject obj)
{
	return GrabPtr<CRunApp>(env, obj)->m_oiMaxIndex;
}
jobject JNICALL JVM::MMF2_Application_Parent(JNIEnv *env, jobject obj)
{
	return InstantiatePtr(env, ext->JCRunApp, GrabPtr<CRunApp>(env, obj)->m_pParentApp);
}
jint JNICALL JVM::MMF2_Application_CurrentFrameIndex(JNIEnv *env, jobject obj)
{
	return GrabPtr<CRunApp>(env, obj)->m_nCurrentFrame;
}
jobject JNICALL JVM::MMF2_Application_CurrentFrame(JNIEnv *env, jobject obj)
{
	return InstantiatePtr(env, ext->JCRunFrame, GrabPtr<CRunApp>(env, obj)->m_Frame);
}
jobjectArray JNICALL JVM::MMF2_Application_GlobalValues(JNIEnv *env, jobject obj)
{
	CRunApp *app = GrabPtr<CRunApp>(env, obj);
	while(app->m_bShareGlobalValues) app = app->m_pParentApp;
	unsigned int nvals = app->m_nGlobalValues;
	jobjectArray vals = env->NewObjectArray(nvals, env->FindClass("java/lang/Number"), 0);
	jclass jInteger = env->FindClass("java/lang/Integer"), jDouble = env->FindClass("java/lang/Double");
	jmethodID jIntegerInit = env->GetMethodID(jInteger, "<init>", "(I)V"), jDoubleInit = env->GetMethodID(jDouble, "<init>", "(D)V");
	for(unsigned i = 0; i < nvals; ++i)
	{
		CValue &val (app->m_pGlobalValues[i]);
		if(val.m_type == TYPE_LONG)
		{
			env->SetObjectArrayElement(vals, i, env->NewObject(jInteger, jIntegerInit, val.m_long));
		}
		else if(val.m_type == TYPE_DOUBLE)
		{
			env->SetObjectArrayElement(vals, i, env->NewObject(jDouble, jDoubleInit, val.m_double));
		}
	}
	return vals;
}
jobjectArray JNICALL JVM::MMF2_Application_GlobalStrings(JNIEnv *env, jobject obj)
{
	CRunApp *app = GrabPtr<CRunApp>(env, obj);
	while(app->m_bShareGlobalStrings) app = app->m_pParentApp;
	unsigned int nvals = app->m_nGlobalStrings;
	jobjectArray vals = env->NewObjectArray(nvals, env->FindClass("java/lang/String"), 0);
	for(unsigned i = 0; i < nvals; ++i)
	{
		env->SetObjectArrayElement(vals, i, Conv2::JStr(env, app->m_pGlobalString[i]));
	}
	return vals;
}
jint JNICALL JVM::MMF2_Application_Frame_Width(JNIEnv *env, jobject obj)
{
	return GrabPtr<CRunFrame>(env, obj)->m_hdr.leWidth;
}
jint JNICALL JVM::MMF2_Application_Frame_Height(JNIEnv *env, jobject obj)
{
	return GrabPtr<CRunFrame>(env, obj)->m_hdr.leHeight;
}
jint JNICALL JVM::MMF2_Application_Frame_BackgroundColor(JNIEnv *env, jobject obj)
{
	return GrabPtr<CRunFrame>(env, obj)->m_hdr.leBackground;
}
jint JNICALL JVM::MMF2_Application_Frame_Flags(JNIEnv *env, jobject obj)
{
	return GrabPtr<CRunFrame>(env, obj)->m_hdr.leFlags;
}
jstring JNICALL JVM::MMF2_Application_Frame_Name(JNIEnv *env, jobject obj)
{
	return Conv2::JStr(env, GrabPtr<CRunFrame>(env, obj)->m_name);
}
jint JNICALL JVM::MMF2_Application_Frame_NObjects(JNIEnv *env, jobject obj)
{
	return GrabPtr<CRunFrame>(env, obj)->m_loMaxIndex;
}
jobject JNICALL JVM::MMF2_Application_Frame_GetRuntime(JNIEnv *env, jobject obj)
{
	return InstantiatePtr(env, ext->JCRunApp, GrabPtr<CRunFrame>(env, obj)->m_rhPtr);
}
jint JNICALL JVM::MMF2_Application_Frame_Obj_X(JNIEnv *env, jobject obj)
{
	return GrabPtr<LO>(env, obj)->loX;
}
jint JNICALL JVM::MMF2_Application_Frame_Obj_Y(JNIEnv *env, jobject obj)
{
	return GrabPtr<LO>(env, obj)->loY;
}
jint JNICALL JVM::MMF2_Application_Frame_Obj_Layer(JNIEnv *env, jobject obj)
{
	return GrabPtr<LO>(env, obj)->loLayer;
}
jint JNICALL JVM::MMF2_Application_Frame_Obj_Type(JNIEnv *env, jobject obj)
{
	return GrabPtr<LO>(env, obj)->loType;
}
jint JNICALL JVM::MMF2_Application_Frame_Obj_Info_Type(JNIEnv *env, jobject obj)
{
	return GrabPtr<OI>(env, obj)->oiHdr.oiType;
}
jint JNICALL JVM::MMF2_Application_Frame_Obj_Info_InkEffect(JNIEnv *env, jobject obj)
{
	return GrabPtr<OI>(env, obj)->oiHdr.oiInkEffect;
}
jint JNICALL JVM::MMF2_Application_Frame_Obj_Info_InkEffectParam(JNIEnv *env, jobject obj)
{
	return GrabPtr<OI>(env, obj)->oiHdr.oiInkEffectParam;
}
jstring JNICALL JVM::MMF2_Application_Frame_Obj_Info_Name(JNIEnv *env, jobject obj)
{
	return Conv2::JStr(env, GrabPtr<OI>(env, obj)->oiName);
}
