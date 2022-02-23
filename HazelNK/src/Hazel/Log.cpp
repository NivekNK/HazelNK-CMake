#include "nkpch.h"

#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace nk
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	//TODO: Integrate a better console color format
	void Log::Init(std::string pattern)
	{
		spdlog::set_pattern(std::move(pattern));
		s_CoreLogger = spdlog::stdout_color_mt("NK");
		s_CoreLogger->set_level(spdlog::level::trace);
		const auto coreLoggerSink = dynamic_cast<spdlog::sinks::stdout_color_sink_mt*>(s_CoreLogger->sinks().back().get());
#ifdef NK_PLATFORM_WINDOWS
		coreLoggerSink->set_color(spdlog::level::trace, FOREGROUND_GREEN | FOREGROUND_BLUE);
		coreLoggerSink->set_color(spdlog::level::info, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#endif
		s_ClientLogger = spdlog::stderr_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
		const auto clientLoggerSink = dynamic_cast<spdlog::sinks::stderr_color_sink_mt*>(s_ClientLogger->sinks().back().get());
#ifdef NK_PLATFORM_WINDOWS
		clientLoggerSink->set_color(spdlog::level::trace, FOREGROUND_GREEN | FOREGROUND_BLUE);
		clientLoggerSink->set_color(spdlog::level::info, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#endif
	}
}
