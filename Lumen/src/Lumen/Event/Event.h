#pragma once

#include "Lumen/Defines.h"

namespace Lumen
{
	enum class EventType
	{
		None = 0,
		EvKeyPressed, EvKeyReleased,
		EvMouseMove, EvMouseClick, EvMouseRelease, EvMouseScroll,
		EvWindowClose, EvWindowResize, EvWindowMinimize, EvWindowMaximize
	};

	enum EventCategory
	{
		None = 0,
		EvCategoryMouse = BIT(1),
		EvCategoryKey = BIT(2),
		EvCategoryWindow = BIT(3)
	};

#define LUMEN_EVENT_TYPE(type) \
static EventType GetStaticEvent() {return type;} \
virtual EventType GetEventType() const override {return GetStaticEvent();} \

#define LUMEN_EVENT_CATEGORY(category) \
virtual unsigned int GetEventCategory() const override {return category;}

	
	class Event
	{
		friend class EventDispatcher;
		friend class Application;
	private:
		bool m_is_handled{ false };

	public:
		Event() = default;
		virtual ~Event() = default;

		virtual EventType GetEventType() const = 0;
		virtual unsigned int GetEventCategory() const = 0;
		virtual std::string ToString() const = 0;

		bool IsHandled() const{ return m_is_handled; }
	};

	class EventDispatcher
	{
	private:
		Event& m_event;

	public:
		EventDispatcher(Event& event) : m_event(event) {};
		~EventDispatcher() = default;

		template <typename T>
		bool Dispatch(std::function<bool(T&)> func)
		{
			if (m_event.GetEventType() == T::GetStaticEvent())
			{
				m_event.m_is_handled = func(dynamic_cast<T&>(m_event));
				return true;
			}

			return false;
		}

	};
}

