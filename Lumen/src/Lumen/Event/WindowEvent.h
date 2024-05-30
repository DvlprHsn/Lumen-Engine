#pragma once

#include "Event.h"

namespace Lumen
{
	class WindowCloseEvent : public Event
	{
	private:

	public:
		WindowCloseEvent() = default;
		~WindowCloseEvent() = default;

		LUMEN_EVENT_CATEGORY(EventCategory::EvCategoryWindow)
		LUMEN_EVENT_TYPE(EventType::EvWindowClose)

		virtual std::string ToString() const override
		{
			std::stringstream ss{};
			ss << "Window Close Event";
			return ss.str();
		}
	};

	class WindowResizeEvent : public Event
	{
	private:
		int m_w{};
		int m_h{};

	public:
		WindowResizeEvent(const int& w, const int& h)
			:m_w(w), m_h(h) {}
		~WindowResizeEvent() = default;

		int GetWidth() const
		{
			return m_w;
		}

		int GetHeight() const
		{
			return m_h;
		}

		LUMEN_EVENT_CATEGORY(EventCategory::EvCategoryWindow)
		LUMEN_EVENT_TYPE(EventType::EvWindowResize)

		virtual std::string ToString() const override
		{
			std::stringstream ss{};
			ss << "Window Resize Event : " << m_w << " , " << m_h;
			return ss.str();
		}
	};

	class WindowMinimizeEvent : public Event
	{
	private:

	public:
		WindowMinimizeEvent() = default;
		~WindowMinimizeEvent() = default;

		LUMEN_EVENT_CATEGORY(EventCategory::EvCategoryWindow)
		LUMEN_EVENT_TYPE(EventType::EvWindowMinimize)
			
		virtual std::string ToString() const override
		{
			std::stringstream ss{};
			ss << "Window Minimize Event";
			return ss.str();
		}
	};

	class WindowMaximizeEvent : public Event
	{
	private:

	public:
		WindowMaximizeEvent() = default;
		~WindowMaximizeEvent() = default;

		LUMEN_EVENT_CATEGORY(EventCategory::EvCategoryWindow)
		LUMEN_EVENT_TYPE(EventType::EvWindowMaximize)

		virtual std::string ToString() const override
		{
			std::stringstream ss{};
			ss << "Window Maximized Event";
			return ss.str();
		}
	};
}