#pragma once

#ifdef NK_PLATFORM_WINDOWS

extern nk::Application* nk::CreateApplication();

int main(int argc, char** argv)
{
	nk::Log::Init();

	DebugCoreTrace("Hola {}", "Mundo");
	DebugCoreInfo("Hola {}", "Mundo");
	DebugCoreWarning("Hola {}", "Mundo");
	DebugCoreError("Hola {}", "Mundo");
	DebugCoreFatal("Hola {}", "Mundo");

	DebugTrace("Hola {}", "Mundo");
	DebugInfo("Hola {}", "Mundo");
	DebugWarning("Hola {}", "Mundo");
	DebugError("Hola {}", "Mundo");
	DebugFatal("Hola {}", "Mundo");

	auto app = nk::CreateApplication();
	app->Run();
	delete app;
}

#endif
