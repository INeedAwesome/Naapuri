#pragma once

#define MAX_NAME_STRING 256
#define HInstance() GetModuleHandle(NULL)

#ifdef WIN32
	#include <Windows.h>
#endif

#ifdef BUILD_DLL
	#define NAAP_API __declspec(dllexport)
#else
	#define NAAP_API __declspec(dllimport)
#endif

#include "Common/Logger.h"
#include "Core/PerGameSettings.h"
#include "Common/Time.h"
