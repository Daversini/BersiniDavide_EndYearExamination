#include <MyEngine/Utils/pch.h>

#include "MyEngine/Scene/GameObjects/RenderedObjects/Sprite.h"

namespace MyEngine {

	Sprite::Sprite()
	{
		renderer = new Renderer2D();
		addComponent(renderer);
	}

	Sprite::~Sprite()
	{
		delete rectangleTransform;
		delete renderer;
	}
}