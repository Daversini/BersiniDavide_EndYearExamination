#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <MyEngine/Utils/ProjectExport.h>
#include <MyEngine/Utils/pch.h>

#include "MyEngine/Scene/Components/Component.h"
#include "MyEngine/Scene/Object.h"
#include "MyEngine/Scene/ITickable.h"

namespace MyEngine {

	class Component;

	/// <summary>
	/// Defines an Object with attachable Components
	/// </summary>
	class MYENGINEAPI GameObject : public MyEngine::Object, public MyEngine::ITickable
	{
		friend class Application;
	public:
		/// <summary>
		/// Game Object constructors
		/// </summary>
		/// <param name="name">Game object name</param>
		/// <param name="is_active">Game object active boolean</param>
		GameObject(const std::string name, const bool is_active = true);

		/// <summary>
		/// Game Object constructors
		/// </summary>
		/// <param name="name">Game object name</param>
		/// <param name="components">Game object components list</param>
		/// <param name="is_active">Game object active boolean</param>
		GameObject(const std::string name, const std::vector<Component*> components, const bool is_active = true);
		virtual ~GameObject() = default;

		/// <summary>
		/// Add a component to a Game object
		/// </summary>
		/// <param name="component">The component to add</param>
		void addComponent(Component* component);

		/// <summary>
		/// Remove a component from a Game object
		/// </summary>
		/// <param name="component">The component to remove</param>
		void removeComponent(Component* component);

		/// <summary>
		/// Get the first component of a given type from the Game object attached components
		/// </summary>
		/// <typeparam name="T">The component to get</typeparam>
		/// <typeparam name="Components">Component class</typeparam>
		/// <returns></returns>
		template<class T, class = Component>  T* getComponent()const
		{
			if (components.size() == 0) return nullptr;

			for (Component* item : components)
			{
				const auto val = dynamic_cast<T*>(item);
				if (!val) continue;

				return val;
			}
			return nullptr;
		}

		/// <summary>
		/// Get all components in a Game object
		/// </summary>
		/// <typeparam name="T">All component types</typeparam>
		/// <returns></returns>
		template<class T> std::vector<T*> getComponents()const
		{
			std::vector<T*> result;

			if (components.size() == 0) return result;

			for each (Component* component in this->components)
			{
				const auto val = dynamic_cast<T*>(component);
				if (!val) continue;

				result.push_back(val);
			}
			return result;
		}

	protected:
		// Inherited via ITickable
		virtual void onFixedUpdate(const float deltaTime) override;
		virtual void onUpdate(const float deltaTime) override;

	private:
		std::vector<Component*> components;
	};
}

#endif // !GAMEOBJECT_H