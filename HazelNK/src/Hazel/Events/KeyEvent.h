#pragma once

#include "Event.h"

namespace nk
{
	class NK_API KeyEvent : public Event
	{
	public:
		[[nodiscard]] int GetKeyCode() const { return m_KeyCode; }
		[[nodiscard]] int GetMods() const { return m_Mods; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(const int keycode, const int mods)
			: m_KeyCode(keycode), m_Mods(mods) {}

		int m_KeyCode;
		int m_Mods;
	};

	class NK_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(const int keycode, const int mods, const int repeatCount)
			: KeyEvent(keycode, mods), m_RepeatCount(repeatCount) {}

		[[nodiscard]] int GetRepeatCunt() const { return m_RepeatCount; }

		[[nodiscard]] virtual std::string ToString() const override
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
		KeyReleasedEvent(const int keycode, const int mods)
			: KeyEvent(keycode, mods) {}

		[[nodiscard]] virtual std::string ToString() const override
		{
			return fmt::format("{}: {}", GetName(), m_KeyCode);
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class NK_API KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(const int keycode, const int mods)
			: KeyEvent(keycode, mods) {}

		[[nodiscard]] virtual std::string ToString() const override
		{
			return fmt::format("{}: {}", GetName(), m_KeyCode);
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};
}