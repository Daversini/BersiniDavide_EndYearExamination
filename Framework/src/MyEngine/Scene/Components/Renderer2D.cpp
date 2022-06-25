#include <MyEngine/Utils/pch.h>

#include "MyEngine/Scene/Components/Renderer2D.h"
#include "MyEngine/Scene/GameObjects/Area2D.h"

namespace MyEngine {

	Renderer2D::Renderer2D() : Component("Renderer 2D")
	{
		source = nullptr;
	}

	Renderer2D::Renderer2D(std::string sourcePath, bool smooth, bool repeat) : Component("Renderer 2D")
	{
		source = new sf::Texture();
		source->create(10, 10);
		if (!source->loadFromFile(sourcePath))
		{
			std::cout << "Can't load texture at path " << sourcePath.c_str() << "\n";
			return;
		}
		source->setSmooth(smooth);
		source->setRepeated(repeat);

		const auto rect = getOwner()->getComponent<RectTransform>();
		if (!rect)
		{
			std::cout << "Can't load rectangle transform from component owner\n";
			return;
		}

		rect->getTransform()->setTexture(source);
	}

	Renderer2D::~Renderer2D()
	{
		delete source;
	}

	void Renderer2D::setTextureSource(std::string sourcePath, bool smooth, bool repeat)
	{
		delete source;
		source = new sf::Texture();
		if (!source->loadFromFile(sourcePath))
		{
			std::cout << "Can't load texture at path " << sourcePath.c_str() << "\n";
			return;
		}

		source->setSmooth(smooth);
		source->setRepeated(repeat);

		const auto owner = dynamic_cast<Area2D*>(getOwner());
		if (!owner)
		{
			std::cout << "Owner casting failed!\n";
			return;
		}

		owner->rectangleTransform->getTransform()->setTexture(source);
	}
}