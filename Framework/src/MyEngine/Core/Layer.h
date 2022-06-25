#ifndef LAYER_H
#define LAYER_H

#include <MyEngine/Utils/pch.h>

#include "MyEngine/Utils/ProjectExport.h"
#include "MyEngine/Scene/GameObjects/GameObject.h"

namespace MyEngine {
	
	class MYENGINEAPI Layer
	{
	public:
		Layer(const char* name = "Layer");
		virtual ~Layer() = default;

		virtual std::vector<GameObject*> onAttach() = 0;
		virtual void onDetach() {}
		virtual void onUpdate(float deltaTime) {}
		virtual void onEvent() {}

		const char* getName()const { return m_layerName; }

	protected:
		const char* m_layerName;
	};
}

#endif // !LAYER_H