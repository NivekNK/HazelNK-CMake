#pragma once

#ifdef NK_PLATFORM_WINDOWS
	#ifdef NK_BUILD_DLL
		#define NK_API __declspec(dllexport) 
	#else
		#define NK_API __declspec(dllimport) 
	#endif
#else
	#error Hazel Only supports Windows!
#endif

#ifdef NK_DEBUG
	#define NK_ENABLE_ASSERTS
#endif

#ifdef NK_ENABLE_ASSERTS
	#define NK_ASSERT(x, ...) { if(!(x)) { DebugError("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define NK_CORE_ASSERT(x, ...) { if(!(x)) { DebugCoreError("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define NK_ASSERT(x, ...)
	#define NK_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define NK_BIND_EVENT_FN(fn) [this](Event& event, const EventType eventType) { event.Handled = fn(event, eventType); }
