#pragma once

#include "enginepch.h"
#include "Engine/Core.h"
#include "Engine/Window.h"
#include "Engine/Events/Event.h"
#include "Engine/Events/ApplicationEvent.h"
#include "Engine/Layer.h"
#include "Engine/LayerStack.h"

namespace Engine
{

	class Application
	{
		public:
			Application();
			virtual ~Application();
			void	Run();
			void	OnEvent(Event& e);

			void	PushLayer(Layer* layer);
			void	PushOverlay(Layer* layer);
		private:
			bool	OnWindowClose(WindowCloseEvent& e);
			std::unique_ptr<Window> m_Window;
			bool					m_Running = true;
			LayerStack				m_LayerStack;
	};

	// To be defined in CLIENT
	Application*	CreateApplication();

}
