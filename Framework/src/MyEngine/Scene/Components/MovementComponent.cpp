#include "MyEngine/Utils/pch.h"
#include "MovementComponent.h"

MyEngine::MovementComponent::MovementComponent() : Component("Movement Component")
{
	speed = 10;
	controller = nullptr;
	transform = nullptr;
}

MyEngine::MovementComponent::~MovementComponent()
{
	delete controller;
	delete transform;
}

sf::Vector2f MyEngine::MovementComponent::getVelocity() const
{
	auto motion = controller->getAxisVector();
	return { motion.x * speed, motion.y * speed };
}

sf::Vector2f MyEngine::MovementComponent::getMotionVector() const
{
	const auto velocity = getVelocity();
	const float lenght = sqrt(velocity.x * velocity.x + velocity.y * velocity.y);

	if (lenght == 0.0f) return { 0,0 };

	return { velocity.x / lenght, velocity.y / lenght };
}

void MyEngine::MovementComponent::onUpdate(const float deltaTime)
{
	if (!motionIsValid()) return;

	auto nextPosition = transform->getTransform()->getPosition() + sf::Vector2f(getMotionVector().x * speed * deltaTime, getMotionVector().y * speed * deltaTime);

	std::cout << "New pos: " << nextPosition.x << ", " << nextPosition.y << "\n";
	transform->setPosition(nextPosition.x, nextPosition.y);
}

void MyEngine::MovementComponent::onFixedUpdate(const float deltaTime)
{

}