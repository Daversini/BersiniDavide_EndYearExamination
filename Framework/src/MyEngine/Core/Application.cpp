#include "Application.h"

namespace MyEngine {

	Application* Application::m_istance = nullptr;

	Application::Application()
	{
		m_istance = this;
	}

	void Application::Run()
	{
		std::cout << "Hello World!";
		std::cin.get();
	}
}