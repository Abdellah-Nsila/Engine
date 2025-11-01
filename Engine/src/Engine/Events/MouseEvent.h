#pragma once

#include "Engine/Events/Event.h"
#include <sstream>

namespace Engine
{

	// MouseMovedEvent
	class MouseMovedEvent : public Event
	{
		public:
			MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y) {};
			inline float	GetX() const { return this->m_MouseX; };
			inline float	GetY() const { return this->m_MouseY; };
			std::string	ToString() const override
			{
				std::stringstream	ss;
				ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
				return ss.str();
			}
			EVENT_CLASS_TYPE(MouseMoved)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
		protected:
			float	m_MouseX;
			float	m_MouseY;
	};

	// MouseScrolledEvent
	class MouseScrolledEvent : public Event
	{
		public:
			MouseScrolledEvent(float x, float y) : m_XOffset(x), m_YOffset(y) {};
			inline float	GetX() const { return this->m_XOffset; };
			inline float	GetY() const { return this->m_YOffset; };
			std::string	ToString() const override
			{
				std::stringstream	ss;
				ss << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
				return ss.str();
			}
			EVENT_CLASS_TYPE(MouseScrolled)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
		protected:
			float	m_XOffset;
			float	m_YOffset;
	};

	// MouseButtonEvent Base Class has two derived: MouseButtonPressedEvent && MouseButtonReleasedEvent
	class MouseButtonEvent : public Event
	{
		public:
			inline float	GetMouseButton() const { return this->m_Button; };
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
		protected:
			MouseButtonEvent(int button) : m_Button(button) {};
			int	m_Button;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
		public:
			MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {};
			inline float	GetMouseButton() const { return this->m_Button; };
			std::string	ToString() const override
			{
				std::stringstream	ss;
				ss << "MouseButtonPressedEvent: " << m_Button;
				return ss.str();
			}
			EVENT_CLASS_TYPE(MouseButtonPressed)
		protected:
			int	m_Button;
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
		public:
			MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {};
			inline float	GetMouseButton() const { return this->m_Button; };
			std::string	ToString() const override
			{
				std::stringstream	ss;
				ss << "MouseButtonReleasedEvent: " << m_Button;
				return ss.str();
			}
			EVENT_CLASS_TYPE(MouseButtonReleased)
		protected:
			int	m_Button;
	};


	
	
}