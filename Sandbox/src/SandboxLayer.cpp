#include <MyEngine/Utils/pch.h>

#include "SandboxLayer.h"

SandboxLayer::SandboxLayer()
	: Layer("Sandbox")
{}

std::vector<MyEngine::GameObject*> SandboxLayer::onAttach()
{
	std::cout << "\n\nStarting Game...\n\n";
	
	background->renderer->setTextureSource("resources/textures/AOT-background.jpg", true, true);
	background->rectangleTransform->setScale(1920, 1080);
	allEntities.push_back(background);

	player->renderer->setTextureSource("resources/textures/Mikasa.png", true, false);
	player->movementComponent->speed = 300;
	player->rectangleTransform->setScale(400, 400);
	player->rectangleTransform->setPosition(1920 / 2 - 400 / 2, 1080 / 2 - 400 / 2);
	allEntities.push_back(player);

	return allEntities;
}

void SandboxLayer::onDetach()
{
	std::cout << "\n\nQuitting Game...\n\n";
}

void SandboxLayer::onUpdate(float deltaTime)
{
	if (player->movementComponent->motionIsValid())
		std::cout << "Character pos: " << player->movementComponent->nextPosition.x << ", " << player->movementComponent->nextPosition.y << "\n";
}

void SandboxLayer::onEvent()
{
	
}