#pragma once

#include "enginepch.h"
#include "Engine/Events/Event.h"

namespace Engine
{
	
	// KeyEvent Base Class has two derived: KeyPressedEvent && KeyReleasedEvent
	class KeyEvent : public Event
	{

		public:
			inline int	GetKeyCode() const { return this->m_KeyCode; };
			EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
		protected:
			KeyEvent(int keycode) : m_KeyCode(keycode) {};
			int	m_KeyCode;

	};

	class KeyPressedEvent : public KeyEvent
	{
		public:
			KeyPressedEvent(int keycode, int repeatCount) : KeyEvent(keycode), m_ReapeatCount(repeatCount) {};
			inline int	GetReapeatCount() const { return m_ReapeatCount; };
			std::string	ToString() const override
			{
				std::stringstream	ss;
				ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_ReapeatCount << " repeats)";
				return ss.str();
			}
			EVENT_CLASS_TYPE(KeyPressed)
		private:
			int	m_ReapeatCount;
	};

	class KeyReleasedEvent : public KeyEvent
	{
		public:
			KeyReleasedEvent(int keycode, int repeatCount) : KeyEvent(keycode), m_ReapeatCount(repeatCount) {};
			inline int	GetReapeatCount() const { return m_ReapeatCount; };
			std::string	ToString() const override
			{
				std::stringstream	ss;
				ss << "KeyReleasedEvent: " << m_KeyCode << " (" << m_ReapeatCount << " repeats)";
				return ss.str();
			}
			EVENT_CLASS_TYPE(KeyReleased)
		private:
			int	m_ReapeatCount;
	};

}