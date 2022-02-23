#pragma once

#include "Core.h"

#include <spdlog/spdlog.h>
//#include <spdlog/fmt/ostr.h>

namespace nk
{
	class NK_API Log
	{
	public:
		static void Init(std::string pattern = GetDefaultPattern());

		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

		static std::string GetDefaultPattern() { return "%^[%T] %n %l: %v%$"; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Log Macros
#define DebugCoreTrace(...)		::nk::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DebugCoreInfo(...)		::nk::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DebugCoreWarning(...)	::nk::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DebugCoreError(...)		::nk::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DebugCoreFatal(...)		::nk::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client Log Macros
#define DebugTrace(...)			::nk::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DebugInfo(...)			::nk::Log::GetClientLogger()->info(__VA_ARGS__)
#define DebugWarning(...)		::nk::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DebugError(...)			::nk::Log::GetClientLogger()->error(__VA_ARGS__)
#define DebugFatal(...)			::nk::Log::GetClientLogger()->critical(__VA_ARGS__)
