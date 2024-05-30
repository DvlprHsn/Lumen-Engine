#pragma once

#include "Event.h"
#include <sstream>

namespace Lumen
{
	class MouseButtonEvent : public Event
	{
	protected:
		int m_code{};
		
	public:
		MouseButtonEvent(int code)
			:m_code(code) {};
		virtual ~MouseButtonEvent() = default;

		LUMEN_EVENT_CATEGORY(EventCategory::EvCategoryMouse)
	};

	class MouseClickEvent : public MouseButtonEvent
	{
	private:
		bool m_repeat {false};

	public:
		MouseClickEvent(int code, bool repeat)
			: MouseButtonEvent(code), m_repeat(repeat) {}
		~MouseClickEvent() = default;

		LUMEN_EVENT_TYPE(EventType::EvMouseClick)

		virtual std::string ToString() const override
		{
			std::stringstream ss{};
			ss << "Mouse Button Clicked Event : " << m_code << ", Repeat " << m_repeat;
			return ss.str();
		}
	};

	class MouseReleaseEvent : public MouseButtonEvent
	{
	private:

	public:
		MouseReleaseEvent(int code)
			:MouseButtonEvent(code) {}
		~MouseReleaseEvent() = default;

		virtual std::string ToString() const override
		{
			std::stringstream ss{};
			ss << "Mouse Button Release Event : " << m_code;
			return ss.str();
		}

		LUMEN_EVENT_TYPE(EventType::EvMouseRelease)

	};

	class MouseMoveEvent : public Event
	{
	private:
		int m_x{};
		int m_y{};

	public:
		MouseMoveEvent(const int& x, const int& y)
			:m_x(x), m_y(y) {}
		~MouseMoveEvent() = default;

		int GetPosX() const
		{
			return m_x;
		}

		int GetPosY() const
		{
			return m_y;
		}

		LUMEN_EVENT_CATEGORY(EventCategory::EvCategoryMouse)
		LUMEN_EVENT_TYPE(EventType::EvMouseMove)

			virtual std::string ToString() const override
		{
			std::stringstream ss{};
			ss << "Mouse Position Event: " << m_x << " , " << m_y;
			return ss.str();
		}


	};

	class MouseScrollEvent : public Event
	{
	private:
		int m_offset_x{};
		int m_offset_y{};

	public:
		MouseScrollEvent(const int& offset_x, const int& offset_y)
			:m_offset_x(offset_x), m_offset_y(offset_y) {}
		~MouseScrollEvent() = default;
		
		int GetOffsetX() const
		{
			return m_offset_x;
		}

		int GetOffsetY() const
		{
			return m_offset_y;
		}

		LUMEN_EVENT_CATEGORY(EventCategory::EvCategoryMouse)
		LUMEN_EVENT_TYPE(EventType::EvMouseScroll)

		virtual std::string ToString() const override
		{
			std::stringstream ss{};
			ss << "Mouse Scroll Event : " << m_offset_x << " , " << m_offset_y;
			return ss.str();
		}

	};
}