#pragma once

#ifdef LUMEN_PLATFORM_WIN64
	#if LUMEN_BUILD_DLL
		#define LUMEN_API __declspec(dllexport)
	#else
		#define LUMEN_API __declspec(dllimport)
	#endif
#elif LUMEN_PLATFORM_WIN32
	#if LUMEN_BUILD_DLL
		#define LUMEN_API __declspec(dllexport)
	#else
		#define LUMEN_API __declspec(dllimport)
	#endif
#elif LUMEN_PLATFORM_MACOS
	#if LUMEN_BUILD_DLL
		#define LUMEN_API __attribute__((visibility("default")))
	#else
		#define LUMEN_API
	#endif
#elif LUMEN_PLATFORM_LINUX
	#if LUMEN_BUILD_DLL
		#define LUMEN_API __attribute__((visibility("default")))
	#else
		#define LUMEN_API
	#endif
#else
#error "Unknown Platform!"
#endif

#define LUMEN_VERSION_MAJOR 0
#define LUMEN_VERSION_MINOR 1
#define LUMEN_VERSION_PATCH 0


#define LUMEN_INFO(...) Lumen::Logger::Instance().GetClientLogger()->info(__VA_ARGS__)
#define LUMEN_ERROR(...) Lumen::Logger::Instance().GetClientLogger()->error(__VA_ARGS__)
#define LUMEN_WARN(...) Lumen::Logger::Instance().GetClientLogger()->warn(__VA_ARGS__)
#define LUMEN_FATAL(...) Lumen::Logger::Instance().GetClientLogger()->critical(__VA_ARGS__)
#define LUMEN_TRACE(...) Lumen::Logger::Instance().GetClientLogger()->trace(__VA_ARGS__)
#define LUMEN_ASSERT(x, msg) if (!x){ LUMEN_FATAL("{}\n\t{}\n\tin file: {}\n\ton line{}", #x, msg, __FILE__, __LINE__); __debugbreak();}

#ifdef DEBUG

#define LUMEN_CORE_INFO(...) Lumen::Logger::Instance().GetCoreLogger()->info(__VA_ARGS__)
#define LUMEN_CORE_ERROR(...) Lumen::Logger::Instance().GetCoreLogger()->error(__VA_ARGS__)
#define LUMEN_CORE_WARN(...) Lumen::Logger::Instance().GetCoreLogger()->warn(__VA_ARGS__)
#define LUMEN_CORE_FATAL(...) Lumen::Logger::Instance().GetCoreLogger()->critical(__VA_ARGS__)
#define LUMEN_CORE_TRACE(...) Lumen::Logger::Instance().GetCoreLogger()->trace(__VA_ARGS__);
#define LUMEN_CORE_ASSERT(x, msg) if (!x){ LUMEN_CORE_FATAL("{}\n\t{}\n\tin file: {}\n\ton line{}", #x, msg, __FILE__, __LINE__); __debugbreak();}

#endif

#define BIT(X) (1 << X)
