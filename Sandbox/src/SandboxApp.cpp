#include <Engine.h>

namespace Engine
{

	class ExampleLayer : public Engine::Layer
	{
		public:
			ExampleLayer() : Layer("Example") {};

			void	OnUpdate() override
			{
				ENGINE_INFO("ExampleLayer: Update");
			}

			void	OnEvent(Engine::Event& event) override
			{
				ENGINE_TRACE("ExampleLayer: " + event.ToString());
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
