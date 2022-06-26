#include <MyEngine/Utils/pch.h>

#include "MyEngine/Scene/Components/InputController.h"

namespace MyEngine {

	InputController::InputController() : Component("Input Controller")
	{
		forwardMovement = false;
		rightMovement = false;
		XAxis = 0;
		YAxis = 0;
	}

	InputController::~InputController() = default;

	void InputController::onUpdate(const float deltaTime)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			forwardMovement = true;
			YAxis = -1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			forwardMovement = true;
			YAxis = 1;
		}
		else
		{
			forwardMovement = false;
			YAxis = 0;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			rightMovement = true;
			XAxis = 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			rightMovement = true;
			XAxis = -1;
		}
		else
		{
			forwardMovement = false;
			XAxis = 0;
		}

		std::cout << "Axis: " << XAxis << ", " << YAxis << "\n";
	}

	void InputController::onFixedUpdate(const float deltaTime)
	{
		Component::onFixedUpdate(deltaTime);
	}
}