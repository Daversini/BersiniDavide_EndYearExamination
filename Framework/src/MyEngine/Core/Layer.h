#ifndef LAYER_H
#define LAYER_H

#include "MyEngine/Utils/ProjectExport.h"

namespace MyEngine {
	
	class MYENGINEAPI Layer
	{
	public:
		Layer(const char* name = "Layer");
		virtual ~Layer() = default;

		virtual void onAttach() {}
		virtual void onDetach() {}
		virtual void onUpdate(float deltaTime) {}
		virtual void onEvent() {}

		const char* getName()const { return m_layerName; }

	protected:
		const char* m_layerName;
	};
}

#endif // !LAYER_H