#pragma once

#include "Engine/Core.h"

namespace Engine
{

	class Application
	{
		public:
			Application(/* args */);
			virtual ~Application();
			void	Run();
		private:
			/* data */
	};

	// To be defined in CLIENT
	Application*	CreateApplication();

}
