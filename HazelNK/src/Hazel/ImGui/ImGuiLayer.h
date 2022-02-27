#pragma once

#include "Hazel/Layer.h"
#include "Hazel/Events/Event.h"

#include <imgui.h>

namespace nk
{
	class NK_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		virtual ~ImGuiLayer() override;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		virtual void OnEvent(Event& event) override;

		static ImGuiKey ImGui_ImplGlfw_KeyToImGuiKey(int key);
	private:
		bool OnMouseButtonPressedEvent(Event& e, EventType eventType);
		bool OnMouseButtonReleasedEvent(Event& e, EventType eventType);
		bool OnMouseMovedEvent(Event& e, EventType eventType);
		bool OnMouseScrolledEvent(Event& e, EventType eventType);
		bool OnKeyPressedEvent(Event& e, EventType eventType);
		bool OnKeyReleasedEvent(Event& e, EventType eventType);
		bool OnKeyTypedEvent(Event& e, EventType eventType);
		bool OnWindowResizeEvent(Event& e, EventType eventType);

		float m_Time = 0.0f;
	};
}
