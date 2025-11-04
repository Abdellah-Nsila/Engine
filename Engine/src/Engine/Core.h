#pragma once

#if defined(__GNUC__) || defined(__clang__)
    #include <signal.h>
    #define DEBUGBREAK() raise(SIGTRAP)
#elif defined(_MSC_VER)
    #define DEBUGBREAK() __debugbreak()
#else
    #define DEBUGBREAK() ((void)0)
#endif


#ifdef ENGINE_ENABLE_ASSERTS
	#define ENGINE_ASSERT(x, ...) { if (!(x)) { ENGINE_ERROR("Assertion Failed: {0}", __VA_ARGS__); DEBUGBREAK(); } }
	#define ENGINE_CORE_ASSERT(x, ...) { if (!(x)) { ENGINE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); DEBUGBREAK(); } }
#else
	#define ENGINE_ASSERT(x, ...)
	#define ENGINE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)