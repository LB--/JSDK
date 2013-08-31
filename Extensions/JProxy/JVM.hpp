#ifndef __JavaNativeInterface_HeaderPlusPlus__
#define __JavaNativeInterface_HeaderPlusPlus__

class JVM
{
	stdstring extname;

	JavaVM *jvm;
	JNIEnv *env;
	jint initresult;

	jclass
		jextedit,		//Edittime
		jextrun,		//Runtime
		jsdkedit,		//JSDK.Edittime
		jsdkrun,		//JSDK.Runtime
		jCRunApp,		//MMF2.Application
		jCRunFrame,		//MMF2.Application.Frame
		jheaderObject,	//MMF2.Runtime.Info
		jLO,			//MMF2.Application.Frame.Obj
		jmv,			//MMF2.Funcs
		jOI,			//MMF2.Application.Frame.Obj.Info
		jRunHeader;		//MMF2.Runtime

	static jint JNICALL JProxyVersion(JNIEnv *env, jclass clazz)
	{
		return 1;
	}

public:
	const stdstring &ExtName;
	const JNIEnv &Env;
	const jclass
		&JExtEdit,
		&JExtRun,
		&JSDKEdit,
		&JSDKRun,
		&JCRunApp,
		&JCRunFrame,
		&JheaderObject,
		&JLO,
		&Jmv,
		&JOI,
		&JRunHeader;

	JVM():ExtName(extname),
		Env(*env),
		JExtEdit(jextedit),
		JExtRun(jextrun),
		JSDKEdit(jsdkedit),
		JSDKRun(jsdkrun),
		JCRunApp(jCRunApp),
		JCRunFrame(jCRunFrame),
		JheaderObject(jheaderObject),
		JLO(jLO),
		Jmv(jmv),
		JOI(jOI),
		JRunHeader(jRunHeader)
	{
		{
			TCHAR DLLpath[MAX_PATH], DLLname[_MAX_FNAME];
			GetModuleFileName(DLL, DLLpath, MAX_PATH);
			_tsplitpath(DLLpath, NULL, NULL, DLLname, NULL);
			extname = DLLname;
		}

		{
			JavaVMInitArgs vm_args;
			vm_args.version = JNI_VERSION_1_6;
			vm_args.nOptions = 1;
			vm_args.options = new JavaVMOption[1];
			#ifdef EDITTIME
			vm_args.options[0].optionString = "-Djava.class.path=../Data/Runtime/Java/";
			#elif defined(RUNTIME)
			vm_args.options[0].optionString = "-Djava.class.path=Java/";//
			#else
			#error
			#endif
			vm_args.ignoreUnrecognized = false;
			initresult = JNI_CreateJavaVM(&jvm, (void **)&env, &vm_args);
			delete[] vm_args.options;
			if(initresult != JNI_OK)
			{
				return;
			}
		}

		jsdkedit = env->FindClass("JSDK/Edittime");
		JNINativeMethod editmethods[] =
		{
			{"Version","()I", &JProxyVersion}
		};
		env->RegisterNatives(jsdkedit, editmethods, 1);

		jsdkrun = env->FindClass("JSDK/Runtime");
		JNINativeMethod runmethods[] =
		{
			{"Version","()I", &JProxyVersion}
		};
		env->RegisterNatives(jsdkrun, runmethods, 1);

		jmv = env->FindClass("MMF2/Funcs");
		JNINativeMethod mvmethods[] =
		{
			{"App","()LMMF2/Application;", &MMF2_Funcs_App},
			{"AppFrame","()LMMF2/Application$Frame;", &MMF2_Funcs_AppFrame},
			{"Prefs","()I", &MMF2_Funcs_Prefs},
			{"AppPath","()Ljava/lang/String;", &MMF2_Funcs_AppPath},
			{"MMF2Version","()I", &MMF2_Funcs_MMF2Version},
			{"OpenHelp","(Ljava/lang/String;ILjava/lang/String;)V", &MMF2_Funcs_OpenHelp},
			{"TriggerCondition","(LExt/Runtime;I)V", &MMF2_Funcs_TriggerCondition},
			{"Rehandle","()V", &MMF2_Funcs_Rehandle},
			{"Redraw","()V", &MMF2_Funcs_Redraw},
			{"Position","(II)V", &MMF2_Funcs_Position}
		};
		env->RegisterNatives(jmv, mvmethods, 10);

		jCRunApp = env->FindClass("MMF2/Application");
		JNINativeMethod ramethods[] =
		{
			{"NFlags","()I", &MMF2_Application_NFlags},
			{"OFlags","()I", &MMF2_Application_OFlags},
			{"NFrames","()I", &MMF2_Application_NFrames},
			{"Framerate","()I", &MMF2_Application_Framerate},
			{"AppName","()Ljava/lang/String;", &MMF2_Application_AppName},
			{"AppFileName","()Ljava/lang/String;", &MMF2_Application_AppFileName},
			{"Copyright","()Ljava/lang/String;", &MMF2_Application_Copyright},
			{"AboutText","()Ljava/lang/String;", &MMF2_Application_AboutText},
			{"HelpFile","()Ljava/lang/String;", &MMF2_Application_HelpFile},
			{"NObjects","()I", &MMF2_Application_NObjects},
			{"Parent","()LMMF2/Application;", &MMF2_Application_Parent},
			{"CurrentFrameIndex","()I", &MMF2_Application_CurrentFrameIndex},
			{"CurrentFrame","()LMMF2/Application$Frame;", &MMF2_Application_CurrentFrame},
			{"GlobalValues","()[Ljava/lang/Number;", &MMF2_Application_GlobalValues},
			{"GlobalStrings","()[Ljava/lang/String;", &MMF2_Application_GlobalStrings}
		};
		env->RegisterNatives(jCRunApp, ramethods, 15);

		jCRunFrame = env->FindClass("MMF2/Application$Frame");
		JNINativeMethod rfmethods[] =
		{
			{"Width","()I", &MMF2_Application_Frame_Width},
			{"Height","()I", &MMF2_Application_Frame_Height},
			{"BackgroundColor","()I", &MMF2_Application_Frame_BackgroundColor},
			{"Flags","()I", &MMF2_Application_Frame_Flags},
			{"Name","()Ljava/lang/String;", &MMF2_Application_Frame_Name},
			{"NObjects","()I", &MMF2_Application_Frame_NObjects},
			{"GetRuntime","()LMMF2/Runtime;", &MMF2_Application_Frame_GetRuntime}
		};
		env->RegisterNatives(jCRunFrame, rfmethods, 7);

		jheaderObject = env->FindClass("MMF2/Runtime$Info");
		JNINativeMethod homethods[] =
		{
			{"ObjectNumber","()S", &MMF2_Runtime_Info_ObjectNumber},
			{"GetRuntime","()LMMF2/Runtime;", &MMF2_Runtime_Info_GetRuntime},
			{"X","()I", &MMF2_Runtime_Info_X},
			{"Y","()I", &MMF2_Runtime_Info_Y},
			{"XHS","()I", &MMF2_Runtime_Info_XHS},
			{"YHS","()I", &MMF2_Runtime_Info_YHS},
			{"Width","()I", &MMF2_Runtime_Info_Width},
			{"Height","()I", &MMF2_Runtime_Info_Height},
			{"Flags","()I", &MMF2_Runtime_Info_Flags}
		};
		env->RegisterNatives(jheaderObject, homethods, 9);

		jRunHeader = env->FindClass("MMF2/Runtime");
		JNINativeMethod rhmethods[] =
		{
			{"NLoops","()I", &MMF2_Runtime_NLoops},
			{"Timer","()I", &MMF2_Runtime_Timer}
		};
		env->RegisterNatives(jRunHeader, rhmethods, 2);

		jLO = env->FindClass("MMF2/Application$Frame$Obj");
		JNINativeMethod lomethods[] =
		{
			{"X","()I", &MMF2_Application_Frame_Obj_X},
			{"Y","()I", &MMF2_Application_Frame_Obj_Y},
			{"Layer","()I", &MMF2_Application_Frame_Obj_Layer},
			{"Type","()I", &MMF2_Application_Frame_Obj_Type}
		};
		env->RegisterNatives(jLO, lomethods, 4);

		jOI = env->FindClass("MMF2/Application$Frame$Obj$Info");
		JNINativeMethod oimethods[] =
		{
			{"Type","()I", &MMF2_Application_Frame_Obj_Info_Type},
			{"InkEffect","()I", &MMF2_Application_Frame_Obj_Info_InkEffect},
			{"InkEffectParam","()I", &MMF2_Application_Frame_Obj_Info_InkEffectParam},
			{"Name","()Ljava/lang/String;", &MMF2_Application_Frame_Obj_Info_Name},
		};
		env->RegisterNatives(jOI, oimethods, 4);

		jextedit = env->FindClass("Ext/Edittime");

		jextrun = env->FindClass("Ext/Runtime");
	}
	int InitStatus()
	{
		return initresult;
	}
	~JVM()
	{
		jvm->DestroyJavaVM();
	}

	static jobject InstantiatePtr(JNIEnv *env, jclass clazz, void *ptr)
	{
		return env->NewObject(clazz, env->GetMethodID(clazz, "<init>", "(I)V"), jint(ptr));
	}
	template<typename T>
	static T *GrabPtr(JNIEnv *env, jobject obj)
	{
		return (T *)env->GetIntField(obj, env->GetFieldID(env->GetObjectClass(obj), "donotchange", "I"));
	}

private:
	static jobject JNICALL MMF2_Funcs_App(JNIEnv *env, jobject obj);
	static jobject JNICALL MMF2_Funcs_AppFrame(JNIEnv *env, jobject obj);
	static jint JNICALL MMF2_Funcs_Prefs(JNIEnv *env, jobject obj);
	static jstring JNICALL MMF2_Funcs_AppPath(JNIEnv *env, jobject obj);
	static jint JNICALL MMF2_Funcs_MMF2Version(JNIEnv *env, jobject obj);
	static void JNICALL MMF2_Funcs_OpenHelp(JNIEnv *env, jobject obj, jstring HelpFile, jint HelpContextID, jstring HelpURL);
	static void JNICALL MMF2_Funcs_TriggerCondition(JNIEnv *env, jobject obj, jobject RunExt, jint ID);
	static void JNICALL MMF2_Funcs_Rehandle(JNIEnv *env, jobject obj);
	static void JNICALL MMF2_Funcs_Redraw(JNIEnv *env, jobject obj);
	static void JNICALL MMF2_Funcs_Position(JNIEnv *env, jobject obj, jint x, jint y);
	static jint JNICALL MMF2_Runtime_NLoops(JNIEnv *env, jobject obj);
	static jint JNICALL MMF2_Runtime_Timer(JNIEnv *env, jobject obj);
	static jshort JNICALL MMF2_Runtime_Info_ObjectNumber(JNIEnv *env, jobject obj);
	static jobject JNICALL MMF2_Runtime_Info_GetRuntime(JNIEnv *env, jobject obj);
	static jint JNICALL MMF2_Runtime_Info_X(JNIEnv *env, jobject obj);
	static jint JNICALL MMF2_Runtime_Info_Y(JNIEnv *env, jobject obj);
	static jint JNICALL MMF2_Runtime_Info_XHS(JNIEnv *env, jobject obj);
	static jint JNICALL MMF2_Runtime_Info_YHS(JNIEnv *env, jobject obj);
	static jint JNICALL MMF2_Runtime_Info_Width(JNIEnv *env, jobject obj);
	static jint JNICALL MMF2_Runtime_Info_Height(JNIEnv *env, jobject obj);
	static jint JNICALL MMF2_Runtime_Info_Flags(JNIEnv *env, jobject obj);
	static jint JNICALL MMF2_Application_NFlags(JNIEnv *env, jobject obj);
	static jint JNICALL MMF2_Application_OFlags(JNIEnv *env, jobject obj);
	static jint JNICALL MMF2_Application_NFrames(JNIEnv *env, jobject obj);
	static jint JNICALL MMF2_Application_Framerate(JNIEnv *env, jobject obj);
	static jstring JNICALL MMF2_Application_AppName(JNIEnv *env, jobject obj);
	static jstring JNICALL MMF2_Application_AppFileName(JNIEnv *env, jobject obj);
	static jstring JNICALL MMF2_Application_Copyright(JNIEnv *env, jobject obj);
	static jstring JNICALL MMF2_Application_AboutText(JNIEnv *env, jobject obj);
	static jstring JNICALL MMF2_Application_HelpFile(JNIEnv *env, jobject obj);
	static jint JNICALL MMF2_Application_NExtensions(JNIEnv *env, jobject obj);
	static jint JNICALL MMF2_Application_NMovements(JNIEnv *env, jobject obj);
	static jint JNICALL MMF2_Application_NObjects(JNIEnv *env, jobject obj);
	static jobject JNICALL MMF2_Application_Parent(JNIEnv *env, jobject obj);
	static jint JNICALL MMF2_Application_CurrentFrameIndex(JNIEnv *env, jobject obj);
	static jobject JNICALL MMF2_Application_CurrentFrame(JNIEnv *env, jobject obj);
	static jobjectArray JNICALL MMF2_Application_GlobalValues(JNIEnv *env, jobject obj);
	static jobjectArray JNICALL MMF2_Application_GlobalStrings(JNIEnv *env, jobject obj);
	static jint JNICALL MMF2_Application_Frame_Width(JNIEnv *env, jobject obj);
	static jint JNICALL MMF2_Application_Frame_Height(JNIEnv *env, jobject obj);
	static jint JNICALL MMF2_Application_Frame_BackgroundColor(JNIEnv *env, jobject obj);
	static jint JNICALL MMF2_Application_Frame_Flags(JNIEnv *env, jobject obj);
	static jstring JNICALL MMF2_Application_Frame_Name(JNIEnv *env, jobject obj);
	static jint JNICALL MMF2_Application_Frame_NObjects(JNIEnv *env, jobject obj);
	static jobject JNICALL MMF2_Application_Frame_GetRuntime(JNIEnv *env, jobject obj);
	static jint JNICALL MMF2_Application_Frame_Obj_X(JNIEnv *env, jobject obj);
	static jint JNICALL MMF2_Application_Frame_Obj_Y(JNIEnv *env, jobject obj);
	static jint JNICALL MMF2_Application_Frame_Obj_Layer(JNIEnv *env, jobject obj);
	static jint JNICALL MMF2_Application_Frame_Obj_Type(JNIEnv *env, jobject obj);
	static jint JNICALL MMF2_Application_Frame_Obj_Info_Type(JNIEnv *env, jobject obj);
	static jint JNICALL MMF2_Application_Frame_Obj_Info_InkEffect(JNIEnv *env, jobject obj);
	static jint JNICALL MMF2_Application_Frame_Obj_Info_InkEffectParam(JNIEnv *env, jobject obj);
	static jstring JNICALL MMF2_Application_Frame_Obj_Info_Name(JNIEnv *env, jobject obj);
};

#endif
