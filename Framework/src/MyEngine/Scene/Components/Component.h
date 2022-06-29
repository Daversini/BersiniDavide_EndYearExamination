#ifndef COMPONENT_H
#define COMPONENT_H

#include <MyEngine/Utils/ProjectExport.h>

#include "MyEngine/Scene/Object.h"
#include "MyEngine/Scene/ITickable.h"

namespace MyEngine {

	/// <summary>
	/// Defines a generic Component as an attachable Object to a GameObject
	/// </summary>
	class MYENGINEAPI Component : public MyEngine::Object, public MyEngine::ITickable
	{
		friend class GameObject;
	public:
		/// <summary>
		/// Component constructor
		/// </summary>
		/// <param name="name">Component name</param>
		/// <param name="is_active">Component active boolean</param>
		Component(const std::string name, const bool is_active = true) : Object(name, is_active) {}
		virtual ~Component() = default;

		/// <summary>
		/// Get the owner of the component
		/// </summary>
		/// <returns>GameObject owner</returns>
		[[nodiscard]] GameObject* getOwner()const { return owner; }

	protected:
		// Inherited via ITickable
		virtual void onUpdate(const float deltaTime) override;
		virtual void onFixedUpdate(const float deltaTime) override;

	private:
		GameObject* owner = nullptr;
	};
}

#endif // !COMPONENT_H