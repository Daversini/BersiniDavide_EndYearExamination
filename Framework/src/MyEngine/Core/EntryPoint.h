#ifndef ENTRY_POINT_H
#define ENTRY_POINT_H

#include "Application.h"

extern MyEngine::Application* MyEngine::createApplication();

int main()
{
	auto app = MyEngine::createApplication();

	app->run();

	delete app;
	return 0;
}

#endif // !ENTRY_POINT_H