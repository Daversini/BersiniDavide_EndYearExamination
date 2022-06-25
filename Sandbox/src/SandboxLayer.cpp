#include <MyEngine/Utils/pch.h>

#include "SandboxLayer.h"

SandboxLayer::SandboxLayer()
	: Layer("Sandbox")
{}

std::vector<MyEngine::GameObject*> SandboxLayer::onAttach()
{
	std::cout << "\n\nStarting Game...\n\n";

	auto background = new MyEngine::Sprite();
	background->renderer->setTextureSource("resources/textures/AOT-background.jpg", true, true);
	background->rectangleTransform->setScale(1920, 1080);
	allEntities.push_back(background);

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