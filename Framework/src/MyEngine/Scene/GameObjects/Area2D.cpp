#include <MyEngine/Utils/pch.h>

#include "MyEngine/Scene/GameObjects/Area2D.h"

namespace MyEngine {

	Area2D::Area2D() : GameObject("Area 2D")
	{
		rectangleTransform = new RectTransform();
		rectangleTransform->setScale(32, 32);
		rectangleTransform->getTransform()->setFillColor(sf::Color::White);

		addComponent(rectangleTransform);
	}

	Area2D::~Area2D()
	{
		delete rectangleTransform;
	}
}