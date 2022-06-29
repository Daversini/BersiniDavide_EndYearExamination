#ifndef LAYER_H
#define LAYER_H

#include <MyEngine/Utils/pch.h>

#include "MyEngine/Utils/ProjectExport.h"
#include "MyEngine/Scene/GameObjects/GameObject.h"

namespace MyEngine {
	
	/// <summary>
	/// Defines a Layer over an Application
	/// </summary>
	class MYENGINEAPI Layer
	{
	public:
		/// <summary>
		/// Layer constructor
		/// </summary>
		/// <param name="name">Layer name</param>
		Layer(const char* name = "Layer");
		virtual ~Layer() = default;

		/// <summary>
		/// Called on application initialization
		/// </summary>
		/// <returns>Vector of GameObjects</returns>
		virtual std::vector<GameObject*> onAttach() = 0;

		/// <summary>
		/// Called on application quit
		/// </summary>
		virtual void onDetach() {}

		/// <summary>
		/// Called every frame
		/// </summary>
		/// <param name="deltaTime">elapsed time between current and last time</param>
		virtual void onUpdate(const float deltaTime) {}

		/// <summary>
		/// Called on each Event
		/// </summary>
		virtual void onEvent() {}

		/// <summary>
		/// Get Layer name
		/// </summary>
		/// <returns>Layer name</returns>
		const char* getName()const { return m_layerName; }

	protected:
		const char* m_layerName;
	};
}

#endif // !LAYER_H