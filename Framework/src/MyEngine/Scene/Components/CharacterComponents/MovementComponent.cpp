#include <MyEngine/Utils/pch.h>

#include "MyEngine/Scene/Components/CharacterComponents/MovementComponent.h"

namespace MyEngine {

	MovementComponent::MovementComponent() : Component("Movement Component")
	{
		speed = 10;
		controller = nullptr;
		transform = nullptr;
	}

	MovementComponent::~MovementComponent()
	{
		delete controller;
		delete transform;
	}

	sf::Vector2f MovementComponent::getVelocity() const
	{
		auto motion = controller->getAxisVector();
		return { motion.x * speed, motion.y * speed };
	}

	sf::Vector2f MovementComponent::getMotionVector() const
	{
		const auto velocity = getVelocity();
		const float lenght = sqrt(velocity.x * velocity.x + velocity.y * velocity.y);

		if (lenght == 0.0f) return { 0,0 };

		return { velocity.x / lenght, velocity.y / lenght };
	}

	void MovementComponent::onUpdate(const float deltaTime)
	{
		if (!motionIsValid()) return;

		auto nextPosition = transform->getTransform()->getPosition() + sf::Vector2f(getMotionVector().x * speed * deltaTime, getMotionVector().y * speed * deltaTime);

		std::cout << "New pos: " << nextPosition.x << ", " << nextPosition.y << "\n";
		transform->setPosition(nextPosition.x, nextPosition.y);
	}

	void MovementComponent::onFixedUpdate(const float deltaTime)
	{

	}
}