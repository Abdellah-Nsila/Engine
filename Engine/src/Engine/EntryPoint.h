#pragma once

#include "Application.h"
#include "Log.h"

#include <spdlog/spdlog.h>

extern Engine::Application* Engine::CreateApplication();

#ifdef ENGINE_PLATFORM_LINUX
	int	main(int argc, char** argv)
	{
		Engine::Log::Init();
		ENGINE_CORE_WARN("Initilize Log!");
		const char *s = "GG";
		ENGINE_INFO("Hello Client VAR={0}", s);
	
		auto app = Engine::CreateApplication();
		app->Run();
		delete app;
	}
#else
	#error Engine only supports Linux!
#endif


//TODO: Make an Engine Repo and keep Larn_OpenGL to Learning bout API only:
// that have cmake and premake branches
