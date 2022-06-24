#include <MyEngine/Utils/pch.h>

#include "MyEngine/Scene/GameObjects/GameObject.h"

namespace MyEngine {

	GameObject::GameObject(const std::string name, const bool is_active) : Object(name, is_active)
	{
		this->name = name;
		this->is_active = is_active;
	}

	GameObject::GameObject(const std::string name, const std::vector<Component*> components, const bool is_active) : Object(name, is_active)
	{
		this->name = name;
		this->components = components;
	}

	void GameObject::add_component(Component* component)
	{
		component->owner = this;
		components.push_back(component);
	}

	void GameObject::remove_component(Component* component)
	{
		//TODO: Fix component erase
		//components.erase();
	}

	void GameObject::on_fixed_update(const float deltaTime)
	{
		for (auto item : components)
		{
			if (item->is_active && item->tick_enabled()) { item->on_fixed_update(deltaTime); }
		}
	}

	void GameObject::on_update(const float deltaTime)
	{
		for (auto item : components)
		{
			if (item->is_active && item->tick_enabled()) { item->on_update(deltaTime); }
		}
	}
}