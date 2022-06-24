#ifndef COMPONENT_H
#define COMPONENT_H

#include "MyEngine/Scene/Object.h"
#include "MyEngine/Scene/ITickable.h"

namespace MyEngine {

	class Component : public MyEngine::Object, public MyEngine::ITickable
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

		[[nodiscard]] GameObject* get_owner()const { return owner; }

	protected:
		// Inherited via ITickable
		virtual void on_update(const float deltaTime) override;
		virtual void on_fixed_update(const float deltaTime) override;

	private:
		GameObject* owner = nullptr;
	};
}

#endif // !COMPONENT_H