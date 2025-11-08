#pragma once

#include "Engine/Input.h"

namespace Engine
{
	class LinuxInput : public Input
	{
		public:
			bool IsKeyPressedImpl(int keycode) override;
			bool IsMouseButtonPressedImpl(int button) override;
			std::pair<float, float> GetMousePositionImpl() override;
			float GetMouseXImpl() override;
			float GetMouseYImpl() override;
	};
	
	
}