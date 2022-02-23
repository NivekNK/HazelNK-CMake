#include "nkpch.h"

#include "Application.h"

#include <GLFW/glfw3.h>

namespace nk
{
#define BIND_EVENT_FN(x) [this](auto&& arg1, auto arg2){ x(std::forward<decltype(arg1)>(arg1), std::forward<decltype(arg2)>(arg2)); SetEventHandle(std::forward<decltype(arg1)>(arg1), std::forward<decltype(arg2)>(arg2)); }

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback([this](auto&& arg) { OnEvent(std::forward<decltype(arg)>(arg)); });

		m_Dispatcher.AddListener(EventType::WindowClose, BIND_EVENT_FN(OnWindowClose));
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& event)
	{
		m_Dispatcher.Dispatch(event, EventType::WindowClose);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(event);
			if (event.Handled)
				break;
		}

		if (event.Handled)
			event.Handled = false;
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
	}

	void Application::OnWindowClose(Event& event, const EventType eventType)
	{
		m_Running = false;
	}

	void Application::SetEventHandle(Event& event, const EventType eventType)
	{
		event.Handled = true;
	}
}
