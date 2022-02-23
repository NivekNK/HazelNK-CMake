#pragma once

#include "Hazel/Core.h"

#include "Hazel/Window.h"
#include "Hazel/LayerStack.h"
#include "Hazel/Events/Event.h"

namespace nk
{
	class NK_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& event);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		void OnWindowClose(Event& event, EventType eventType);
		void SetEventHandle(Event& event, EventType eventType);

		EventDispatcher<Event> m_Dispatcher;

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
