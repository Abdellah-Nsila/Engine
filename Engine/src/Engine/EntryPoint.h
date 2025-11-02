#pragma once

#include "Engine/Application.h"
#include "Engine/Window.h"
#include "Engine/Log.h"

#include <spdlog/spdlog.h>

extern Engine::Application* Engine::CreateApplication();

#ifdef ENGINE_PLATFORM_LINUX
	int	main(int argc, char** argv)
	{
		Engine::Log::Init();
		ENGINE_CORE_WARN("Initialize Log!");
		const char *s = "GG";
		ENGINE_INFO("Hello Client VAR={0}", s);
	
		auto app = Engine::CreateApplication();
		app->Run();
		delete app;
	}
#else
	#error Engine only supports Linux!
#endif

