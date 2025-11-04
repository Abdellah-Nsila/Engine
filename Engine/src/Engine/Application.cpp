#include "enginepch.h"
#include "Engine/Application.h"
#include "Engine/Events/ApplicationEvent.h"

#include <glad/glad.h>

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
		this->m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));;
	}
	
	Application::~Application()
	{
	}

	void	Application::Run()
	{
		while (this->m_Running)
		{
			glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : this->m_LayerStack)
				layer->OnUpdate();

			this->m_Window->OnUpdate();
		}
	}

	void	Application::OnEvent(Event& e)
	{
		// OK What is this ???
		// The Story begin with Window Interface, representing a window and its default propeties and pure virtual member functions
		// It provide a setter to update a signature of a function (espacily the argument type event : mouse, key ...)
		// => void(Event&) this is the base signature, we know that we have a Event interface that al events use it
		// so eah event have its diffrent properties, when we Init the The Derived class LinuxWindow (Creating Window)
		// we setup also all events callback, each of them update the EventCallback attribute to its own signature, just the event type chage
		// what is this function , simply its the OnEvent of the application void	OnEvent(Event& e), same signature right
		// this is the tricky part that we update the signature in each event
		// the role of dispatcher is just take the target class type event and matched with the member event then execute the function provided for this event
		// We use BIND_EVENT_FN because if you want to use a member function class in another class we need to bind it early by its own this (self object class)
		EventDispatcher	dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

		for (auto	it = this->m_LayerStack.end(); it != this->m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.IsHandled())
				break ;
		}
	}

	void	Application::PushLayer(Layer* layer)
	{
		this->m_LayerStack.PushLayer(layer);
	}

	void	Application::PushOverlay(Layer* layer)
	{
		this->m_LayerStack.PushOverLay(layer);
	}


	bool	Application::OnWindowClose(WindowCloseEvent& e)
	{
		this->m_Running = false;
		return true;
	}
}
