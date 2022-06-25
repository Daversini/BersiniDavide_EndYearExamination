#ifndef SPRITE_H
#define SPRITE_H

#include <MyEngine/Utils/ProjectExport.h>

#include "MyEngine/Scene/GameObjects/Area2D.h"
#include "MyEngine/Scene/Components/Renderer2D.h"

namespace MyEngine {

	class MYENGINEAPI Sprite : public MyEngine::Area2D
	{
	public:
		Sprite();
		~Sprite() override;

		Renderer2D* renderer;
	};
}

#endif // !SPRITE_H