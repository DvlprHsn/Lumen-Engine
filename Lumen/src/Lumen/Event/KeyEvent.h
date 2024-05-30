#pragma once

#include "Event.h"
#include <sstream>

namespace Lumen
{
	class KeyEvent : public Event
	{
	protected:
		int m_code{};

	public:
		KeyEvent(int code)
			:m_code(code) {};
		virtual ~KeyEvent() = default;

		LUMEN_EVENT_CATEGORY(EventCategory::EvCategoryKey)
	};

	class KeyPressedEvent : public KeyEvent
	{
	private:
		bool m_repeat{ false };

	public:
		KeyPressedEvent(int code, bool repeat)
			: KeyEvent(code), m_repeat(repeat) {}
		~KeyPressedEvent() = default;

		LUMEN_EVENT_TYPE(EventType::EvKeyPressed)

		virtual std::string ToString() const override
		{
			std::stringstream ss{};
			ss << "Key Button Pressed Event : " << m_code << ", Repeat " << m_repeat;
			return ss.str();
		}
	};

	class KeyReleaseEvent : public KeyEvent
	{
	private:

	public:
		KeyReleaseEvent(int code)
			:KeyEvent(code) {}
		~KeyReleaseEvent() = default;

		virtual std::string ToString() const override
		{
			std::stringstream ss{};
			ss << "Key Button Release Event : " << m_code;
			return ss.str();
		}

		LUMEN_EVENT_TYPE(EventType::EvKeyReleased)

	};

}