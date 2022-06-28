#include <MyEngine/Utils/pch.h>

#include "MyEngine/Scene/GameObjects/Character.h"

namespace MyEngine {

	Character::Character() : Sprite()
	{
		inputController = new InputController();
		addComponent(inputController);

		movementComponent = new MovementComponent();
		movementComponent->controller = inputController;
		movementComponent->transform = rectangleTransform;
		movementComponent->speed = 120;
		addComponent(movementComponent);
	}

	Character::~Character()
	{
		delete movementComponent;
		delete inputController;
	}

	void Character::onUpdate(const float deltaTime)
	{
		Sprite::onUpdate(deltaTime);
	}

	void Character::onFixedUpdate(const float deltaTime)
	{
		Sprite::onFixedUpdate(deltaTime);
	}
}