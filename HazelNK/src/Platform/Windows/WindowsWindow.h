#pragma once

#include "Hazel/Window.h"

// ReSharper disable once IdentifierTypo
// ReSharper disable once CppInconsistentNaming
struct GLFWwindow;

namespace nk
{
	class WindowsWindow : public Window
	{
	public:
		explicit WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow() override;

		virtual void OnUpdate() override;

		[[nodiscard]] virtual unsigned int GetWidth() const override { return m_Data.Width; }
		[[nodiscard]] virtual unsigned int GetHeight() const override { return m_Data.Height; }

		virtual void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		virtual void SetVSync(bool enabled) override;
		[[nodiscard]] virtual bool IsVSync() const override;
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

		GLFWwindow* m_Window{};

		struct WindowData
		{
			std::string Title;
			unsigned int Width{}, Height{};
			bool VSync{};

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}