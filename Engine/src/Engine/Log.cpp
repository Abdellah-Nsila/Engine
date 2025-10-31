#include "Log.h"

namespace Engine
{

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
	
	void	Log::Init()
	{
		// logSinks[0]->set_pattern("%^[%T] %n: %v%$");
		// logSinks[1]->set_pattern("[%T] [%l] %n: %v");
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("ENGINE");
		s_CoreLogger->set_level(spdlog::level::trace);
		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}

}