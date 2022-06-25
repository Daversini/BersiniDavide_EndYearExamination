#include <MyEngine/Core/EntryPoint.h>

#include "SandboxLayer.h"

class Sandbox : public MyEngine::Application
{
public:
	Sandbox() : Application(1920, 1080, "Sandbox")
	{
		// Game Settings
		enableFPSLimit();
		setMaxFPS(60);

		// Push SandboxLayer to Application
		pushLayer(new SandboxLayer);
	}

	~Sandbox() {}
};

MyEngine::Application* MyEngine::createApplication()
{
	return new Sandbox;
}