#include <Engine.h>

namespace Engine
{

	class Sandbox : public Engine::Application
	{
		
		public:
		Sandbox()
		{
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
