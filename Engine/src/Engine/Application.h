#pragma once

#include "enginepch.h"
#include "Engine/Core.h"
#include "Engine/Window.h"
#include "Engine/Events/Event.h"

namespace Engine
{

	class Application
	{
		public:
			Application();
			virtual ~Application();
			void	Run();
			void	OnEvent(Event& e);
		private:
			std::unique_ptr<Window> m_Window;
			bool					m_Running = true;
	};

	// To be defined in CLIENT
	Application*	CreateApplication();

}
