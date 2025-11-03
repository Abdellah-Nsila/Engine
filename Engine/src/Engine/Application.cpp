#include "enginepch.h"
#include "Engine/Application.h"
#include "Engine/Events/ApplicationEvent.h"

namespace Engine
{

	// std::bind “binds” a member function with an instance (the this pointer)
	// and produces a callable that matches the needed function signature.
	#define BIND_EVENT_FN(x)	std::bind(&x, this, std::placeholders::_1)

	Application::Application()
	{
		this->m_Window = std::unique_ptr<Window>(Window::Create());
		// OnEvent is a member function, which means it implicitly takes a hidden this pointer — so its type is:
		// void (Application::*)(Event&)
		this->m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
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
			glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			this->m_Window->OnUpdate();
		}
	}

	void	Application::OnEvent(Event& e)
	{
		ENGINE_CORE_INFO(e.ToString());
	}
}
