#include "MyEngine/Utils/pch.h"

#include "SandboxLayer.h"

SandboxLayer::SandboxLayer()
	: Layer("Sandbox")
{}

void SandboxLayer::onAttach()
{
	std::cout << "\n\nStarting Game...\n\n";

	//TODO: Return allEntities
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