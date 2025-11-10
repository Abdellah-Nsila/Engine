#include <Engine.h>
#include <glm/glm.hpp>

namespace Engine
{

	class ExampleLayer : public Engine::Layer
	{
		public:
			ExampleLayer() : Layer("Example") {};

			void	OnUpdate() override
			{
				if (Input::IsKeyPressed(ENGINE_KEY_TAB))
				{
					ENGINE_TRACE("Tap key is pressed!");
				}
			}

			void	OnEvent(Engine::Event& event) override
			{
				if (event.GetEventType() == Engine::EventType::KeyPressed)
				{
					Engine::KeyPressedEvent& e = (Engine::KeyPressedEvent&)event; 
					if (e.GetKeyCode() == ENGINE_KEY_ESCAPE)
					{
						ENGINE_TRACE("Escape key is pressed!");
					}
				}
			}
	};

	class Sandbox : public Engine::Application
	{
		
		public:
		Sandbox()
		{
			this->PushLayer(new ExampleLayer());
			this->PushOverlay(new Engine::ImGuiLayer());
		}
		
		~Sandbox()
		{
		}
		
	};
	
	Application*	CreateApplication()
	{
		return (new Sandbox());
	}
	
}
