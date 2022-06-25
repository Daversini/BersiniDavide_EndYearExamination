#ifndef AREA2D_H
#define AREA2D_H

#include <MyEngine/Scene/GameObjects/GameObject.h>
#include <MyEngine/Scene/Components/RectTransform.h>

namespace MyEngine {

	class Area2D : public GameObject
	{
	public:
		Area2D();
		~Area2D() override;

		RectTransform* rectangleTransform;
	};
}

#endif // !AREA2D_H