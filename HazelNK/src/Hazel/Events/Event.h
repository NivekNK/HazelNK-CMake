#pragma once

#include "Hazel/Core.h"

#include <fmt/format.h>
#include <eventpp/eventdispatcher.h>

namespace nk
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
							   virtual EventType GetEventType() const override { return GetStaticType(); }\
							   virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class NK_API Event
	{
	public:
		bool Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		bool IsInCategory(const EventCategory category) const { return GetCategoryFlags() & category; }
	};

	template<typename E>
	class EventDispatcher
	{
	public:
		struct EventPolicies
		{
			static EventType getEvent(const Event& e, const EventType eventType)
			{
				if (e.GetEventType() == eventType)
					return e.GetEventType();

				return EventType::None;
			}
		};

		using Dispatcher = eventpp::EventDispatcher<EventType, void(E&, EventType), EventPolicies>;
		using Handle = typename Dispatcher::Handle;
		using Callback = typename Dispatcher::Callback;

		EventDispatcher() = default;

		Handle AddListener(const EventType eventType, const Callback& callback)
		{
			return m_Dispatcher.appendListener(eventType, callback);
		}

		bool RemoveListener(const EventType eventType, const Handle handle)
		{
			return m_Dispatcher.removeListener(eventType, handle);
		}

		Dispatcher GetDispatcher() const { return m_Dispatcher; }

		void Dispatch(E& event) { m_Dispatcher.dispatch(event, event.GetEventType()); }

		template<typename... Args>
		void Dispatch(E& event, Args&&... args) { m_Dispatcher.dispatch(event, args...); }
	private:
		Dispatcher m_Dispatcher;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

	template <typename T>
	struct fmt::formatter<T, std::enable_if_t<std::is_base_of_v<nk::Event, T>, char>> : formatter<std::string>
	{
		template <typename FormatContext>
		auto format(const nk::Event& e, FormatContext& ctx)
		{
			return formatter<std::string>::format(e.ToString(), ctx);
		}
	};
}
