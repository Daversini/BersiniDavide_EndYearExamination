#ifndef AREA2D_H
#define AREA2D_H

#include <MyEngine/Utils/ProjectExport.h>

#include "MyEngine/Scene/GameObjects/GameObject.h"
#include "MyEngine/Scene/Components/RectTransform.h"

namespace MyEngine {

	/// <summary>
	/// Defines a GameObject with a 2D Area controlled by a RectTransform
	/// </summary>
	class MYENGINEAPI Area2D : public MyEngine::GameObject
	{
	public:
		Area2D();
		~Area2D() override;

		RectTransform* rectangleTransform;
	};
}

#endif // !AREA2D_H