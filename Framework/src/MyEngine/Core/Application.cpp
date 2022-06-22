#include "pch.h"
#include "MyEngine/Core/Application.h"

namespace MyEngine {

	Application* Application::m_istance = nullptr;

	Application::Application(float width, float height, const char* title) :
		m_Window(nullptr),
		maxFPS(0),
		windowWidth(width),
		windowHeight(height),
		windowTitle(title)
	{
		initApp();
	}

	void Application::pushLayer(Layer* layer)
	{
		m_layer = layer;
		layer->onAttach();
	}

	void Application::initApp()
	{
		createWindow();

		//TODO
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
			std::cout << "FPS: " << getFrameRate() << std::endl;
			processWindowEvents();

			while (lag < msForFixedUpdate)
			{
				fixedUpdate();
				lag -= msForFixedUpdate;
			}
			update();
			sf::sleep(sf::seconds((1.0f / maxFPS)));
		}
	}

	void Application::updateGameTime()
	{
		currentTime = time.getCurrentTime();
		elapsedTime = Timer::calculateElapsedTime(currentTime.asSeconds(), lastTime.asSeconds());
		lag += elapsedTime;
		lastTime = currentTime;
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
		//TODO
	}

	void Application::update()
	{
		m_layer->onUpdate(elapsedTime);

		//TODO
	}

	void Application::draw()
	{
		m_Window->clear(sf::Color::Black);

		//TODO

		m_Window->display();
	}
}