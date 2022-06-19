#include "MyEngine/Core/Application.h"

#include <iostream>
#include <SFML/Window.hpp>

namespace MyEngine {

	Application* Application::m_istance = nullptr;

	Application::Application()
	{
		m_istance = this;
	}

	void Application::Run()
	{
		//TESTING
		sf::Window window(sf::VideoMode(800, 600), "My Game");
		std::cout << "Hello World!";
		std::cin.get();
	}
}