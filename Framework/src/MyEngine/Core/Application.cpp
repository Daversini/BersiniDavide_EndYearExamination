#include <MyEngine/Utils/pch.h>

#include "MyEngine/Core/Application.h"

#include "MyEngine/Scene/Components/Component.h"
#include "MyEngine/Scene/Components/RenderingComponents/Renderer2D.h"

#include "MyEngine/Scene/GameObjects/Area2D.h"
#include "MyEngine/Scene/GameObjects/RenderedObjects/Sprite.h"

namespace MyEngine {

	Application* Application::m_istance = nullptr;

	Application::Application(float width, float height, const char* title) :
		m_Window(nullptr),
		windowWidth(width),
		windowHeight(height),
		windowTitle(title),

		lag(0),
		maxFPS(0),
		avgFPS(0),
		movAvgAlphaFPS(0.4f),
		SEC_PER_FIXED_UPDATE(0.5),
		fpsLimitEnabled(false),
		m_layer(nullptr)
	{
		initialize();
	}

	void Application::pushLayer(Layer* layer)
	{
		m_layer = layer;
		allEntities = layer->onAttach();
	}

	void Application::initialize()
	{
		std::cout << "Starting Application...\n\n";
		std::cout << "Window settings:\n" << "Width: " << windowWidth << "\n" << "Height: " << windowHeight << "\n\n";

		createWindow();

		font.loadFromFile("resources/fonts/arial.ttf");
		windowTextFPS.setFont(font);
		windowTextFPS.setCharacterSize(30);
		windowTextFPS.setFillColor(sf::Color::White);
		windowTextFPS.move(10.0f, 10.0f);
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

			while (lag >= SEC_PER_FIXED_UPDATE)
			{
				fixedUpdate();
				lag -= SEC_PER_FIXED_UPDATE;
			}

			update();
			render();

			if (fpsLimitEnabled)
				sf::sleep(sf::seconds((1.0f / maxFPS)));
		}

		if (m_layer != nullptr) m_layer->onDetach();
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
		trackFPS();

		for (auto item : allEntities)
		{
			if (item->is_active && item->tickEnabled()) item->onFixedUpdate(deltaTime);
		}
	}

	void Application::update()
	{
		if (m_layer != nullptr) m_layer->onUpdate(deltaTime);

		for (GameObject* item : allEntities)
		{
			if (item->is_active && item->tickEnabled()) item->onUpdate(deltaTime);
		}
	}

	void Application::render()
	{
		m_Window->clear(sf::Color::Black);

		for each (auto item in allEntities)
		{
			const auto components = item->getComponents<RectTransform>();

			for each (auto rend in components)
			{
				m_Window->draw(*rend->getTransform());
			}
		}

		m_Window->draw(windowTextFPS);

		m_Window->display();
	}

	void Application::trackFPS()
	{
		//std::cout << "Frames per sec:	" << getFrameRate() << "\n";
		//std::cout << "Current Lag	" << lag << "\n";
		//std::cout << "Delta Time:	" << deltaTime << "\n\n";

		avgFPS = movAvgAlphaFPS * avgFPS + (1.0 - movAvgAlphaFPS) * getFrameRate();

		std::ostringstream FPSString;
		FPSString << "FPS: " << avgFPS;
		windowTextFPS.setString(FPSString.str());
	}
}