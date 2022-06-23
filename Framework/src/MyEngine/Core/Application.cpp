#include "MyEngine/Utils/pch.h"
#include "MyEngine/Core/Application.h"

namespace MyEngine {

	Application* Application::m_istance = nullptr;

	Application::Application(float width, float height, const char* title) :
		m_Window(nullptr),
		maxFPS(0),
		windowWidth(width),
		windowHeight(height),
		windowTitle(title),
		lag(0)
	{
		createWindow();
	}

	void Application::pushLayer(Layer* layer)
	{
		m_layer = layer;
		layer->onAttach();
	}

	void Application::createWindow()
	{
		m_Window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), windowTitle);
		if (!m_Window)
		{
			std::cerr << "Application window initialization failed!\n";
			return;
		}
	}

	void Application::run()
	{
		lastTime = time.getCurrentTime();
		while (m_Window->isOpen())
		{
			updateGameTime();
			processWindowEvents();

			if (fixedUpdateEnabled)
			{
				while (lag >= SEC_PER_FIXED_UPDATE)
				{
					fixedUpdate();
					lag -= SEC_PER_FIXED_UPDATE;
				}
			}

			update();
			render();

			if (fpsLimitEnabled)
				sf::sleep(sf::seconds((1.0f / maxFPS)));
		}

		m_layer->onDetach();
	}

	void Application::updateGameTime()
	{
		currentTime = time.getCurrentTime();
		deltaTime = Timer::calculateElapsedTime(currentTime.asSeconds(), lastTime.asSeconds());
		lastTime = currentTime;
		lag += deltaTime;
	}

	void Application::processWindowEvents()
	{
		sf::Event evt{};
		while (m_Window->pollEvent(evt))
		{
			if (evt.type == sf::Event::EventType::Closed)
			{
				m_Window->close();
			}
		}
	}

	void Application::fixedUpdate()
	{
		std::cout << "\n\n\n\n\n\nFIXED UPDATE\n\n\n\n\n\n";

		//TODO
	}

	void Application::update()
	{
		m_layer->onUpdate(deltaTime);

		std::cout << "Frames per sec:	" << getFrameRate() << "\n";
		std::cout << "Current Lag	" << lag << "\n";
		std::cout << "Delta Time:	" << deltaTime << "\n\n";

		//TODO
	}

	void Application::render()
	{
		m_Window->clear(sf::Color::Black);

		//TODO

		m_Window->display();
	}
}