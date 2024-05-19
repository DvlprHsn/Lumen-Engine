#pragma once

#ifdef LUMEN_PLATFORM_WIN64
	#if LUMEN_BUILD_DLL
		#define LUMEN_API __declspec(dllexport)
	#else
		#define LUMEN_API __declspec(dllimport)
	#endif
#endif

#ifdef LUMEN_PLATFORM_WIN32
	#if LUMEN_BUILD_DLL
		#define LUMEN_API __declspec(dllexport)
	#else
		#define LUMEN_API __declspec(dllimport)
	#endif
#endif
