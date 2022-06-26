#include <MyEngine/Utils/pch.h>

#include "SandboxLayer.h"

SandboxLayer::SandboxLayer()
	: Layer("Sandbox")
{}

std::vector<MyEngine::GameObject*> SandboxLayer::onAttach()
{
	std::cout << "\n\nStarting Game...\n\n";

	auto background = new MyEngine::Sprite();
	background->renderer->setTextureSource(resourcesPath + "AOT-background.jpg", true, true);
	background->rectangleTransform->setScale(1920, 1080);
	allEntities.push_back(background);

	const auto player = new MyEngine::Character();
	player->renderer->setTextureSource(resourcesPath + "Mikasa.png", true, false);
	player->rectangleTransform->setScale(250, 250);
	player->rectangleTransform->setPosition(960 - 125, 540 - 125);
	allEntities.push_back(player);

	return allEntities;
}

void SandboxLayer::onDetach()
{
	std::cout << "\n\nQuitting Game...\n\n";
}

void SandboxLayer::onUpdate(float deltaTime)
{
	//TODO
}

void SandboxLayer::onEvent()
{
	//TODO
}