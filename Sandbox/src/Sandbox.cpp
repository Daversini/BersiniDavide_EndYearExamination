#include <MyEngine.h>
#include <MyEngine/Core/EntryPoint.h>

#include "SandboxLayer.h"

class Sandbox : public MyEngine::Application
{
public:
	Sandbox(float windowWidth, float windowHeight, const char* title, int maxFPS)
		: Application(windowWidth, windowHeight, title, maxFPS)
	{
		// Game Settings
		SEC_PER_FIXED_UPDATE = 0.5;
		fpsLimitEnabled = true;

		// Push SandboxLayer to Application
		pushLayer(new SandboxLayer);
	}

	~Sandbox() { delete m_Window; }
};

MyEngine::Application* MyEngine::createApplication()
{
	return new Sandbox(1920, 1080, "Sandbox", 60);
}