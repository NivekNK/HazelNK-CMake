#pragma once

#include "Event.h"

namespace nk
{
	class NK_API KeyEvent : public Event
	{
	public:
		int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(const int keycode)
			: m_KeyCode(keycode) {}

		int m_KeyCode;
	};

	class NK_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(const int keycode, const int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {}

		int GetRepeatCunt() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			return fmt::format("{}: {} ({} repeats)", GetName(), m_KeyCode, m_RepeatCount);
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};

	class NK_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(const int keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override
		{
			return fmt::format("{}: {}", GetName(), m_KeyCode);
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class NK_API KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(const int keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override
		{
			return fmt::format("{}: {}", GetName(), m_KeyCode);
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};
}