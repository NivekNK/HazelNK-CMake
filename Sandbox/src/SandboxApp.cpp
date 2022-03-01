#include <Hazel.h>

#include "Events/KeyEvent.h"

class ExampleLayer : public nk::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override
	{
		if (nk::Input::IsKeyPressed(NK_KEY_TAB))
			DebugInfo("Pressed Key Tab!");
	}

	void OnEvent(nk::Event& event) override
	{
		if (event.GetEventType() == nk::EventType::KeyPressed)
		{
			const auto& e = dynamic_cast<nk::KeyPressedEvent&>(event);
			DebugTrace(static_cast<char>(e.GetKeyCode()));
		}
	}
};

class Sandbox : public nk::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new nk::ImGuiLayer());
	}

	~Sandbox()
	{
		
	}
};

nk::Application* nk::CreateApplication()
{
	return new Sandbox();
}