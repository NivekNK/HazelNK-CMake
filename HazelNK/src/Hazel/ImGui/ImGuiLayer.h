#pragma once

#include <imgui.h>

#include "Hazel/Layer.h"

namespace nk
{
	class NK_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() override;

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& event) override;

		static ImGuiKey ImGui_ImplGlfw_KeyToImGuiKey(int key);
	private:
		float m_Time = 0.0f;
	};
}
