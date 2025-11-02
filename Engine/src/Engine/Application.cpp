
#include "Engine/Application.h"
#include "Engine/Events/ApplicationEvent.h"
#include "Engine/Log.h"

namespace Engine
{
	Application::Application()
	{
		this->m_Window = std::unique_ptr<Window>(Window::Create());
	}
	
	Application::~Application()
	{
	}

	void	Application::Run()
	{
		// WindowResizeEvent	e(1080, 720);
		// ENGINE_TRACE(e.ToString());
		while (this->m_Running)
		{
			this->m_Window->OnUpdate();
		}
	}
}
