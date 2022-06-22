#include <MyEngine.h>
#include <MyEngine/Core/EntryPoint.h>

#include "SandboxLayer.h"

class Sandbox : public MyEngine::Application
{
public:
	Sandbox(float windowWidth, float windowHeight, const char* title)
		: Application(windowWidth, windowHeight, title)
	{
		setMaxFPS(60);
		pushLayer(new SandboxLayer);
	}

	~Sandbox() {}
};

MyEngine::Application* MyEngine::createApplication()
{
	return new Sandbox(1920, 1080, "Sandbox");
}