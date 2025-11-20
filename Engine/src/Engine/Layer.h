#pragma once

#include "enginepch.h"
#include "Engine/Events/Event.h"

namespace Engine
{
	class Layer
	{
		public:
			Layer(const std::string& name = "Layer");
			virtual ~Layer();

			virtual void	OnAttach() {};
			virtual void	OnDetach() {};
			virtual void	OnUpdate() {};
			virtual void	OnImGuiRender() {};
			virtual void	OnEvent(Event& event) {};

			inline const std::string&	GetName() const { return this->GetName(); };
		protected:
			std::string	m_DebugName;
	};

}