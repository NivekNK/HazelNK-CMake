#pragma once

#ifdef NK_PLATFORM_WINDOWS

// TODO: Change this if the creation of the application stop working
//extern nk::Application* nk::CreateApplication();

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

	const auto app = nk::CreateApplication();
	app->Run();
	delete app;
}

#endif
