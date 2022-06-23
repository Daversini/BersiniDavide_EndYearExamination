#include <MyEngine.h>
#include <MyEngine/Core/EntryPoint.h>

#include "SandboxLayer.h"

class Sandbox : public MyEngine::Application
{
public:
	Sandbox(float windowWidth, float windowHeight, const char* title)
		: Application(windowWidth, windowHeight, title)
	{
		// Game Settings
		fixedUpdateEnabled = true;
		fpsLimitEnabled = true;
		maxFPS = 60;
		SEC_PER_FIXED_UPDATE = 2;

		// Push SandboxLayer to Application
		pushLayer(new SandboxLayer);
	}

	~Sandbox() { delete m_Window; }
};

MyEngine::Application* MyEngine::createApplication()
{
	return new Sandbox(1920, 1080, "Sandbox");
}