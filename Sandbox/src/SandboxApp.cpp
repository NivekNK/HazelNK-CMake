#include <Hazel.h>

class ExampleLayer : public nk::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override
	{
		//DebugInfo("ExampleLayer::Update");
	}

	void OnEvent(nk::Event& event) override
	{
		//DebugTrace(event);
	}
};

class Sandbox : public nk::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{
		
	}
};

nk::Application* nk::CreateApplication()
{
	return new Sandbox();
}