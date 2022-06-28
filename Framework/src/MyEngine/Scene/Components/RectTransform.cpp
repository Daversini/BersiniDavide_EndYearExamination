#include <MyEngine/Utils/pch.h>

#include "MyEngine/Scene/Components/RectTransform.h"

MyEngine::RectTransform::RectTransform() : Component("Rectangle Transform")
{
	// disables update and fixed update callbacks (Inherited via ITickable interface)
	disable();

	position = sf::Vector2f(1920/2, 1080/2);
	scale = sf::Vector2f(1, 1);
	rotation = 0;

	rectangleTransform = new sf::RectangleShape(scale);
}

MyEngine::RectTransform::RectTransform(sf::Vector2f position, float rotation, sf::Vector2f scale) : Component("Rectangle Transform")
{
	// disables update and fixed update callbacks (Inherited via ITickable interface)
	disable();

	this->position = position;
	this->rotation = rotation;
	this->scale = scale;

	rectangleTransform = new sf::RectangleShape(scale);
}

MyEngine::RectTransform::~RectTransform()
{
	delete rectangleTransform;
}

void MyEngine::RectTransform::setPosition(float x, float y) const
{
	rectangleTransform->setPosition(x, y);
}

void MyEngine::RectTransform::setRotation(float angle) const
{
	rectangleTransform->setRotation(angle);
}

void MyEngine::RectTransform::setScale(float x, float y) const
{
	rectangleTransform->setScale(x, y);
}

sf::RectangleShape* MyEngine::RectTransform::getTransform() const
{
	return rectangleTransform;
}
