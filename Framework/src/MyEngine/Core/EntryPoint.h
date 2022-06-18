#pragma once

#include "Application.h"

//extern MyEngine::Application* MyEngine::CreateApplication();

int main()
{
	auto app = MyEngine::CreateApplication();

	app->Run();

	delete app;
	return 0;
}