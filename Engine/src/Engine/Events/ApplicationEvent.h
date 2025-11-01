#pragma once

#include "enginepch.h"
#include "Engine/Events/Event.h"

namespace Engine
{
	
	// WindowResizeEvent
	class WindowResizeEvent : public Event
	{
		public:
			WindowResizeEvent(float width, float height) : m_Width(width), m_Height(height) {};
			inline float	GetWidth() const { return this->m_Width; };
			inline float	GetHeight() const { return this->m_Height; };
			std::string	ToString() const override
			{
				std::stringstream	ss;
				ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
				return ss.str();
			}
			EVENT_CLASS_TYPE(WindowResize)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
		protected:
			unsigned int	m_Width;
			unsigned int	m_Height;
	};

	// WindowCloseEvent
	class WindowCloseEvent : public Event
	{
		public:
			WindowCloseEvent() {};
			EVENT_CLASS_TYPE(WindowClose)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	// AppTickEvent
	class AppTickEvent : public Event
	{
		public:
			AppTickEvent() {};
			EVENT_CLASS_TYPE(AppTick)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	// AppUpdateEvent
	class AppUpdateEvent : public Event
	{
		public:
			AppUpdateEvent() {};
			EVENT_CLASS_TYPE(AppUpdate)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	// AppRenderEvent
	class AppRenderEvent : public Event
	{
		public:
			AppRenderEvent() {};
			EVENT_CLASS_TYPE(AppRender)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};


}