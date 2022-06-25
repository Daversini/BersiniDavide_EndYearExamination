#ifndef AREA2D_H
#define AREA2D_H

#include <MyEngine/Utils/ProjectExport.h>

#include <MyEngine/Scene/GameObjects/GameObject.h>
#include <MyEngine/Scene/Components/RectTransform.h>

namespace MyEngine {

	class MYENGINEAPI Area2D : public MyEngine::GameObject
	{
	public:
		Area2D();
		~Area2D() override;

		RectTransform* rectangleTransform;
	};
}

#endif // !AREA2D_H