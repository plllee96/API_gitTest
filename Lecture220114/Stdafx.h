#pragma once

#include <sdkddkver.h>		
#define WIN32_LEAN_AND_MEAN            
#define _USE_MATH_DEFINES

//# Library
#include <windows.h>
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#pragma comment(lib, "Winmm.lib")
#pragma comment(lib, "msimg32.lib")

//# Ignore Warning
#pragma warning(disable:4244)

//# C Header
#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>
#include <time.h>
#include <assert.h>
#include <math.h>
#include <mmsystem.h>
#include <mciapi.h>

//# C++ Header
#include <iostream>
#include <random>
#include <bitset>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

//===============================================================
//# Custom Header File
//===============================================================
#include "CommonMacroFunction.h"
#include "RandomFunction.h"
#include "KeyManager.h"
#include "ImageManager.h"
#include "FontManager.h"
#include "TempSoundManager.h"
#include "TimeManager.h"
#include "Utils.h"

using namespace MY_UTIL;

//===============================================================
//# Singleton Header File
//===============================================================
#define RND						RandomFunction::getSingleton()
#define KEYMANAGER			KeyManager::getSingleton()
#define IMAGEMANAGER		ImageManager::getSingleton()
#define FONTMANAGER			FontManager::getSingleton()
#define SOUNDMANAGER		TempSoundManager::getSingleton()
#define TIMEMANAGER			TimeManager::getSingleton()

//===============================================================
//# Window Macro
//===============================================================
#define WINNAME				LPSTR(TEXT("WindowsAPI"))
//#define FULLSCREEN

#ifdef FULLSCREEN
#define WINSTART_X				0
#define WINSTART_Y				0
#define WINSIZE_X				GetSystemMetrics(SM_CXSCREEN)
#define WINSIZE_Y				GetSystemMetrics(SM_CYSCREEN)
#define WINSTYLE					WS_POPUPWINDOW | WS_MAXIMIZE
#else
#define WINSTART_X				100
#define WINSTART_Y				0
#define WINSIZE_X				1200
#define WINSIZE_Y				800
#define WINSTYLE					WS_CAPTION | WS_SYSMENU
#endif



#define PI							3.141592653
#define DTOR(degree)			(degree)*M_PI/180.0f

//===============================================================
//# Macro
//===============================================================
#define CENTER_X			WINSIZE_X / 2
#define CENTER_Y			WINSIZE_Y / 2

//===============================================================
//# Function Macro (Release Dynamic Allocation)
//===============================================================
#define SAFE_DELETE(p)					{if(p) {delete (p); (p) = nullptr;}}
#define SAFE_DELETE_ARRAY(p)		{if(p) {delete[] (p); (p) = nullptr;}}
#define SAFE_RELEASE(p)				{if(p) {(p)->release(); (p) = nullptr;}}

//===============================================================
//# Global Variable
//===============================================================
extern HINSTANCE _hInstance;
extern HWND _hWnd;
extern POINT _ptMouse;
