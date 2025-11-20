#pragma once

#include "enginepch.h"
#include "imgui.h"

#include "Engine/Layer.h"
#include "Engine/Events/Event.h"
#include "Engine/Events/ApplicationEvent.h"
#include "Engine/Events/KeyEvent.h"
#include "Engine/Events/MouseEvent.h"

namespace Engine
{
	class ImGuiLayer : public Layer
	{
		public:
			ImGuiLayer();
			~ImGuiLayer();

			void	OnAttach() override;
			void	OnDetach() override;
			void	OnImGuiRender() override;

			void	Begin();
			void	End();

			static ImGuiKey	MapToImGuiKey(int keycode);
		private:
			float	m_Time = 0.0f;
	};
	
}