#include "SandboxLayer.h"

#include <iostream>

SandboxLayer::SandboxLayer()
	: Layer("Sandbox")
{}

void SandboxLayer::onAttach()
{
	//TODO
}

void SandboxLayer::onDetach()
{
	std::cout << "\n\nQuitting application...\n\n";
}

void SandboxLayer::onUpdate(float deltaTime)
{
	//TODO
}

void SandboxLayer::onEvent()
{
	//TODO
}
